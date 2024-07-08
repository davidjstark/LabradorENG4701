// Source: https://github.com/ZenSepiol/Dear-ImGui-App-Framework/blob/main/src/app/sample_app/app.hpp
#include "AppBase.hpp"
#include "implot_internal.h"
#include <iostream>
#include <string>
#include <librador.h>
#include "PSUControl.hpp"
#include "OSCControl.hpp"
#include "SGControl.hpp"
#include "MultimeterControl.hpp"

#include "util.h"

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

		init_constants();
    }

    // Anything that needs to be called cyclically INSIDE of the main application loop
    void Update()
    {
		
		{
			// Main window
			ImGui::SetNextWindowPos(ImVec2(0, 0));
			ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
			ImGui::Begin("Main Window", NULL,
			    ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse
			        | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_MenuBar);

			// Menu Bar
			static bool showDemoWindows = false;
			if (ImGui::BeginMenuBar())
			{
				if (ImGui::BeginMenu("Menu"))
				{
					ImGui::MenuItem("Show Demos", "", &showDemoWindows);
					ImGui::EndMenu();
				}
				ImGui::EndMenuBar();
			}

			// Apply custom padding
			const int padding = 6;
			ImGuiStyle& style = ImGui::GetStyle();
			style.WindowPadding = ImVec2(padding, padding); // Custom padding within window
			
			// Get window dimensions
			ImVec2 window_size = ImGui::GetWindowSize();
			float plot_width = (window_size.x - 2*style.WindowPadding.x) * 0.60f - padding;
			float plot_height = (window_size.y - 2*style.WindowPadding.y) * 0.75f - padding;
			
			// Left Column Widgets
			style.ItemSpacing = ImVec2(0, 0); // No padding for left and right columns
			int menu_height = ImGui::GetFrameHeight();
			ImGui::BeginChild("Left Column",
			    ImVec2(plot_width, window_size.y - 2*style.WindowPadding.y - menu_height),
			    false);
			style.ItemSpacing = ImVec2(padding, padding);

			// Render scope
			// TODO: could potentially combine scope and scope controls because they will have a lot of shared responsibilities
			ImGui::PushStyleColor(ImGuiCol_Border, IM_COL32(255,255,255, 255));
			ImGui::BeginChild("Plot Widget", ImVec2(plot_width, plot_height), true);
			ImGui::Text("Plot Widget");
			// plot drawing code here
			ImGui::EndChild();
			ImGui::PopStyleColor();

			// Render Oscilloscope controls
			OSCWidget.setSize(ImVec2(plot_width, 0));
			OSCWidget.Render();
			
			ImGui::EndChild(); // End left column

			// Right column control widgets
			float control_widget_height = (window_size.y - 2*style.WindowPadding.y - 3*style.ItemSpacing.y) * 0.25f;
			
			style.ItemSpacing = ImVec2(padding, 0);
			ImGui::SameLine(); 
			ImGui::BeginChild("Right Column",ImVec2(
				window_size.x - plot_width - 2 * padding - 2 * style.WindowPadding.x,
			    window_size.y - 2 * style.WindowPadding.y - menu_height),
			    false);
			style.ItemSpacing = ImVec2(padding, padding);

			// ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(10, 10, 10, 255));
			
			// Render PSU Control
			PSUWidget.setSize(ImVec2(0, control_widget_height));
			PSUWidget.Render();

			// Render Signal Gen 1
			SG1Widget.setSize(ImVec2(0, control_widget_height));
			SG1Widget.Render();

			// Render Signal Gen 2
			SG2Widget.setSize(ImVec2(0, control_widget_height));
			SG2Widget.Render();

			// Render Multimeter
			MMWidget.setSize(ImVec2(0, 0)); // fill rest of space
			MMWidget.Render();

			// ImGui::PopStyleColor();

			ImGui::EndChild(); // End right column
			ImGui::End();

			// Updates state of labrador to match widgets
			if (connected && frames % labRefreshRate == 0)
			{
				// Call controlLab functions for each widget
				PSUWidget.controlLab();
				SG1Widget.controlLab();
				SG2Widget.controlLab();
			}

			if (showDemoWindows)
			{
				// Show ImGui and ImPlot demo windows
				ImGui::ShowDemoWindow();
				ImPlot::ShowDemoWindow();
			}
				
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
	const int labRefreshRate = 60; // send controls to labrador every this many frames
	bool connected = true; // state of labrador connection
	// Define default configurations for widgets here
	PSUControl PSUWidget = PSUControl("Power Supply Unit (PSU)", ImVec2(0,0), constants::PSU_ACCENT);
	MultimeterControl MMWidget
	    = MultimeterControl("Multimeter", ImVec2(0, 0), IM_COL32(0,0,0, 255));
	SGControl SG1Widget
	    = SGControl("Signal Generator 1 (SG1)", ImVec2(0, 0), constants::SG1_ACCENT, 1);
	SGControl SG2Widget
	    = SGControl("Signal Generator 2 (SG2)", ImVec2(0, 0), constants::SG2_ACCENT, 2);
	OSCControl OSCWidget
	    = OSCControl("Scope Settings", ImVec2(0, 0), IM_COL32(0,0,0, 255));
};

