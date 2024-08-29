#pragma once
#include "imgui.h"
#include "implot.h"
#include "librador.h"
#include "algorithm"
#include <chrono>
#include "OSCControl.hpp"
#include "OscData.hpp"


/// <summary>
/// Abstract class that draws child that can be populated by a control widget
/// </summary>
class PlotWidget
{
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="label">Name of controller</param>
	/// <param name="size">Child window size</param>
	PlotWidget(const char* label, ImVec2 size,OSCControl* osc_control)
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
		std::vector<double>* analog_data_osc1 = OSC1Data.GetData(osc_control->Paused);
		std::vector<double>* analog_data_osc2 = OSC2Data.GetData(osc_control->Paused);
		if (osc_control->AutofitNext)
		{
			ImPlot::SetNextAxesToFit();
			osc_control->AutofitNext = false;
		}
		ImPlot::SetNextAxesLimits(init_time_range_lower, init_time_range_upper,
		    init_voltage_range_lower, init_voltage_range_upper, ImPlotCond_Once);
		if (ImPlot::BeginPlot("##Oscilloscopes",size,ImPlotFlags_NoFrame))
		{
			ImPlot::SetupAxes("", "",
				ImPlotAxisFlags_NoLabel,
				ImPlotAxisFlags_NoLabel);
			if (analog_data_osc1)
			{
				std::vector<double> time_osc1
				    = OSC1Data.GetTime(ImPlot::GetPlotLimits().X.Min,osc_control->Paused);
				ImPlot::SetNextLineStyle(osc_control->OSC1Colour.Value);
				if (osc_control->DisplayCheckOSC1)
				{
					ImPlot::PlotLine("##Osc 1", time_osc1.data(),
					    analog_data_osc1->data(), analog_data_osc1->size());
				}
				OSC1Data.SetTimeWindow(ImPlot::GetPlotLimits().X.Size(),osc_control->Paused);
			}
			if (analog_data_osc2)
			{
				std::vector<double> time_osc2
				    = OSC2Data.GetTime(ImPlot::GetPlotLimits().X.Min, osc_control->Paused);
				ImPlot::SetNextLineStyle(osc_control->OSC2Colour.Value);
				if (osc_control->DisplayCheckOSC2)
				{
					ImPlot::PlotLine("##Osc 2", time_osc2.data(),
					    analog_data_osc2->data(), analog_data_osc2->size());
				}
				OSC2Data.SetTimeWindow(ImPlot::GetPlotLimits().X.Size(), osc_control->Paused);
			}
			ImPlot::EndPlot();
		}
		ImGui::PopStyleColor();
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
};