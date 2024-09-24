#pragma once
#include "util.h"
#include "implot.h"
class Cursor
{
public:
	double x;
	double y;
	double cursor_size;
	Cursor(double init_x = 0, double init_y = 0, float cursor_size = 4.0)
	    : x(init_x)
	    , y(init_y)
	    , cursor_size(cursor_size)
	{
	}
	void Plot()
	{
		ImPlot::DragPoint(1, &x, &y, ImVec4(1, 1, 1, 1), cursor_size);
		std::string cursor_string = NumToString(x, 2) + ", " + NumToString(y, 2);
		ImVec2 cursor_text_size = ImGui::CalcTextSize(cursor_string.c_str());
		ImPlot::PlotText(cursor_string.c_str(), x, y,
		    ImVec2(cursor_text_size.x / 2 + cursor_size, 0));
	}

private:
	void PlotDashLine(double dash_size,double gap_size,ImColor line_color,constants::LineType line_type)
	{
		ImPlot::SetNextLineStyle(line_color.Value);
		
	}
};