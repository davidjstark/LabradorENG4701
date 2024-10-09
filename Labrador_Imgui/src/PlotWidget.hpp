#pragma once
#include "imgui.h"
#include "implot.h"
#include "librador.h"
#include "algorithm"
#include <chrono>
#include "OSCControl.hpp"
#include "OscData.hpp"
#include "fftw3.h"
#include "Cursor.hpp"
#include "nfd.h"
#include <fstream>
#include <iostream>
#include <float.h>

/// <summary>
/// Abstract class that draws child that can be populated by a control widget
/// </summary>
class PlotWidget
{
public:
	int currentLabOscGain = 4;
	double time_of_last_gain_update = 0;

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="label">Name of controller</param>
	/// <param name="size">Child window size</param>
	PlotWidget(const char* label, ImVec2 size, OSCControl* osc_control)
	    : label(label)
	    , size(size)
	    , osc_control(osc_control)
	{
		librador_set_oscilloscope_gain(1<<currentLabOscGain);
	}

	/// <summary>
	/// Update size of child window
	/// </summary>
	/// <param name="new_size">New size</param>
	void setSize(ImVec2 new_size)
	{
		size = new_size;
	}

	/// <summary>
	/// Generic function to render plot widget with correct style
	/// </summary>
	void Render()
	{
		// Show cursor deltas if they are both active
		bool show_cursor_props = (osc_control->Cursor1toggle && osc_control->Cursor2toggle);
		// Show text underneath if cursors or signal properties activated
		bool text_window = show_cursor_props || osc_control->SignalPropertiesToggle;
		ImVec2 region_size = ImGui::GetContentRegionAvail();
		float row_height = ImGui::GetFrameHeight();
		ImVec2 plot_size
		    = ImVec2(region_size.x, region_size.y - (text_window ? 3 * row_height : 0));

		ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(255, 255, 255, 255));
		UpdateOscData();
		std::vector<double> analog_data_osc1 = OSC1Data.GetData();
		std::vector<double> analog_data_osc2 = OSC2Data.GetData();
		ImPlot::SetNextAxesLimits(init_time_range_lower, init_time_range_upper,
		    init_voltage_range_lower, init_voltage_range_upper, ImPlotCond_Once);
		if (ImPlot::BeginPlot("##Oscilloscopes", plot_size, ImPlotFlags_NoFrame | ImPlotFlags_NoLegend))
		{
			ImPlot::SetupAxes("", "", ImPlotAxisFlags_NoLabel, ImPlotAxisFlags_NoLabel);
			// Autofit so that 3 periods occur in a time window
			// If there are 2 oscs visible use the one with the larger period
			// If none are visible, reset to default
			if (osc_control->AutofitX) 
			{	
				double T_osc1 = OSC1Data.GetPeriod();
				double T_osc2 = OSC2Data.GetPeriod();
				double T = 0;
				if (osc_control->DisplayCheckOSC1 && !osc_control->DisplayCheckOSC2)
				{
					T = T_osc1;
					T *= 3;
				}
				else if (osc_control->DisplayCheckOSC2 && !osc_control->DisplayCheckOSC1)
				{
					T = T_osc2;
					T *= 3;
				}
				else if (osc_control->DisplayCheckOSC2 && osc_control->DisplayCheckOSC1)
				{
					T = T_osc1 > T_osc2 ? T_osc1 : T_osc2;
					T *= 3;
				}
				else if (!osc_control->DisplayCheckOSC2 && !osc_control->DisplayCheckOSC1)
				{
					T = init_time_range_upper;
				}
				ImPlot::SetupAxisLimits(ImAxis_X1,init_time_range_lower,T,ImPlotCond_Always);
			}
			if (osc_control->AutofitY) // Autofits so that data is centered and takes up 1/3 of the screen (this can be written way cleaner)
			{
				double osc1_max;
				double osc2_max;
				double osc1_min;
				double osc2_min;
				if (osc_control->DisplayCheckOSC1) // set to actual max and min only if the oscilloscope channel is visible
				{
					osc1_max = OSC1Data.GetDataMax();
					osc1_min = OSC1Data.GetDataMin();
				}
				else // else set to opposite extremes so that it always loses on comparison
				{
					osc1_max = DBL_MIN;
					osc1_min = DBL_MAX;
				}
				if (osc_control->DisplayCheckOSC2) // set to actual max and min only if the oscilloscope channel is visible
				{
					osc2_max = OSC2Data.GetDataMax();
					osc2_min = OSC2Data.GetDataMin();
				}
				else // else set to opposite extremes so that it always loses on comparison
				{
					osc2_max = DBL_MIN;
					osc2_min = DBL_MAX;
				}
				double osc_max = osc1_max > osc2_max ? osc1_max : osc2_max;
				double osc_min = osc1_min < osc2_min ? osc1_min : osc2_min;
				double osc_range = osc_max - osc_min;
				if (osc_control->DisplayCheckOSC1 || osc_control->DisplayCheckOSC2) // only autofit if there is visible data
				{
					ImPlot::SetupAxisLimits(ImAxis_Y1, osc_min - osc_range, osc_max + osc_range,ImPlotCond_Always);
				}
				else // else reset to default (start-up) range
				{
					ImPlot::SetupAxisLimits(ImAxis_Y1, init_voltage_range_lower,init_voltage_range_upper,ImPlotCond_Always);
				}
				osc_control->AutofitY = false;
			}
			ImPlot::SetupAxisZoomConstraints(ImAxis_X1,0,60);// ensure plot cannot be expanded larger than the size of the buffer
			// Plot oscilloscope 1 signal
			std::vector<double> time_osc1 = OSC1Data.GetTime();
			ImPlot::SetNextLineStyle(osc_control->OSC1Colour.Value);
			if (osc_control->DisplayCheckOSC1)
			{
				ImPlot::PlotLine("##Osc 1", time_osc1.data(), analog_data_osc1.data(),
				    analog_data_osc1.size());
			}
			OSC1Data.SetTime(ImPlot::GetPlotLimits().X.Size(), ImPlot::GetPlotLimits().X.Min);
			// Plot Oscilloscope 2 Signal
			std::vector<double> time_osc2 = OSC2Data.GetTime();
			ImPlot::SetNextLineStyle(osc_control->OSC2Colour.Value);
			if (osc_control->DisplayCheckOSC2)
			{
				ImPlot::PlotLine("##Osc 2", time_osc2.data(), analog_data_osc2.data(),
				    analog_data_osc2.size());
			}
			OSC2Data.SetTime(ImPlot::GetPlotLimits().X.Size(), ImPlot::GetPlotLimits().X.Min);
			// Plot cursor 1
			if (osc_control->Cursor1toggle)
				drawCursor(1, &cursor1_x, &cursor1_y);
			if (osc_control->Cursor2toggle)
				drawCursor(2, &cursor2_x, &cursor2_y);

			ImPlot::EndPlot();
		}
		if (show_cursor_props)
		{
			ImGui::Text(
			    "Cursor properties:    dT = %.2f s   1/dT = %.2f Hz    dV = %.2f V",
			    cursor2_x - cursor1_x, 1 / (cursor2_x - cursor1_x), cursor2_y - cursor1_y);
		}
		if (osc_control->SignalPropertiesToggle)
		{
			writeSignalProps(OSC1Data);
			writeSignalProps(OSC2Data);
		}
		ImGui::PopStyleColor();
	}

	void writeSignalProps(OscData data)
	{
		double T = data.GetPeriod();
		double Vpp = data.GetDataMax() - data.GetDataMin();

		if (T == (double)-1)
		{
			// No period found
			ImGui::Text(
			    "OSC%d Signal Properties: Vpp = %.2f V (no periodic waveform found)",
			    data.GetChannel(), Vpp);
		}
		else
		{
			// Period found - show delta T property
			ImGui::Text(
			    "OSC%d Signal Properties:  dT = %.2f ms   1/dT = %.2f Hz  Vpp = %.2f V",
			    data.GetChannel(), 1000*T, 1 / T, Vpp);
		}
	}

	void drawCursor(int id, double* cx, double* cy)
	{
		if (*cx == -1000 && *cy == -1000)
		{
			// Initial cursor centered
			ImPlotRect lim = ImPlot::GetPlotLimits();
			ImPlotPoint max = lim.Max();
			ImPlotPoint min = lim.Min();
			*cx = (max.x + min.x) / 2;
			*cy = (max.y + min.y) / 2;
		}

		ImPlot::DragPoint(id, cx, cy, ImVec4(1, 1, 1, 1), 8.0f);
		char cursor_label[20];
		std::string label = std::to_string(id) + ":";
		// Label is in (ms, V) - TODO: change axis to ms instead of seconds
		sprintf(cursor_label, (label + "(%.2f, %.2f)").c_str(), *cx, *cy);
		ImPlot::PlotText(cursor_label, *cx, *cy, ImVec2(50, -12));
		ImPlot::SetNextLineStyle(ImVec4(1, 1, 1, 0.8));
		ImPlot::PlotInfLines((label + "vert").c_str(), cx, 1, ImPlotInfLinesFlags_None);
		ImPlot::SetNextLineStyle(ImVec4(1, 1, 1, 0.8));
		ImPlot::PlotInfLines((label + "vert").c_str(), cy, 1, ImPlotInfLinesFlags_Horizontal);
	}

	void UpdateOscData()
	{
		OSC1Data.SetPaused(osc_control->Paused);
		OSC2Data.SetPaused(osc_control->Paused);
		OSC1Data.SetExtendedData();
		OSC2Data.SetExtendedData();
		double trigger_time_osc1 = OSC1Data.GetTriggerTime(osc_control->Trigger1, static_cast<constants::TriggerType>(osc_control->Trigger1TypeComboCurrentItem),
			    osc_control->Trigger1Level.getValue(), osc_control->Trigger1Hysteresis);
		double trigger_time_osc2 = OSC2Data.GetTriggerTime(osc_control->Trigger2, static_cast<constants::TriggerType>(osc_control->Trigger2TypeComboCurrentItem),
			    osc_control->Trigger2Level.getValue(), osc_control->Trigger2Hysteresis);
		OSC1Data.SetTriggerTime(trigger_time_osc1);
		OSC2Data.SetTriggerTime(trigger_time_osc2);
		OSC1Data.SetData();
		OSC2Data.SetData();
		OSC1Data.SetRawData();
		OSC2Data.SetRawData();
		OSC1Data.ApplyFFT();
		OSC2Data.ApplyFFT();
		AutoSetOscGain();
		if (osc_control->AutoTrigger1Level)
		{
			AutoSetTriggerLevel(constants::Channel::OSC1,
			    static_cast<constants::TriggerType>(osc_control->Trigger1TypeComboCurrentItem),
			    &osc_control->Trigger1Level,
			    &osc_control->Trigger1Hysteresis);
		}
		if (osc_control->AutoTrigger2Level)
		{
			AutoSetTriggerLevel(constants::Channel::OSC2,
			    static_cast<constants::TriggerType>(osc_control->Trigger2TypeComboCurrentItem),
			    &osc_control->Trigger2Level,
			    &osc_control->Trigger2Hysteresis);
		}
		HandleWrites();
	}
	void HandleWrites()
	{
		bool* OSCClipboardCopyNext_p = NULL; // pointer to the bool for OSC which needs copying to clipboard (only one wll need copying at a time, prevents rewriting of code)
		bool* OSCClipboardCopied_p = NULL; // pointer to a status for whether copying was successful
		nfdchar_t** OSCWritePath_p = NULL; // pointer to the OSCWritePath which needs writing to file (one at a time as well)
		OscData* OSCData_p = NULL;

		// set up pointers based what we are doing to which osc
		if (osc_control->OSC1ClipboardCopyNext) // if we are copying osc1 to clipboard
		{
			OSCClipboardCopyNext_p = &osc_control->OSC1ClipboardCopyNext; // sets the pointer to the clipboard bool
			OSCClipboardCopied_p = &osc_control->OSC1ClipboardCopied; // sets the pointer to the clipboard success
			OSCData_p = &OSC1Data; // sets the pointer to the OSC we are copying
		}
		if (osc_control->OSC2ClipboardCopyNext) // if we are copying osc2 to clipboard
		{
			OSCClipboardCopyNext_p = &osc_control->OSC2ClipboardCopyNext; // sets the pointer to the clipboard bool
			OSCClipboardCopied_p = &osc_control->OSC2ClipboardCopied; // sets the pointer to the clipboard success
			OSCData_p = &OSC1Data; // sets the pointer to the OSC we are copying
		}
		if (osc_control->OSC1WritePath != NULL) // if we are writing osc1 to csv file
		{
			OSCWritePath_p = &osc_control->OSC1WritePath; // sets the pointer to the write path var
			OSCData_p = &OSC1Data; // sets the pointer to the OSC we are copying
		}
		if (osc_control->OSC2WritePath != NULL) // if we are writing osc2 to csv file
		{
			OSCWritePath_p = &osc_control->OSC2WritePath; // sets the pointer to the write path var
			OSCData_p = &OSC1Data; // sets the pointer to the OSC we are copying
		}

		// once pointers are set up, perform desired task on desired osc
		if (OSCClipboardCopyNext_p != NULL) // if we are copying to clipboard
		{
			// get OSCData signal and time vectors
			std::vector<double> data = OSCData_p->GetData();
			std::vector<double> time = OSCData_p->GetTime();
			// write osc to string
			std::string clipboard_str = ""; // define empty string which we will add to
			clipboard_str += "Time\tVoltage\n"; // header
			if (data.size() != 0)
			{
				for (int i = 0; i < data.size(); i++)
				{
					std::string time_str = std::to_string(time[i]); // convert time point to string
					std::string data_str = std::to_string(data[i]); // convert data point to string
					clipboard_str += time_str + "\t" + data_str + "\n"; // write to the clipboard string
				}
				ImGui::SetClipboardText(clipboard_str.c_str());
				*OSCClipboardCopied_p = true;
			}
			*OSCClipboardCopyNext_p = false; // reset state so we don't repeat on next render
		}
		if (OSCWritePath_p != NULL) // if we are writing to a csv file
		{
			// get OSCData signal and time vectors
			std::vector<double> data = OSCData_p->GetData();
			std::vector<double> time = OSCData_p->GetTime();
			// write osc to string
			std::string file_str = ""; // define empty string which we will add to
			file_str += "Time,Voltage\n"; // header
			if (data.size() != 0)
			{
				for (int i = 0; i < data.size(); i++)
				{
					std::string time_str = std::to_string(time[i]); // convert time point to string
					std::string data_str = std::to_string(data[i]); // convert data point to string
					file_str += time_str + "," + data_str + "\n"; // write to the clipboard string
				}
				std::ofstream file;
				// Automatically add the file extension to the end of the directory string if it isn't already there
				// NOTE: This is not an ideal implementation. It doesn't behave entirely how file saving should work in windows
				// For example, usually if you overwriting a file, it will warn you that you are overwriting a file
				// But because we add the extension afterwards, it doesn't do this
				// There may be a workaround, perhaps by rewriting some of nfd source code to fit our needs
				// or perhaps we may just need to use a windows library and then create separate code for handling file saving 
				// on macOS and linux.
				size_t path_length = strlen(*OSCWritePath_p);
				std::string extension_str = "." + std::string(osc_control->FileExtension);
				if (path_length > extension_str.length())
				{
					// get last n characters (where n is the length of the extension)
					int extension_start_index = path_length - extension_str.length();
					if (std::strncmp(*OSCWritePath_p + extension_start_index, extension_str.c_str(), extension_str.length()) != 0) // checks if file path string does not end in the file extension
					{
						// append the file extension since it is not there already
						std::string file_path_str = std::string(*OSCWritePath_p); // convert file path to std::string
						file_path_str += extension_str; // append the extension
						delete[] *OSCWritePath_p; // deallocate the old OSCWritePath memory as we are about to reallocate it
						*OSCWritePath_p = new char[file_path_str.length() + 1]; // allocates the memory for OSCWritePath
						std::strcpy(*OSCWritePath_p, file_path_str.c_str()); // copies the string to the OSCWritePath
					}
				}
				file.open(*OSCWritePath_p);
				file << file_str.c_str();
				file.close();
			}
			*OSCWritePath_p = NULL; // reset state so we don't repeat on next render
		}
	}
	void AutoSetTriggerLevel(constants::Channel trigger_channel,
	    constants::TriggerType trigger_type, SIValue* TriggerLevel, float* TriggerHysteresis)
	{
		double hysteresis_factor = 0.4;
		OscData* OSCData_ptr;
		if (trigger_channel == constants::Channel::OSC1)
		{
			OSCData_ptr = &OSC1Data;
		}
		if (trigger_channel == constants::Channel::OSC2)
		{
			OSCData_ptr = &OSC2Data;
		}
		TriggerLevel->setLevel(OSCData_ptr->GetDCComponent());
		if (trigger_type == constants::TriggerType::RISING_EDGE)
		{
			*TriggerHysteresis
			    = hysteresis_factor * std::abs((TriggerLevel->getValue() - OSCData_ptr->GetDataMin()));
		}
		if (trigger_type == constants::TriggerType::FALLING_EDGE)
		{
			*TriggerHysteresis
			    = hysteresis_factor * std::abs((OSCData_ptr->GetDataMax() - TriggerLevel->getValue()));
		}
	}

	

	void AutoSetOscGain()
	{
		int frame = ImGui::GetFrameCount();
		if (frame - last_update_frame < 5)
		{
			return;
		}

		int gainUpdate1 = 1;
		int gainUpdate2 = 1;

		// Check whether gain needs to increase or decrease
		// gainUpdate = -1 : OSC Data is out of range provided by current gain (clipping) - zoom out
		// gainUpdate =  0 : OSC Data is in range provided by gain - no change
		// gainUpdate = +1 : OSC Data is in range provided by larger gain - zoom in
		if (osc_control->DisplayCheckOSC1)
		{
			gainUpdate1 = GetChangeToGain(OSC1Data.GetMiniBuffer());
		}
		
		if (osc_control->DisplayCheckOSC2)
		{
			gainUpdate2 = GetChangeToGain(OSC2Data.GetMiniBuffer());
		}
		if (osc_control->DisplayCheckOSC1 == false && osc_control->DisplayCheckOSC2 == false)
		{
			gainUpdate1 = 0;
			gainUpdate2 = 0;
		}

		bool changed = false;
		// Zoom out if either OSC data is clipping
		if (gainUpdate1 == -1 || gainUpdate2 == -1)
		{
			changed = true;
			currentLabOscGain--;
		}
		// Zoom in if both OSC datas are within threshold
		else if (gainUpdate1 == 1 && gainUpdate2 == 1)
		{
			changed = true;
			currentLabOscGain++;
		}

		if (changed)
		{
			librador_set_oscilloscope_gain(1 << currentLabOscGain);
			last_update_frame = frame;
			printf("Frame: %03d, gain: %02d\n", frame, 1 << currentLabOscGain);
		}
	}

private:
	const double adc_center = 3.3 / 2;
	const double gain_scale = 0.35;
	const double threshold_samples_frac = 0.1;
	
	int GetChangeToGain(
	    std::vector<double> osc_data)
	{
		// Check whether gain needs to decrease (zoom out, prevent clipping of larger waveforms)
		if (currentLabOscGain > 1)
		{
			const double offset = (1 << (6 - currentLabOscGain)) * gain_scale;
			const double max_thresh = adc_center + offset;
			const double min_thresh = adc_center - offset;

			// counts number of values which we identify to potentially be clipping
			int max_count = std::count_if(osc_data.begin(), osc_data.end(),
			    [max_thresh](double x) { return x > max_thresh; });
			int min_count = std::count_if(osc_data.begin(), osc_data.end(),
			    [min_thresh](double x) { return x < min_thresh; });
			if (max_count > threshold_samples_frac * osc_data.size()
			    || min_count > threshold_samples_frac * osc_data.size())
			{
				return -1; // decrement gain
			}
		}
		// Check if gain needs to increase (zoom in, for smaller waveforms)
		if (currentLabOscGain < 6)
		{
			const double offset = (1 << (5 - currentLabOscGain)) * gain_scale;
			const double max_thresh = adc_center + offset;
			const double min_thresh = adc_center - offset;
			const double grace = 0.2 * offset; // only apply to min game to prevent repetitive switching

			// counts number of values outside of the thresholds of the smaller gain
			int max_count = std::count_if(osc_data.begin(), osc_data.end(),
			    [max_thresh, grace](double x) { return x > max_thresh - grace; });
			int min_count = std::count_if(osc_data.begin(), osc_data.end(),
			    [min_thresh, grace](double x) { return x < min_thresh + grace; });
			if (max_count < threshold_samples_frac * osc_data.size()
			    && min_count < threshold_samples_frac * osc_data.size())
			{
				return 1; // increment gain
			}
		}
		
		return 0; // no change

	}

protected:
	const char* label;
	ImVec2 size;
	bool paused = false;
	double init_time_range_lower = 0;
	double init_time_range_upper = 0.03;
	double init_voltage_range_lower = -1.0;
	double init_voltage_range_upper = 5.0;
	OSCControl* osc_control;
	OscData OSC1Data = OscData(1);
	OscData OSC2Data = OscData(2);
	double cursor1_x = -1000;
	double cursor1_y = -1000;
	double cursor2_x = -1000;
	double cursor2_y = -1000;
	int last_update_frame = 10;

	
};