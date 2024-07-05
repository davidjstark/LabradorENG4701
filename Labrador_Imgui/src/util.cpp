#include "util.h"
#include "implot.h"


float constants::x_preview[constants::PREVIEW_RES];
float constants::sine_preview[constants::PREVIEW_RES];

// Initialise preview arrays
void init_constants()
{
	for (int i = 0; i < constants::PREVIEW_RES; i++)
	{
		constants::sine_preview[i] = sinf(i * (1.0f / constants::PREVIEW_RES) * 2*M_PI);
		constants::x_preview[i] = i * 1.0f;
	}
}

/// <summary>
/// Defines style for the Signal Generator Preview plot
/// </summary>
void PreviewStyle()
{
	ImPlotStyle& style = ImPlot::GetStyle();

	ImVec4* colors = style.Colors;
	colors[ImPlotCol_Line] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f); // WHITE
	colors[ImPlotCol_Fill] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f); // TRANSPARENT
	//colors[ImPlotCol_MarkerOutline] = IMPLOT_AUTO_COL;
	//colors[ImPlotCol_MarkerFill] = IMPLOT_AUTO_COL;
	//colors[ImPlotCol_ErrorBar] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	colors[ImPlotCol_FrameBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
	colors[ImPlotCol_PlotBg] = ImVec4(1.0f, 1.0f, 1.0f, 0.0f); // TRANSPARENT
	colors[ImPlotCol_PlotBorder] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	//colors[ImPlotCol_LegendBg] = ImVec4(0.92f, 0.92f, 0.95f, 1.00f);
	//colors[ImPlotCol_LegendBorder] = ImVec4(0.80f, 0.81f, 0.85f, 1.00f);
	//colors[ImPlotCol_LegendText] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	//colors[ImPlotCol_TitleText] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	//colors[ImPlotCol_InlayText] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	//colors[ImPlotCol_AxisText] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	//colors[ImPlotCol_AxisGrid] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	//colors[ImPlotCol_AxisBgHovered] = ImVec4(0.92f, 0.92f, 0.95f, 1.00f);
	//colors[ImPlotCol_AxisBgActive] = ImVec4(0.92f, 0.92f, 0.95f, 0.75f);
	//colors[ImPlotCol_Selection] = ImVec4(1.00f, 0.65f, 0.00f, 1.00f);
	//colors[ImPlotCol_Crosshairs] = ImVec4(0.23f, 0.10f, 0.64f, 0.50f);

	//style.LineWeight = 1.5;
	//style.Marker = ImPlotMarker_None;
	//style.MarkerSize = 4;
	//style.MarkerWeight = 1;
	//style.FillAlpha = 1.0f;
	//style.ErrorBarSize = 5;
	//style.ErrorBarWeight = 1.5f;
	//style.DigitalBitHeight = 8;
	//style.DigitalBitGap = 4;
	//style.PlotBorderSize = 0;
	//style.MinorAlpha = 1.0f;
	//style.MajorTickLen = ImVec2(0, 0);
	//style.MinorTickLen = ImVec2(0, 0);
	//style.MajorTickSize = ImVec2(0, 0);
	//style.MinorTickSize = ImVec2(0, 0);
	//style.MajorGridSize = ImVec2(1.2f, 1.2f);
	//style.MinorGridSize = ImVec2(1.2f, 1.2f);
	style.PlotPadding = ImVec2(0, 0);
	//style.LabelPadding = ImVec2(5, 5);
	//style.LegendPadding = ImVec2(5, 5);
	//style.MousePosPadding = ImVec2(5, 5);
	//style.PlotMinSize = ImVec2(300, 225);
}