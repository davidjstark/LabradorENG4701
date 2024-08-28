#pragma once
#include <vector>
#include "librador.h"
#include "algorithm"
class OSCControl;

class OscData
{
public:
	OscData(OSCControl* osc_control,int channel)
	    : osc_control(osc_control)
	    , channel(channel)
	{}

	std::vector<double>* GetData();
	std::vector<double> GetTime(double plot_min);
	void SetTimeWindow(double t);

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


