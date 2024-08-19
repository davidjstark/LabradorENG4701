#include "ControlWidget.hpp"
#include "librador.h"
#include "UIComponents.hpp"
#include "implot.h"
#include "util.h"
#include "SignalType.hpp"

/// <summary>Signal Generator Widget
/// </summary>
class SGControl : public ControlWidget
{
public:
	
	// Constructor
	SGControl(std::string label, ImVec2 size, ImU32 accentColour, int channel)
	    : ControlWidget(label, size, accentColour)
	    , channel(channel)
	    , active(false)
	    , label(label)
	    , signal_idx(0)
	{
		signals[0] = new SineSignal("Sine");
		signals[1] = new SquareSignal("Square");
		signals[2] = new SawtoothSignal("Sawtooth");
		signals[3] = new TriangleSignal("Triangle");
	}
	
	// Destructor
	~SGControl()
	{
		for (int i = 0; i < 4; ++i)
		{
			delete signals[i];
		}
	}
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
		
		ObjectDropDown(("##" + label + "wt_selector").c_str(), signals,
		    &signal_idx, IM_ARRAYSIZE(constants::wavetypes));

		ImGui::SeparatorText(
		    ((signals[signal_idx]->getLabel()) + " Wave Properties").c_str());
		
		signals[signal_idx]-> renderControl();	
	}

	/// <summary>
	/// Render help message in popup window
	/// </summary>
	void renderHelp() override
	{
		ImGui::Text("HELP HERE");
		// Pinout image
		ImGui::Image((void*)constants::sg_pinout_texture,
		    ImVec2(constants::pinout_width, constants::pinout_height));
	}

	/// <summary>
	/// Set the Signal Generator on the labrador board.
	/// </summary>
	void controlLab() override
	{
		if (active)
		{
			signals[signal_idx] -> controlLab(channel);
		}
		
	}

private:
	const std::string label;
	int channel;
	bool active;
	int signal_idx = 0;
	GenericSignal* signals[4];
};
