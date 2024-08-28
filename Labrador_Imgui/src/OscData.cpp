#pragma once
#include "OscData.h"
#include "OSCControl.hpp"


std::vector<double>* OscData::GetData()
{
	librador_set_oscilloscope_gain(16);
	if (!osc_control->Paused)
	{
		data = librador_get_analog_data(
		    channel, time_window, sample_rate_hz, delay_s, filter_mode);
	}
	return data;
}
std::vector<double> OscData::GetTime(double plot_min)
{
	double time_step = time_window / data->size();
	std::vector<double> time(data->size());
	if (!osc_control->Paused)
	{
		time_start = plot_min;
	}
	auto& local_time_start = time_start;
	std::generate(time.begin(), time.end(),
	    [n = 0, &time_step, &local_time_start]() mutable
	    { return n++ * time_step + local_time_start; });
	return time;
}
void OscData::SetTimeWindow(double t)
{
	if (!osc_control->Paused)
	{
		time_window = t;
	}
}