#include "ControlWidget.hpp"
#include "librador.h"
#include "UIComponents.hpp"
#include "implot.h"
#include "util.h"

/// <summary>Signal Generator Widget
/// </summary>
class SGControl : public ControlWidget
{
public:
	
	SGControl(const char* label, ImVec2 size, ImU32 accentColour)
	    : ControlWidget(label, size, accentColour)
	    , active(false)
	    , toggle_id(label + (std::string)"_toggle")
	    , plot_id(label + (std::string)"_preview")
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
		const float height = ImGui::GetFrameHeight();
		switch (wt_current_idx)
		{
		case 0: // SINE

			// Controls
			ImGui::BeginChild((plot_id + "_control").c_str(), ImVec2(width * 0.5f, height * 3.0f));
			ImGui::Text("Amplitude");
			ImGui::Text("Frequency");
			ImGui::Text("Phase Offset");
			ImGui::EndChild();
			// Preview
			ImGui::SameLine();

			ImPlotStyle backup = ImPlot::GetStyle();
			PreviewStyle();
			if (ImPlot::BeginPlot((plot_id).c_str(), ImVec2(width * 0.4, 4 * height),
			        ImPlotFlags_CanvasOnly | ImPlotFlags_NoInputs))
			{
				ImPlot::SetupAxes(nullptr, nullptr, ImPlotAxisFlags_NoDecorations,
				    ImPlotAxisFlags_NoDecorations);
				ImPlot::SetupAxesLimits(
				    0, constants::PREVIEW_RES, 1.2, -1.2, ImGuiCond_Always);
				ImPlot::PlotLine(("##" + plot_id).c_str(), constants::x_preview,
				    constants::sine_preview, constants::PREVIEW_RES);
				ImPlot::EndPlot();
			}
			ImPlot::GetStyle() = backup;

			// ImGui::PlotLines(("##" + plot_id).c_str(), constants::sine_preview, constants::PREVIEW_RES, 0, NULL, -1.0f, 1.0f, ImVec2(width*0.4, 3*height));
			
			

			//ImPlot::PushStyleVar(ImPlotStyleVar_PlotPadding, ImVec2(0, 0));
			//if (ImPlot::BeginPlot((plot_id).c_str(), ImVec2(width * 0.4, 3 * height)),
			//    ImPlotFlags_CanvasOnly))
			//{
			//	ImPlot::SetupAxes(nullptr, nullptr, ImPlotAxisFlags_NoDecorations,
			//	    ImPlotAxisFlags_NoDecorations);
			//	ImPlot::SetupAxesLimits(0, count - 1, min_v, max_v, ImGuiCond_Always);
			//	ImPlot::SetNextLineStyle(col);
			//	ImPlot::SetNextFillStyle(col, 0.25);
			//	ImPlot::PlotLine(id, values, count, 1, 0, ImPlotLineFlags_Shaded, offset);
			//	ImPlot::EndPlot();
			//}
			//ImPlot::PopStyleVar();


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
	std::string plot_id;
	bool active;
	int wt_current_idx = 0;
};
