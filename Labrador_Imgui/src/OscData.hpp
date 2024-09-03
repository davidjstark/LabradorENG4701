#pragma once
#include <vector>
#include "librador.h"
#include <algorithm>
#include <chrono>
class OSCControl;

class OscData
{
public:
	OscData(int channel)
	    : channel(channel)
	{}
	void SetRawData()
	{
		if (!paused)
		{
			double sample_rate_hz = CalculateSampleRate();
			std::vector<double>* raw_data_ptr = librador_get_analog_data(channel,
			    time_window + trigger_timeout, sample_rate_hz, delay_s, filter_mode);
			if (raw_data_ptr)
			{
				raw_data = *raw_data_ptr;
				std::reverse(raw_data.begin(), raw_data.end());
			}
			else
			{
				raw_data = {};
			}
		}
	}
	std::vector<double> GetData()
	{
		if (!paused)
		{
			double sample_rate_hz = CalculateSampleRate();
			/*int stride = max_sample_rate / sample_rate_hz;
			data = {};
			double ul = (trigger_time + time_window) * max_sample_rate < raw_data.size()
			    ? (trigger_time + time_window) * max_sample_rate
			    : raw_data.size();
			for (int i = trigger_time * max_sample_rate; i < ul; i += stride)
			{
				data.push_back(raw_data[i]);
			}*/
			data = std::vector<double>(
			    raw_data.begin() + trigger_time * sample_rate_hz, raw_data.begin()+(trigger_time+time_window)*sample_rate_hz);
		}
		return data;
	}
	std::vector<double> GetTime(double plot_min)
	{
		double time_step = time_window / data.size();
		std::vector<double> time(data.size());
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
	void SetTimeWindow(double t)
	{
		if (!paused)
		{
			time_window = t;
		}
	}
	double GetTriggerTime(bool trigger,
	    constants::TriggerType trigger_type,
	    double trigger_level, double trigger_hysteresis)
	{
		if (!paused)
		{
			double sample_rate_hz = CalculateSampleRate();
			std::vector<double> temp_data = raw_data;
			if (trigger && time_window > 0)
			{
				switch (trigger_type)
				{
				case constants::TriggerType::RISING_EDGE:
				{
					double hysteresis_level = trigger_level - trigger_hysteresis;
					bool hysteresis_set = false;
					for (int i = 0; i < trigger_timeout * sample_rate_hz; i++)
					{
						if (temp_data[i] < hysteresis_level
						    && temp_data[i + 1] > hysteresis_level)
						{
							hysteresis_set = true;
						}
						if (hysteresis_set && temp_data[i] > trigger_level)
						{
							return i / sample_rate_hz; // returns the time in seconds
							                           // after the beginning of the
							                           // signal of the ith element
						}
					}
					break;
				}
				case constants::TriggerType::FALLING_EDGE:
				{
					double hysteresis_level = trigger_level + trigger_hysteresis;
					bool hysteresis_set = false;
					for (int i = 0; i < trigger_timeout * sample_rate_hz; i++)
					{
						if (temp_data[i] > hysteresis_level
						    && temp_data[i + 1] < hysteresis_level)
						{
							hysteresis_set = true;
						}
						if (hysteresis_set && temp_data[i] < trigger_level)
						{
							return i / sample_rate_hz; // returns the time in seconds
							                           // after the beginning of the
							                           // signal of the ith element
						}
					}
					break;
				}
				default:
				{
					return 0; // trigger immediately
				}
				}
				return trigger_timeout;
			}
			else
			{
				return 0;
			}
		}
		return 0;
	}
	void SetTriggerTime(double trigger_time)
	{
		if (!paused)
		{
			this->trigger_time = trigger_time;
		}
	}
	void SetTriggerTimeout(double trigger_timeout)
	{
		this->trigger_timeout = trigger_timeout;
	}
	void SetPaused(bool paused)
	{
		this->paused = paused;
	}

private:
	double time_window = 0;
	double time_start = 0;
	std::vector<double> time = {};
	std::vector<double> data = {};
	std::vector<double> raw_data = {};
	int channel;
	int filter_mode = 0;
	double delay_s = 0;
	double trigger_timeout = 0.02; // seconds
	double trigger_time = 0; // seconds
	int max_plot_samples = 2048;
	double max_sample_rate = 375000;
	// osc control parameters
	bool paused = false;
	double CalculateSampleRate()
	{
		double sample_rate = max_plot_samples / time_window;
		for (auto i = constants::DIVISORS_375000.rbegin();
		     i != constants::DIVISORS_375000.rend(); ++i)
		{
			int divisor = *i;
			if (sample_rate > divisor)
			{
				return divisor;
			}
		}
		return 1;
	}
};


