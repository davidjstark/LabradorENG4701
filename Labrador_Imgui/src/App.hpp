// Source: https://github.com/ZenSepiol/Dear-ImGui-App-Framework/blob/main/src/app/sample_app/app.hpp
#include "AppBase.hpp"
#include "implot_internal.h"
#include <iostream>
#include <string>
#include <librador.h>

// #define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_internal.h"

class App : public AppBase<App>
{
  public:
    App(){};
    virtual ~App() = default;

    // Anything that needs to be called once OUTSIDE of the main application loop
    void StartUp()
    {
		int error = librador_init();
		if (error)
		{
			printf("librador_init FAILED with error code %d\t\n", error);
			// std::exit(error);
			connected = false;
		}

		// Initialise the USB
		error = librador_setup_usb();
		if (error)
		{
			printf("librador_setup_usb FAILED with error code %d\t\n", error);
			// std::exit(error);
			connected = false;
		}
		if (connected) printf("Device Connected Successfully!\n");

		// Print firmware info
		uint16_t deviceVersion = librador_get_device_firmware_version();
		uint8_t deviceVariant = librador_get_device_firmware_variant();
		printf("deviceVersion=%hu, deviceVariant=%hhu\n", deviceVersion, deviceVariant);
    }

    // Anything that needs to be called cyclically INSIDE of the main application loop
    void Update()
    {
		if (false)
		{
			// Show ImGui and ImPlot demo windows
			ImGui::ShowDemoWindow();
			ImPlot::ShowDemoWindow();
		}

		static float voltage = 4.5;
		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to
		// create a named window.
		
		if (false)
		{
			static int counter = 0;

			ImGui::Begin("Labrador Controller"); // Create a window called "Hello, world!" and
			                               // append into it.

			ImGui::Text("Aiming to push this voltage to Power Supply on Labrador board "
			            "with libusbk library."); // Display some text (you can use a
			                                      // format strings too)

			ImGui::SliderFloat("Voltage (PSU)", &voltage, 4.5f, 6.0f, "%.1f V");

			if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets
			                             // return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);
			static float framerate = ImGui::GetIO().Framerate;

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
			    1000.0f / framerate, framerate);
			ImGui::End();
		}

		{
			// Main window
			ImGui::SetNextWindowPos(ImVec2(0, 0));
			ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
			ImGui::Begin("Main Window", NULL,
			    ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove
			        | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

			// Apply custom padding
			const int padding = 10;
			ImGuiStyle& style = ImGui::GetStyle();
			style.WindowPadding = ImVec2(padding, padding); // Custom padding within window
			
			// Get window dimensions
			ImVec2 window_size = ImGui::GetWindowSize();
			float plot_width = (window_size.x - 2*style.WindowPadding.x) * 0.60f - padding;
			float plot_height = (window_size.y - 2*style.WindowPadding.y) * 0.75f - padding;
			
			
			style.ItemSpacing = ImVec2(0, 0); // No padding for left and right columns
			// Plot widget with unique outline color
			ImGui::BeginChild("Left Column",
			    ImVec2(plot_width + 2*padding, window_size.y - 2*style.WindowPadding.y),
			    false);
			style.ItemSpacing = ImVec2(padding, padding);

			ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(255, 0, 0, 255)); // Red border
			ImGui::BeginChild("Plot Widget", ImVec2(plot_width, plot_height), true);
			ImGui::Text("Plot Widget");
			// Your plot drawing code here
			ImGui::EndChild();
			ImGui::PopStyleColor();

			// Control widget under plot with unique outline color
			ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(0, 255, 0, 255)); // Green border
			ImGui::BeginChild("Control Widget Under Plot",
			    ImVec2(plot_width, 0), true);
			ImGui::Text("Control Widget Under Plot");
			// Your control code here
			ImGui::EndChild();
			ImGui::PopStyleColor();
			
			ImGui::EndChild(); // End Left Column

			// Right column control widgets
			float control_widget_height = (window_size.y - 2*style.WindowPadding.y - 3*style.ItemSpacing.y) * 0.25f;
			
			style.ItemSpacing = ImVec2(0, 0);
			ImGui::SameLine();
			ImGui::BeginChild("Right Column",
			    ImVec2(window_size.x - plot_width - 2*padding - 2*style.WindowPadding.x,
			        window_size.y - 2 * style.WindowPadding.y),
			    false);
			style.ItemSpacing = ImVec2(padding, padding);

			// Control widget 1 with unique outline color
			ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(0, 0, 255, 255)); // Blue border
			ImGui::BeginChild("Control Widget 1", ImVec2(0, control_widget_height), true);
			ImGui::Text("Control Widget 1");
			// Your control code here
			ImGui::EndChild();
			ImGui::PopStyleColor();

			// Control widget 2 with unique outline color
			ImGui::PushStyleColor(
			    ImGuiCol_Border, IM_COL32(255, 255, 0, 255)); // Yellow border
			ImGui::BeginChild("Control Widget 2", ImVec2(0, control_widget_height), true);
			ImGui::Text("Control Widget 2");
			// Your control code here
			ImGui::EndChild();
			ImGui::PopStyleColor();

			// Control widget 3 with unique outline color
			ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(0, 255, 255, 255)); // Cyan border
			ImGui::BeginChild("Control Widget 3", ImVec2(0, control_widget_height), true);
			ImGui::Text("Control Widget 3");
			// Your control code here
			ImGui::EndChild();
			ImGui::PopStyleColor();

			// Control widget 4 with unique outline color
			ImGui::PushStyleColor(
			    ImGuiCol_Border, IM_COL32(255, 0, 255, 255)); // Magenta border
			ImGui::BeginChild("Control Widget 4", ImVec2(0, control_widget_height), true);
			ImGui::Text("Control Widget 4");
			// Your control code here
			ImGui::EndChild();
			ImGui::PopStyleColor();

			ImGui::EndChild();

			ImGui::End();
		}

		if (frames % 60 == 0 && connected)
		{
			// will run every 60 frames
			// Set the power supply voltage
			int error = librador_set_power_supply_voltage(voltage);
			if (error)
			{
				printf("librador_set_power_supply_voltage FAILED with error code "
				       "%d\tExiting...",
				    error);
				std::exit(error);
			}
			printf("Successfully set power supply voltage to %.2fV\n", voltage);
		}

		frames++;
    }

    // The callbacks are updated and called BEFORE the Update loop is entered
    // It can be assumed that inside the Update loop all callbacks have already been processed
    static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
    {
        // For Dear ImGui to work it is necessary to queue if the mouse signal is already processed by Dear ImGui
        // Only if the mouse is not already captured it should be used here.
        ImGuiIO& io = ImGui::GetIO();
        if (!io.WantCaptureMouse)
        {
        }
    }

    static void CursorPosCallback(GLFWwindow* window, double xpos, double ypos)
    {
        // For Dear ImGui to work it is necessary to queue if the mouse signal is already processed by Dear ImGui
        // Only if the mouse is not already captured it should be used here.
        ImGuiIO& io = ImGui::GetIO();
        if (!io.WantCaptureMouse)
        {
        }
    }

    static void KeyCallback(GLFWwindow* window, int key, int scancode, int actions, int mods)
    {
        // For Dear ImGui to work it is necessary to queue if the keyboard signal is already processed by Dear ImGui
        // Only if the keyboard is not already captured it should be used here.
        ImGuiIO& io = ImGui::GetIO();
        if (!io.WantCaptureKeyboard)
        {
        }
    }

  private:
	int frames = 0;
	bool connected = true;
};