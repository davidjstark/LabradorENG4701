#pragma once
#include "imgui.h"
#include "implot.h"
#include "librador.h"
#include "algorithm"
#include <chrono>

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
	PlotWidget(const char* label, ImVec2 size)
	    : label(label)
		, size(size)
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
		ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(255,255,255, 255));
		int channel = 1;
		double sample_rate_hz = 375000;
		double delay_s = 0;
		int filter_mode = 0; // 1 for a moving average filter
		librador_set_oscilloscope_gain(16);
		ImGui::Checkbox("Pause", &paused);
		if (!paused)
		{
			analog_data = librador_get_analog_data(
			    channel, time_window_s, sample_rate_hz, delay_s, filter_mode);
		}
		
		if (ImGui::Button("Autofit"))
		{
			ImPlot::SetNextAxesToFit();
		}
		ImPlot::SetNextAxesLimits(0, time_window_s, 0, 5, ImPlotCond_Once);
		if (ImPlot::BeginPlot("##Oscilloscopes",size,ImPlotFlags_NoFrame))
		{
			ImPlot::SetupAxes("", "",
				ImPlotAxisFlags_NoLabel,
				ImPlotAxisFlags_NoLabel);
			if (analog_data)
			{
				// plot drawing code here
				double time_step = time_window_s / analog_data->size();
				std::vector<double> time(analog_data->size());
				// linspace vector between 0 and time_window_s where n is number of
				// samples in current frame
				if (!paused)
				{
					time_start = ImPlot::GetPlotLimits().X.Min;
				}
				//printf("Left bound: %f\nRight bound: %f\n", time_left, time_right);
				auto& local_time_start = time_start;
				std::generate(time.begin(), time.end(),
				    [n = 0, &time_step,&local_time_start]() mutable { return n++*time_step+local_time_start; });
				ImPlot::PlotLine(
				    "##Osc 1", time.data(), analog_data->data(), analog_data->size());
				if (!paused)
				{
					time_window_s = ImPlot::GetPlotLimits().X.Size();
				}
				//printf("Time Window: %f\n", time_window_s);
			}
			ImPlot::EndPlot();
		}
		ImGui::PopStyleColor();
	}


protected:
	const char* label;
	ImVec2 size;
	std::vector<double>* analog_data = {};
	bool paused = false;
	double time_window_s = 0.03;
	double time_start = 0;
};