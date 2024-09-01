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

	std::vector<double> GetData()
	{
		if (!paused)
		{
			sample_rate_hz = CalculateSampleRate();
			std::vector<double>* temp_data_ptr = librador_get_analog_data(
				channel, time_window+trigger_timeout, sample_rate_hz, delay_s, filter_mode);
			std::vector<double> temp_data = {};
			if (temp_data_ptr)
			{
				temp_data = *temp_data_ptr;
			}
			else
			{
				return data;
			}
			std::reverse(temp_data.begin(), temp_data.end());
			if (trigger
			    && time_window > 0)
			{
				switch (trigger_type)
				{
					case constants::TriggerType::RISING_EDGE:
					{
						double hysteresis_level = trigger_level - trigger_hysteresis;
					    bool hysteresis_set = false;
					    bool timeout = true;
						for (int i = 0; i < trigger_timeout*sample_rate_hz; i++)
						{
							if (temp_data[i] < hysteresis_level &&  temp_data[i + 1] > hysteresis_level)
							{
							    hysteresis_set = true;
							}
						    if (hysteresis_set && temp_data[i] > trigger_level)
						    {
							    data = std::vector<double>(temp_data.begin() + i,
							        temp_data.begin() + i + time_window * sample_rate_hz+1);
							    hysteresis_set = false;
							    timeout = false;
							    break;
						    }
						}
						if (timeout)
						{
						    data = std::vector<double>(
						        temp_data.begin() + trigger_timeout * sample_rate_hz,
						        temp_data.end());
						}
						break;
					}
					case constants::TriggerType::FALLING_EDGE:
					{
						break;
					}
				    default:
					{
					    data = std::vector<double>(temp_data.begin(),
					        temp_data.begin() + time_window * sample_rate_hz);
					}
				}
			}
			else
			{
				data = std::vector<double>(
				    temp_data.begin(), temp_data.begin()+time_window*sample_rate_hz);
			}
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
	void SetTrigger(bool trigger,
	    constants::TriggerType trigger_type = constants::TriggerType::RISING_EDGE,
	    double trigger_level = 0, double trigger_hysteresis = 0)
	{
		this->trigger = trigger;
		this->trigger_type = trigger_type;
		this->trigger_level = trigger_level;
		this->trigger_hysteresis = trigger_hysteresis;
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
	int channel;
	double sample_rate_hz = 375000;
	int filter_mode = 0;
	double delay_s = 0;
	double trigger_timeout = 0.02; // seconds
	int max_plot_samples = 2048;
	double max_sample_rate = 375000;
	// osc control parameters
	bool paused = false;
	bool trigger = false;
	constants::TriggerType trigger_type = constants::TriggerType::RISING_EDGE;
	double trigger_level = 0;
	double trigger_hysteresis;
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


