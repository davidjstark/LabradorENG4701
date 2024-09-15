#pragma once
#include <vector>
#include "librador.h"
#include <algorithm>
#include <chrono>
#include "fftw3.h"
class OSCControl;

class OscData
{
public:
	OscData(int channel)
	    : channel(channel)
	{
		data_ft_in = (double*)fftw_malloc(sizeof(double) * ft_size);
		data_ft_out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * ft_size);
		data_ft_in_filtered = (double*)fftw_malloc(sizeof(double) * ft_size);
		data_ft_out_filtered = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * ft_size);
		plan = fftw_plan_dft_r2c_1d(ft_size, data_ft_in, data_ft_out,FFTW_ESTIMATE);
		reverse_plan = fftw_plan_dft_c2r_1d(
		    ft_size, data_ft_out_filtered, data_ft_in_filtered, FFTW_ESTIMATE);
		// init mini buffer to all 1.65 (adc_center)
		mini_buffer.resize(int(max_sample_rate * mini_buffer_length));
		std::fill(mini_buffer.begin(), mini_buffer.end(), 1.65);
	}
	void SetRawData() // sets the raw_data vector to be used for fourier analysis (frequency stuff)
	{
		if (!paused)
		{

			std::vector<double>* raw_data_ptr = librador_get_analog_data(
			    channel, ft_time_window, ft_sample_rate, delay_s, filter_mode);
			if (raw_data_ptr)
			{
				raw_data = *raw_data_ptr;
			}
			else
			{
				raw_data = {};
			}
			raw_time_step = 1 / ft_sample_rate;
			double time_step = raw_time_step;
			raw_time.resize(raw_data.size());
			std::generate(raw_time.begin(), raw_time.end(),
			    [n = 0, &time_step]() mutable
			    { return n++ * time_step; });
		}
	}
	void SetExtendedData() // sets the extended_data vector to be used for plotting, extended meaning including the trigger timeout
	{
		if (!paused)
		{
			double sample_rate_hz = CalculateSampleRate();
			std::vector<double>* extended_data_ptr = librador_get_analog_data(channel,
			    time_window + trigger_timeout, sample_rate_hz, delay_s, filter_mode);
			if (extended_data_ptr)
			{
				extended_data = *extended_data_ptr;
				std::reverse(extended_data.begin(), extended_data.end());
			}
			else
			{
				extended_data = {};
			}
		}
	}
	std::vector<double> GetData()
	{
		return data;
	}
	void SetData() // sets the data vector for plotting, this is exactly what is plotted
	{
		if (!paused)
		{
			double sample_rate_hz = CalculateSampleRate();
			if (extended_data.size() == 0)
			{
				data = {};
			}
			else
			{
				data = std::vector<double>(extended_data.begin() + trigger_time * sample_rate_hz,
				    extended_data.begin() + (trigger_time + time_window) * sample_rate_hz);
			}
			this->time_step = this->time_window / data.size();
			double time_step = time_window / data.size();
			time.resize(data.size());
			auto& local_time_start = time_start;
			std::generate(time.begin(), time.end(),
			    [n = 0, &time_step, &local_time_start]() mutable
			    { return n++ * time_step + local_time_start; });
		}
	}
	std::vector<double> GetTime()
	{
		return time;
	}
	void SetTime(double time_window,double time_start)
	{
		if (!paused)
		{
			this->time_window = time_window;
			this->time_start = time_start;

		}
		this->time_step = this->time_window / data.size();
		double time_step = this->time_step;
		std::vector<double> time(data.size());
		auto& local_time_start = this->time_start;
		std::generate(time.begin(), time.end(),
		    [n = 0, &time_step, &local_time_start]() mutable
		    { return n++ * time_step + local_time_start; });
	}
	double GetTriggerTime(bool trigger,
	    constants::TriggerType trigger_type,
	    double trigger_level, double trigger_hysteresis)
	{
		if (!paused)
		{
			double sample_rate_hz = CalculateSampleRate();
			std::vector<double> temp_data = extended_data;
			if (trigger && time_window > 0 && extended_data.size() != 0)
			{
				switch (trigger_type)
				{
				case constants::TriggerType::RISING_EDGE:
				{
					double hysteresis_level = trigger_level - trigger_hysteresis;
					trigger_time = trigger_timeout+1;
					for (int i = trigger_timeout*sample_rate_hz; i > 0; i--)
					{
						if (temp_data[i] > trigger_level
						    && temp_data[i - 1] < trigger_level)
						{
							trigger_time = i / sample_rate_hz; // time in seconds
							                           // after the beginning of the
							                           // signal of the ith element
						}
						if (trigger_time <= trigger_timeout && temp_data[i] < hysteresis_level)
						{
							return trigger_time; 
						}
					}
					break;
				}
				case constants::TriggerType::FALLING_EDGE:
				{
					double hysteresis_level = trigger_level + trigger_hysteresis;
					trigger_time = trigger_timeout + 1;
					for (int i = trigger_timeout * sample_rate_hz; i > 0; i--)
					{
						if (temp_data[i] < trigger_level && temp_data[i - 1] > trigger_level)
						{
							trigger_time = i / sample_rate_hz; // time in seconds
							                                   // after the beginning of the
							                                   // signal of the ith element
						}
						if (trigger_time <= trigger_timeout && temp_data[i] > hysteresis_level)
						{
							return trigger_time;
						}
					}
					break;
				}
				default:
				{
					return trigger_timeout; // trigger as late as possible
				}
				}
				return trigger_timeout; // trigger as late as possible
			}
			else
			{
				return trigger_timeout;
			}
		}
		return trigger_timeout;
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
	int GetDataSize()
	{
		return data.size();
	}
	double GetFrequency()
	{
		std::vector<double> ft_mag;
		ApplyFFT();
		for (int i = 0; i < ft_size; i++)
		{
			ft_mag.push_back(GetComplexMagnitude(data_ft_out[i]));
		}
		if (ft_mag.size() > 0)
		{
			ft_mag[0] = 0; // ignore the zero frequency (offset)
			int freq_max_idx = std::max_element(ft_mag.begin(), ft_mag.end()) - ft_mag.begin();
			return frequency_ft[freq_max_idx];
		}
		else
		{
			return 0;
		}
	}
	void ApplyFFT()
	{
		std::copy(raw_data.begin(),raw_data.end(),data_ft_in);
		fftw_execute(plan);
		double freq_step = 1 / ft_time_window;
		frequency_ft.resize(ft_size);
		std::generate(frequency_ft.begin(), frequency_ft.end(),
		    [n = 0, &freq_step]() mutable { return n++ * freq_step; });
	}
	std::vector<double> GetFilteredData() // this will get the raw data with a low pass filter applied, to be used in determining max for osc gain, but removing spikes
	{
		ApplyFFT();
		double filter_cutoff = 50000; // hz
		for (int i = 0; i < raw_data.size(); i++)
		{
			if ( i < raw_data.size()/16)
			{
				data_ft_out_filtered[i][0] = data_ft_out[i][0];
				data_ft_out_filtered[i][1] = data_ft_out[i][1];
			}
			else
			{
				data_ft_out_filtered[i][0] = 0;
				data_ft_out_filtered[i][1] = 0;
			}
		}
		fftw_execute(reverse_plan);
		std::vector<double> filtered_data(data_ft_in_filtered, data_ft_in_filtered + ft_size);
		// scale by 1/N
		double norm_factor = 1.0 / filtered_data.size();
		std::transform(filtered_data.begin(), filtered_data.end(), filtered_data.begin(),
		    [&norm_factor](auto& c) { return c * norm_factor; });
		return filtered_data;
	}
	void FillMiniBuffer()
	{
		std::vector<double>* buffer_update_ptr = librador_get_analog_data_sincelast(
		    channel, 5, max_sample_rate, delay_s, filter_mode);
		int buffer_update_size = buffer_update_ptr->size();
		for (int i = 0; i < buffer_update_size; i++)
		{
			int mini_buffer_idx = (mini_buffer_next_index + i) % mini_buffer.size();
			mini_buffer[mini_buffer_idx] = buffer_update_ptr->at(buffer_update_size-1-i);
		}
		mini_buffer_next_index = (mini_buffer_next_index + buffer_update_size) % mini_buffer.size();
	}
	std::vector<double> GetMiniBuffer()
	{
		if (!paused)
		{
			FillMiniBuffer();
		}
		return mini_buffer;
	}

private:
	// time domain (plot) stuff
	double time_window = 0;
	double time_start = 0;
	double time_step = 0;
	std::vector<double> time = {};
	std::vector<double> data = {};
	std::vector<double> extended_data = {};
	int channel;
	int filter_mode = 0;
	double delay_s = 0;
	double trigger_timeout = 0.02; // seconds
	double trigger_time = trigger_timeout; // seconds
	int max_plot_samples = 2048;
	double max_sample_rate = 375000;
	// frequency stuff
	std::vector<double> raw_data = {};
	std::vector<double> raw_time = {};
	int ft_size = 16384; // 2^15
	double* data_ft_in;
	fftw_complex* data_ft_out;
	std::vector<double> time_ft = {}; // currently unused as is the time vector for the resampling
	std::vector<double> frequency_ft = {};
	fftw_plan plan;
	fftw_complex* data_ft_out_filtered;
	double* data_ft_in_filtered;
	fftw_plan reverse_plan;
	double ft_sample_rate = max_sample_rate/12; // sets max frequency detection (must be a factor of the max sample rate)
	double ft_time_window = ft_size / ft_sample_rate; // sets frequency detection resolution (and min frequency detection)
	double raw_time_step = 1 / ft_sample_rate;
	// mini buffer (used for determining gain of oscilloscope)
	std::vector<double> mini_buffer = {};
	double mini_buffer_length = 0.2; // seconds
	int mini_buffer_next_index = 0;
	
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
	// fast fourier transform works best (fastest) when have the same length vector every time, and even better if it is a power of 2
	// we create a function to resample to a constant size for use with the fft
	// specifically, this function works by taking linear interpolations between samples to obtain a piecewise continuous function
	// we can then just pluck values from this with the new sample rate
	void ResampleForFT() // currently unused as is quite inefficient, i set sizes manually to ideal for frequency analysis
	{
		if (data.size() > 1 && time.size()>1)
		{
			double step;
			step = raw_data.size() / double(ft_size);
			time_ft = {};
			frequency_ft = {};
			for (int i = 0; i < ft_size; i++)
			{
				double raw_idx = i * step;
				int raw_idx_left = int(std::floor(raw_idx));
				int raw_idx_right = int(std::ceil(raw_idx));
				if (raw_idx_right >= raw_data.size())
				{
					raw_idx_right = raw_data.size() - 1;
				}
				double data_slope = raw_data[raw_idx_right] - raw_data[raw_idx_left];
				double time_slope = raw_time[raw_idx_right] - raw_time[raw_idx_left];
				// set interpolated value
				data_ft_in[i] = raw_data[raw_idx_left] + data_slope * (raw_idx - raw_idx_left);
				time_ft.push_back(raw_time[raw_idx_left] + time_slope * (raw_idx - raw_idx_left));
				double delta_time = raw_time_step * step;
				frequency_ft.push_back(i / (ft_size * delta_time));
			}
		}
	}
	double GetComplexMagnitude(fftw_complex ft_sample)
	{
		double ft_sample_re = ft_sample[0];
		double ft_sample_im = ft_sample[1];
		double ft_sample_mag = std::sqrt(ft_sample[0] * ft_sample[0] + ft_sample[1] * ft_sample[1]);
		return ft_sample_mag;
	}
};


