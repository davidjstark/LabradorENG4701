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
	SGControl(std::string label, ImVec2 size, const float* accentColour, int channel,
	     float* getPSUVoltage)
	    : ControlWidget(label, size, accentColour)
	    , channel(channel)
	    , active(false)
	    , switched(false)
	    , label(label)
	    , signal_idx(0)
	    , pPSUVoltage(getPSUVoltage)
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
		switched
		    = ToggleSwitch((label + "_toggle").c_str(), &active, colourConvert(accentColour));
		ImGui::SameLine();
		ImGui::Text("ON");
		
		switched |= ObjectDropDown(("##" + label + "wt_selector").c_str(), signals,
		    &signal_idx, IM_ARRAYSIZE(constants::wavetypes));

		ImGui::SeparatorText(
		    ((signals[signal_idx]->getLabel()) + " Wave Properties").c_str());
		
		switched = (signals[signal_idx]->renderControl()) || switched;
		
		// Clipping may occur if PSU Voltage is not high enough
		if (signals[signal_idx]->getSignalMax() > *pPSUVoltage - 1.18)
		{
			ImGui::SetTooltip(
			    "Increase Power Supply voltage to\nprevent clipping on signal generator.");
		}
	}

	/// <summary>
	/// Set the Signal Generator on the labrador board.
	/// </summary>
	bool controlLab() override
	{
		if (switched)
		{
			if (!active)
			{
				signals[signal_idx]->turnOff(channel);
				return true;
			}
			else
			{
				signals[signal_idx]->controlLab(channel);
				return true;
			}
		}
		return false;
		
	}

	void reset()
	{
		signals[0]->turnOff(channel);
	}

private:
	const std::string label;
	int channel;
	bool active;
	bool switched;
	int signal_idx = 0;
	GenericSignal* signals[4];
	float* pPSUVoltage;
};
