#include "ControlWidget.hpp"
#include "librador.h"
#include "UIComponents.hpp"
#include "implot.h"

void Demo_LinePlots()
{
	static float xs1[1001], ys1[1001];
	for (int i = 0; i < 1001; ++i)
	{
		xs1[i] = i * 0.001f;
		ys1[i] = 0.5f + 0.5f * sinf(50 * (xs1[i] + (float)ImGui::GetTime() / 100));
	}

	if (ImPlot::BeginPlot("##Line Plots", ImVec2(100, 100)), ImPlotFlags_CanvasOnly)
	{
		ImPlot::SetupAxes(
		    nullptr, nullptr, ImPlotAxisFlags_NoTickLabels, ImPlotAxisFlags_NoTickLabels);
		ImPlot::PlotLine("##f(x)", xs1, ys1, 201, ImPlotLineFlags_None);
		
		// ImPlot::SetNextMarkerStyle(ImPlotMarker_Circle);
		ImPlot::EndPlot();
	}
}


/// <summary>Signal Generator Widget
/// </summary>
class SGControl : public ControlWidget
{
public:
	
	SGControl(const char* label, ImVec2 size, ImU32 accentColour)
	    : ControlWidget(label, size, accentColour)
	    , active(false)
	    , toggle_id(label + (std::string)"_toggle")
	    , wt_current_idx(0)
	{}
	
	/// <summary> 
	/// Render UI elements for Signal Generator
	/// </summary>
	void renderControl() override
	{
		ImGui::Dummy(ImVec2(0.0f, 5.0f)); // add space
		ImGui::Text("Power");
		ImGui::SameLine();
		ImGui::Text("   OFF");
		ImGui::SameLine();
		ToggleSwitch(toggle_id.c_str(), &active, accentColour);
		ImGui::SameLine();
		ImGui::Text("ON");
		
		const char* wt_preview_value = constants::wavetypes[wt_current_idx];
		// TODO: define a generic Dropdown menu in UIComponents
		if (ImGui::BeginCombo("wavetypes", wt_preview_value, 0))
		{
			for (int n = 0; n < IM_ARRAYSIZE(constants::wavetypes); n++)
			{
				const bool is_selected = (wt_current_idx == n);
				if (ImGui::Selectable(constants::wavetypes[n], is_selected))
					wt_current_idx = n;

				// Set the initial focus when opening the combo (scrolling + keyboard
				// navigation focus)
				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndCombo();
		}
		ImGui::SeparatorText((std::string(wt_preview_value) + " Wave Properties").c_str());

		const float width = ImGui::GetContentRegionAvail().x;

		switch (wt_current_idx)
		{
		case 0: // SINE

			// Controls
			ImGui::BeginChild("sg1_wave_control", ImVec2(width * 0.5f, 0.0f));
			ImGui::Text("Amplitude");
			ImGui::Text("Frequency");
			ImGui::Text("Phase Offset");
			ImGui::EndChild();
			// Preview
			ImGui::SameLine();
			Demo_LinePlots();
			break;
		}
		
			
	}

	/// <summary>
	/// Set the Signal Generator on the labrador board.
	/// </summary>
	void controlLab() override
	{

	}

private:
	std::string toggle_id;
	bool active;
	int wt_current_idx = 0;
};
