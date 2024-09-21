#pragma once
#include "imgui.h"
#include "implot.h"
#include "librador.h"
#include "algorithm"
#include <chrono>
#include "OSCControl.hpp"
#include "OscData.hpp"
#include "fftw3.h"

/// <summary>
/// Abstract class that draws child that can be populated by a control widget
/// </summary>
class PlotWidget
{
public:
	int currentLabOscGain = 16;


	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="label">Name of controller</param>
	/// <param name="size">Child window size</param>
	PlotWidget(const char* label, ImVec2 size, OSCControl* osc_control)
	    : label(label)
		, size(size)
	    , osc_control(osc_control)
	{}

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
		if (ImPlot::BeginPlot("##Oscilloscopes", ImVec2(ImGui::GetContentRegionAvail().x,size.y), ImPlotFlags_NoFrame))
		{
			ImPlot::SetupAxes("", "",
			ImPlotAxisFlags_NoLabel,
			ImPlotAxisFlags_NoLabel);
			// Plot oscilloscope 1 signal
			std::vector<double> time_osc1
				= OSC1Data.GetTime();
			ImPlot::SetNextLineStyle(osc_control->OSC1Colour.Value);
			if (osc_control->DisplayCheckOSC1)
			{
				ImPlot::PlotLine("##Osc 1", time_osc1.data(),
					analog_data_osc1.data(), analog_data_osc1.size());
			}
			OSC1Data.SetTime(ImPlot::GetPlotLimits().X.Size(),ImPlot::GetPlotLimits().X.Min);
			// Plot Oscilloscope 2 Signal
			std::vector<double> time_osc2
				= OSC2Data.GetTime();
			ImPlot::SetNextLineStyle(osc_control->OSC2Colour.Value);
			if (osc_control->DisplayCheckOSC2)
			{
				ImPlot::PlotLine("##Osc 2", time_osc2.data(),
					analog_data_osc2.data(), analog_data_osc2.size());
			}
			OSC2Data.SetTime(ImPlot::GetPlotLimits().X.Size(), ImPlot::GetPlotLimits().X.Min);
			// Plot cursor 1
			ImPlot::DragPoint(0, &cursor1_x,&cursor1_y, ImVec4(1, 1, 1, 1));
			ImPlot::EndPlot();
		}
		ImGui::PopStyleColor();
	}

	void UpdateOscData()
	{
		OSC1Data.SetPaused(osc_control->Paused);
		OSC2Data.SetPaused(osc_control->Paused);
		OSC1Data.SetExtendedData();
		OSC2Data.SetExtendedData();
		constants::Channel trigger_channel
		    = maps::ComboItemToChannelTriggerPair.at(osc_control->TriggerTypeComboCurrentItem).channel;
		constants::TriggerType trigger_type
		    = maps::ComboItemToChannelTriggerPair.at(osc_control->TriggerTypeComboCurrentItem).trigger_type;
		double trigger_time = 0;
		if (trigger_channel == constants::Channel::OSC1)
		{
			trigger_time = OSC1Data.GetTriggerTime(osc_control->Trigger, trigger_type,
			    osc_control->TriggerLevel, osc_control->TriggerHysteresis);
		}
		if (trigger_channel == constants::Channel::OSC2)
		{
			trigger_time = OSC2Data.GetTriggerTime(osc_control->Trigger, trigger_type,
			    osc_control->TriggerLevel, osc_control->TriggerHysteresis);
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
			AutoSetTriggerLevel(trigger_channel,trigger_type, &osc_control->TriggerLevel,&osc_control->TriggerHysteresis);
		}
	}
	void AutoSetTriggerLevel(constants::Channel trigger_channel,constants::TriggerType trigger_type, float* TriggerLevel,float* TriggerHysteresis)
	{
		double hysteresis_factor = 0.4;
		if (trigger_channel == constants::Channel::OSC1)
		{
			*TriggerLevel = OSC1Data.GetDCComponent();
		}
		if (trigger_channel == constants::Channel::OSC2)
		{
			*TriggerLevel = OSC2Data.GetDCComponent();
		}
		if (trigger_type == constants::TriggerType::RISING_EDGE)
		{
			*TriggerHysteresis = hysteresis_factor * std::abs((*TriggerLevel- OSC1Data.GetDataMin()));
		}
		if (trigger_type == constants::TriggerType::FALLING_EDGE)
		{
			*TriggerHysteresis = hysteresis_factor * std::abs((OSC1Data.GetDataMax() - *TriggerLevel));
		}
	}
	void AutoSetOscGain()
	{
		double adc_center = 3.3 / 2;
		double osc1_max = adc_center;
		double osc1_min = adc_center;
		double osc2_max = adc_center;
		double osc2_min = adc_center;
		double max_limits[7] = { 25.0, 13.4, 7.5, 4.5, 3.1, 2.4, 2.0 };
		double min_limits[7] = { -22.0, -10.1, -4.2, -1.3, 0.17, 0.91, 1.3 };
		double grace = 0.1;
		if (OSC1Data.GetDataSize() != 0)
		{
			std::vector<double> osc1_data = OSC1Data.GetMiniBuffer();
			osc1_max = *std::max_element(osc1_data.begin(), osc1_data.end());
			osc1_min = *std::min_element(osc1_data.begin(), osc1_data.end());
		}
		if (OSC2Data.GetDataSize() != 0)
		{
			std::vector<double> osc2_data = OSC2Data.GetMiniBuffer();
			double osc2_max = *std::max_element(osc2_data.begin(), osc2_data.end());
			double osc2_min = *std::min_element(osc2_data.begin(), osc2_data.end());
		}
		double osc_max = osc1_max > osc2_max ? osc1_max : osc2_max;
		double osc_min = osc1_min < osc2_min ? osc1_min : osc2_min;
		int min_gain = 1;
		int max_gain = 1;

		for (int i = 1; i < sizeof(max_limits) / sizeof(double); i++)
		{
			if (osc_max < max_limits[i]-grace)
			{
				max_gain = std::pow(2,i);
			}
			else
			{
				break;
			}
		}
		for (int i = 1; i < sizeof(min_limits) / sizeof(double); i++)
		{
			if (osc_min > min_limits[i] + grace)
			{
				min_gain = std::pow(2, i);
			}
			else
			{
				break;
			}
		}
		int desired_gain = max_gain < min_gain ? max_gain : min_gain;
		desired_gain = desired_gain < 1 ? 1 : desired_gain; // insure gain does not go
			                                                // lower than 1
		if (desired_gain != currentLabOscGain)
		{
			currentLabOscGain = desired_gain;
			librador_set_oscilloscope_gain(int(currentLabOscGain));
		}
		
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
	double cursor1_x = 0;
	double cursor1_y = 0;

};