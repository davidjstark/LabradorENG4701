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
	
	SGControl(const char* label, ImVec2 size, ImU32 accentColour, int channel)
	    : ControlWidget(label, size, accentColour)
	    , channel(channel)
	    , active(false)
	    , label(label)
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
		ToggleSwitch((label + "_toggle").c_str(), &active, accentColour);
		ImGui::SameLine();
		ImGui::Text("ON");
		
		const char* wt_preview_value = constants::wavetypes[wt_current_idx];
		DropDown(("##" + label + "wt_selector").c_str(), constants::wavetypes,
		    &wt_current_idx, IM_ARRAYSIZE(constants::wavetypes));
		ImGui::SeparatorText((std::string(wt_preview_value) + " Wave Properties").c_str());

		const float width = ImGui::GetContentRegionAvail().x;
		const float height = ImGui::GetFrameHeightWithSpacing();
		
		// TODO: Make each waveform a separate class that controls rendering and librador controls
		switch (wt_current_idx)
		{
		case 0: // SINE

			// Controls
			ImGui::BeginChild((label + "_control").c_str(), ImVec2(width * 0.5f, height * 3.0f));

			// Amplitude
			ImGui::SliderFloat(("##" + label + "_amp").c_str(), &amplitude, 0.0f, 3.0f, "Amplitude = %.2f");
			ImGui::SameLine();
			DropDown(("##" + label + "_amp_unit").c_str(), constants::volt_units,
			    &amp_unit_idx, IM_ARRAYSIZE(constants::volt_units));

			// Frequency
			ImGui::SliderFloat(("##" + label + "_freq").c_str(), &frequency, 0.0f, 999.0f, "Frequency = %.2f");
			ImGui::SameLine();
			DropDown(("##" + label + "_freq_unit").c_str(), constants::freq_units,
			    &freq_unit_idx, IM_ARRAYSIZE(constants::freq_units));

			// Offset
			ImGui::SliderFloat(("##" + label + "_offset").c_str(), &offset, -3.0f, 3.0f, "Offset = %.2f");
			ImGui::SameLine();
			DropDown(("##" + label + "_os_unit").c_str(), constants::volt_units,
			    &os_unit_idx, IM_ARRAYSIZE(constants::volt_units));

			ImGui::EndChild();
			
			// Preview
			ImGui::SameLine();
			ImPlotStyle backup = ImPlot::GetStyle();
			PreviewStyle();
			if (ImPlot::BeginPlot((label + "_preview").c_str(), ImVec2(width * 0.4, 3 * height),
			        ImPlotFlags_CanvasOnly | ImPlotFlags_NoInputs))
			{
				ImPlot::SetupAxes(nullptr, nullptr, ImPlotAxisFlags_NoDecorations,
				    ImPlotAxisFlags_NoDecorations);
				ImPlot::SetupAxesLimits(
				    0, constants::PREVIEW_RES, 1.2, -1.2, ImGuiCond_Always);
				ImPlot::PlotLine(("##" + label + "_plot_preview").c_str(), constants::x_preview,
				    constants::sine_preview, constants::PREVIEW_RES);
				ImPlot::EndPlot();
			}
			ImPlot::GetStyle() = backup;

			break;
		}
		
			
	}

	/// <summary>
	/// Set the Signal Generator on the labrador board.
	/// </summary>
	void controlLab() override
	{
		if (active)
		{
			switch (wt_current_idx)
			{
			case 0: // SINE
				// TODO: convert to correct units
				librador_send_sin_wave(channel, frequency, amplitude, offset);
			}
		}
		
	}

private:
	std::string label;
	int channel;
	bool active;
	int wt_current_idx = 0;
	float amplitude = 0.0f;
	float offset = 0.0f;
	float frequency = 100.0f;
	int amp_unit_idx = 2;
	int freq_unit_idx = 0;
	int os_unit_idx = 2;
};
