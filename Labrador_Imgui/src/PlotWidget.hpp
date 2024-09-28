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
		if (osc_control->AutofitNext)
		{
			ImPlot::SetNextAxesToFit();
			osc_control->AutofitNext = false;
		}
		ImPlot::SetNextAxesLimits(init_time_range_lower, init_time_range_upper,
		    init_voltage_range_lower, init_voltage_range_upper, ImPlotCond_Once);
		if (ImPlot::BeginPlot(
		        "##Oscilloscopes", plot_size, ImPlotFlags_NoFrame | ImPlotFlags_NoLegend))
		{
			ImPlot::SetupAxes("", "", ImPlotAxisFlags_NoLabel, ImPlotAxisFlags_NoLabel);
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

		constants::Channel trigger_channel = maps::ComboItemToChannelTriggerPair
		                                         .at(osc_control->TriggerTypeComboCurrentItem)
		                                         .channel;
		constants::TriggerType trigger_type
		    = maps::ComboItemToChannelTriggerPair
		          .at(osc_control->TriggerTypeComboCurrentItem)
		          .trigger_type;
		double trigger_time = 0;
		if (trigger_channel == constants::Channel::OSC1)
		{
			trigger_time = OSC1Data.GetTriggerTime(osc_control->Trigger, trigger_type,
			    osc_control->TriggerLevel.getValue(), osc_control->TriggerHysteresis);
		}
		if (trigger_channel == constants::Channel::OSC2)
		{
			trigger_time = OSC2Data.GetTriggerTime(osc_control->Trigger, trigger_type,
			    osc_control->TriggerLevel.getValue(), osc_control->TriggerHysteresis);
		}
		OSC1Data.SetTriggerTime(trigger_time);
		OSC2Data.SetTriggerTime(trigger_time);
		OSC1Data.SetData();
		OSC2Data.SetData();
		OSC1Data.SetRawData();
		OSC2Data.SetRawData();
		OSC1Data.ApplyFFT();
		OSC2Data.ApplyFFT();
		AutoSetOscGain();
		if (osc_control->AutoTriggerLevel)
		{
			AutoSetTriggerLevel(trigger_channel, trigger_type, &osc_control->TriggerLevel,
			    &osc_control->TriggerHysteresis);
		}
	}
	void AutoSetTriggerLevel(constants::Channel trigger_channel,
	    constants::TriggerType trigger_type, SIValue* TriggerLevel, float* TriggerHysteresis)
	{
		double hysteresis_factor = 0.4;
		if (trigger_channel == constants::Channel::OSC1)
		{
			TriggerLevel->setLevel(OSC1Data.GetDCComponent());
		}
		if (trigger_channel == constants::Channel::OSC2)
		{
			TriggerLevel->setLevel(OSC2Data.GetDCComponent());
		}
		if (trigger_type == constants::TriggerType::RISING_EDGE)
		{
			*TriggerHysteresis
			    = hysteresis_factor * std::abs((TriggerLevel->getValue() - OSC1Data.GetDataMin()));
		}
		if (trigger_type == constants::TriggerType::FALLING_EDGE)
		{
			*TriggerHysteresis
			    = hysteresis_factor * std::abs((OSC1Data.GetDataMax() - TriggerLevel->getValue()));
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
	double init_voltage_range_lower = 0;
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