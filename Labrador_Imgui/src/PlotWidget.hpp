#pragma once
#include "imgui.h"
#include "implot.h"
#include "librador.h"
#include "algorithm"
#include <chrono>
#include "OSCControl.hpp"


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
	PlotWidget(const char* label, ImVec2 size,OSCControl* OSC1,OSCControl* OSC2)
	    : label(label)
		, size(size)
	    , OSC1(OSC1)
	    , OSC2(OSC2)
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
		std::vector<double>* analog_data_osc1 = OSC1->Data.GetData();
		std::vector<double>* analog_data_osc2 = OSC2->Data.GetData();
		if (OSC1->AutofitNext)
		{
			ImPlot::SetNextAxesToFit();
			OSC1->AutofitNext = false;
		}
		if (OSC2->AutofitNext)
		{
			ImPlot::SetNextAxesToFit();
			OSC2->AutofitNext = false;
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
				    = OSC1->Data.GetTime(ImPlot::GetPlotLimits().X.Min);
				ImPlot::SetNextLineStyle(ImColor(OSC1->GetAccentColour()).Value);
				if (OSC1->DisplayCheck)
				{
					ImPlot::PlotLine("##Osc 1", time_osc1.data(),
					    analog_data_osc1->data(), analog_data_osc1->size());
				}
				OSC1->Data.SetTimeWindow(ImPlot::GetPlotLimits().X.Size());
			}
			if (analog_data_osc2)
			{
				std::vector<double> time_osc2
				    = OSC2->Data.GetTime(ImPlot::GetPlotLimits().X.Min);
				ImPlot::SetNextLineStyle(ImColor(OSC2->GetAccentColour()).Value);
				if (OSC2->DisplayCheck)
				{
					ImPlot::PlotLine("##Osc 2", time_osc2.data(),
					    analog_data_osc2->data(), analog_data_osc2->size());
				}
				OSC2->Data.SetTimeWindow(ImPlot::GetPlotLimits().X.Size());
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
	OSCControl* OSC1;
	OSCControl* OSC2;
};