#pragma once
#include <vector>
#include "librador.h"
#include "algorithm"
class OSCControl;

class OscData
{
public:
	OscData(int channel)
	    : channel(channel)
	{}

	std::vector<double>* GetData(bool paused)
	{
		librador_set_oscilloscope_gain(16);
		if (!paused)
		{
			data = librador_get_analog_data(
			    channel, time_window, sample_rate_hz, delay_s, filter_mode);
		}
		return data;
	}
	std::vector<double> GetTime(double plot_min,bool paused)
	{
		double time_step = time_window / data->size();
		std::vector<double> time(data->size());
		if (!paused)
		{
			time_start = plot_min;
		}
		auto& local_time_start = time_start;
		std::generate(time.begin(), time.end(),
		    [n = 0, &time_step, &local_time_start]() mutable
		    { return n++ * time_step + local_time_start; });
		return time;
	}
	void SetTimeWindow(double t,bool paused)
	{
		if (!paused)
		{
			time_window = t;
		}
	}

private:
	double time_window=0;
	double time_start=0;
	std::vector<double> time = {};
	std::vector<double>* data = {};
	OSCControl* osc_control;
	int channel;
	double sample_rate_hz = 375000;
	int filter_mode = 0;
	double delay_s = 0;
};


