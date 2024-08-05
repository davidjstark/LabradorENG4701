#include "librador.h"
#include "implot.h"
#include "util.h"
#include "UIComponents.hpp"
#include <string>

class GenericSignal
{
public:
	GenericSignal(const std::string& label, const float* preview)
	    : label(label)
	    , preview(preview)
	{
	}

	std::string getLabel() const
	{
		return label;
	}

	/// <summary>
	/// Generic UI elements for Signal Control
	/// </summary>
	void renderControl()
	{
		const float width = ImGui::GetContentRegionAvail().x;
		const float height = ImGui::GetFrameHeightWithSpacing();

		// Controls
		ImGui::BeginChild((label + "_control").c_str(), ImVec2(width * 0.5f, height * 3.0f));

		renderProperties();

		ImGui::EndChild();

		// Preview
		ImGui::SameLine();
		ImPlotStyle backup = ImPlot::GetStyle();
		PreviewStyle();
		if (ImPlot::BeginPlot((label + "_preview").c_str(), ImVec2(width * 0.4, 3 * height),
		        ImPlotFlags_CanvasOnly | ImPlotFlags_NoInputs))
		{
			renderPreview();
		}

		ImPlot::GetStyle() = backup;
	}

	void renderPreview()
	{
		ImPlot::SetupAxes(nullptr, nullptr, ImPlotAxisFlags_NoDecorations,
		    ImPlotAxisFlags_NoDecorations);
		ImPlot::SetupAxesLimits(-5, constants::PREVIEW_RES + 5, 1.2, -1.2, ImGuiCond_Always);
		ImPlot::PlotLine(("##" + label + "_plot_preview").c_str(), constants::x_preview,
		    preview, constants::PREVIEW_RES);

		renderAnnotations();

		ImPlot::EndPlot();
	}


	// Customise for each widget
	virtual void renderProperties() = 0;
	
	virtual void renderAnnotations() = 0;

	/// <summary>
	/// Set the Signal Generator on the labrador board.
	/// </summary>
	virtual void controlLab(int channel) = 0;

protected:
	std::string label;
	const float* preview;
	float amplitude = 1.0f;
	float offset = 0.0f;
	float frequency = 100.0f;
	int amp_unit_idx = 2;
	int freq_unit_idx = 0;
	int os_unit_idx = 2;
};


/// <summary>Sine Signal Generator Widget
/// </summary>
class SineSignal : public GenericSignal
{
public:
	
	SineSignal(const std::string& label)
	    : GenericSignal(label, constants::sine_preview)
	{}

	void renderProperties() override
	{
		// Amplitude
		renderSliderwUnits(label + "_amp", &amplitude, 0.1f, 3.0f, "Amplitude = %.2f",
		    constants::volt_units, &amp_unit_idx);

		// Frequency
		renderSliderwUnits(label + "_freq", &frequency, 0.1f, 999.0f, "Frequency = %.0f",
		    constants::freq_units, &freq_unit_idx);

		// Offset
		renderSliderwUnits(label + "_os", &offset, 0.0f, 3.0f, "Offset = %.2f",
		    constants::volt_units, &os_unit_idx);
	}

	void renderAnnotations() override
	{
		float period = constants::PREVIEW_RES;
		float plt_amp = 1.0f;

		float amp_label_x[2] = { period / 4, period / 4 };
		float amp_label_y[2] = { plt_amp, 0.0f };

		ImPlot::PlotLine(("##" + label + "_amp").c_str(), amp_label_x, amp_label_y, 2);
		ImPlot::PlotScatter(("##" + label + "_amp_pnt").c_str(), amp_label_x, amp_label_y, 2);
		// Annotate amplitude
		ImPlot::Annotation(period / 4, 0, ImVec4(0, 0, 0, 0), ImVec2(0, 5), true,
		    "A = %.2f V", amplitude);

		float per_label_x[2] = { 0, period };
		float per_label_y[2] = { 0.0f, 0.0f };

		ImPlot::PlotLine(("##" + label + "_per").c_str(), per_label_x, per_label_y, 2);
		ImPlot::PlotScatter(("##" + label + "_per_pnt").c_str(), per_label_x, per_label_y, 2);
		// Annotate amplitude
		ImPlot::Annotation(3 * period / 4, 0, ImVec4(0, 0, 0, 0), ImVec2(0, -5), true,
		    "T = %.2f s", 1 / frequency);
	}
	/// <summary>
	/// Set the Signal Generator on the labrador board.
	/// </summary>
	void controlLab(int channel) override
	{
		// TODO: convert to correct units
		librador_send_sin_wave(channel, frequency, amplitude, offset);
	}
	
};

/// <summary>Square Signal Generator Widget
/// </summary>
class SquareSignal : public GenericSignal
{
public:
	SquareSignal(const std::string& label)
	    : GenericSignal(label, constants::square_preview)
	{
	}

	void renderProperties() override
	{
		// Amplitude
		renderSliderwUnits(label + "_amp", &amplitude, 0.0f, 3.0f, "Amplitude = %.2f",
		    constants::volt_units, &amp_unit_idx);

		// Frequency
		renderSliderwUnits(label + "_freq", &frequency, 0.0f, 999.0f, "Frequency = %.0f",
		    constants::freq_units, &freq_unit_idx);

		// Offset
		renderSliderwUnits(label + "_os", &offset, 0.0f, 3.0f, "Offset = %.2f",
		    constants::volt_units, &os_unit_idx);
	}

	void renderAnnotations() override
	{
		float period = constants::PREVIEW_RES;
		float plt_amp = 1.0f;

		float amp_label_x[2] = { 3*period / 4, 3*period / 4 };
		float amp_label_y[2] = { plt_amp, 0.0f };

		ImPlot::PlotLine(("##" + label + "_amp").c_str(), amp_label_x, amp_label_y, 2);
		ImPlot::PlotScatter(("##" + label + "_amp_pnt").c_str(), amp_label_x, amp_label_y, 2);
		// Annotate amplitude
		ImPlot::Annotation(amp_label_x[0], 0, ImVec4(0, 0, 0, 0), ImVec2(0, 5), true,
		    "A = %.2f V", amplitude);

		float per_label_x[2] = { 0, period };
		float per_label_y[2] = { 0.0f, 0.0f };

		ImPlot::PlotLine(("##" + label + "_per").c_str(), per_label_x, per_label_y, 2);
		ImPlot::PlotScatter(("##" + label + "_per_pnt").c_str(), per_label_x, per_label_y, 2);
		// Annotate amplitude
		ImPlot::Annotation(period / 4, 0, ImVec4(0, 0, 0, 0), ImVec2(0, -5), true,
		    "T = %.2f s", 1 / frequency);
	}


	/// <summary>
	/// Set the Signal Generator on the labrador board.
	/// </summary>
	void controlLab(int channel) override
	{
		// TODO: convert to correct units
		librador_send_square_wave(channel, frequency, amplitude, offset);
	}
};

/// <summary>Sawtooth Signal Generator Widget
/// </summary>
class SawtoothSignal : public GenericSignal
{
public:
	SawtoothSignal(const std::string& label)
	    : GenericSignal(label, constants::sawtooth_preview)
	{
	}

	void renderProperties() override
	{
		// Amplitude
		renderSliderwUnits(label + "_amp", &amplitude, 0.0f, 3.0f, "Amplitude = %.2f",
		    constants::volt_units, &amp_unit_idx);

		// Frequency
		renderSliderwUnits(label + "_freq", &frequency, 0.0f, 999.0f, "Frequency = %.0f",
		    constants::freq_units, &freq_unit_idx);

		// Offset
		renderSliderwUnits(label + "_os", &offset, 0.0f, 3.0f, "Offset = %.2f",
		    constants::volt_units, &os_unit_idx);
	}

	void renderAnnotations() override
	{
		float period = constants::PREVIEW_RES;
		float plt_amp = 1.0f;

		float amp_label_x[2] = { period / 2, period / 2 };
		float amp_label_y[2] = { plt_amp, 0.0f };

		ImPlot::PlotLine(("##" + label + "_amp").c_str(), amp_label_x, amp_label_y, 2);
		ImPlot::PlotScatter(("##" + label + "_amp_pnt").c_str(), amp_label_x, amp_label_y, 2);
		// Annotate amplitude
		ImPlot::Annotation(3 * period/4, plt_amp/2, ImVec4(0, 0, 0, 0), ImVec2(0, 0), true,
		    "A = %.2f V", amplitude);

		float per_label_x[2] = { 0, period };
		float per_label_y[2] = { 0.0f, 0.0f };

		ImPlot::PlotLine(("##" + label + "_per").c_str(), per_label_x, per_label_y, 2);
		ImPlot::PlotScatter(("##" + label + "_per_pnt").c_str(), per_label_x, per_label_y, 2);
		// Annotate amplitude
		ImPlot::Annotation(period / 4, 0, ImVec4(0, 0, 0, 0), ImVec2(0, 5), true,
		    "T = %.2f s", 1 / frequency);
	}

	/// <summary>
	/// Set the Signal Generator on the labrador board.
	/// </summary>
	void controlLab(int channel) override
	{
		// TODO: convert to correct units
		librador_send_sawtooth_wave(channel, frequency, amplitude, offset);
	}
};

/// <summary>Triangle Signal Generator Widget
/// </summary>
class TriangleSignal : public GenericSignal
{
public:
	TriangleSignal(const std::string& label)
	    : GenericSignal(label, constants::triangle_preview)
	{
	}

	void renderProperties() override
	{
		// Amplitude
		renderSliderwUnits(label + "_amp", &amplitude, 0.0f, 3.0f, "Amplitude = %.2f",
		    constants::volt_units, &amp_unit_idx);

		// Frequency
		renderSliderwUnits(label + "_freq", &frequency, 0.0f, 999.0f, "Frequency = %.0f",
		    constants::freq_units, &freq_unit_idx);

		// Offset
		renderSliderwUnits(label + "_os", &offset, 0.0f, 3.0f, "Offset = %.2f",
		    constants::volt_units, &os_unit_idx);
	}

	void renderAnnotations() override
	{
		float period = constants::PREVIEW_RES;
		float plt_amp = 1.0f;

		float amp_label_x[2] = { period / 2, period / 2 };
		float amp_label_y[2] = { plt_amp, 0.0f };

		ImPlot::PlotLine(("##" + label + "_amp").c_str(), amp_label_x, amp_label_y, 2);
		ImPlot::PlotScatter(("##" + label + "_amp_pnt").c_str(), amp_label_x, amp_label_y, 2);
		// Annotate amplitude
		ImPlot::Annotation(amp_label_x[0], 0, ImVec4(0, 0, 0, 0), ImVec2(0, 5), true,
		    "A = %.2f V", amplitude);

		float per_label_x[2] = { 0, period };
		float per_label_y[2] = { -amplitude, -amplitude };

		ImPlot::PlotLine(("##" + label + "_per").c_str(), per_label_x, per_label_y, 2);
		ImPlot::PlotScatter(("##" + label + "_per_pnt").c_str(), per_label_x, per_label_y, 2);
		// Annotate amplitude
		ImPlot::Annotation(period / 2, 0, ImVec4(0, 0, 0, 0), ImVec2(0, -5), true,
		    "T = %.2f s", 1 / frequency);
	}

	/// <summary>
	/// Set the Signal Generator on the labrador board.
	/// </summary>
	void controlLab(int channel) override
	{
		// TODO: convert to correct units
		librador_send_triangle_wave(channel, frequency, amplitude, offset);
	}
};