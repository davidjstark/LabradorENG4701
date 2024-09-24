// Source: https://github.com/ZenSepiol/Dear-ImGui-App-Framework/blob/main/src/app/sample_app/app.hpp
#pragma once
#include "AppBase.hpp"
#include "implot_internal.h"
#include <iostream>
#include <string>
#include <librador.h>
#include "PSUControl.hpp"
#include "OSCControl.hpp"
#include "SGControl.hpp"
#include "PlotWidget.hpp"
#include "PlotControl.hpp"
#include "util.h"

// #define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_internal.h"

// Global textures to be loaded once during start-up
int constants::pinout_width;
int constants::pinout_height;
intptr_t constants::psu_pinout_texture = 0;
intptr_t constants::sg_pinout_texture;
intptr_t constants::osc_pinout_texture;

class App : public AppBase<App>
{
  public:
    App(){};
    virtual ~App() = default;

	void connectToLabrador()
	{
		// Initialise the USB
		int error = librador_setup_usb();
		if (error)
		{
			printf("librador_setup_usb FAILED with error code %d\t\n", error);
			// std::exit(error);
			connected = false;
		}
		else
			connected = true;
		if (connected)
		{
			printf("Device Connected Successfully!\n");

			// Print firmware info
			uint16_t deviceVersion = librador_get_device_firmware_version();
			uint8_t deviceVariant = librador_get_device_firmware_variant();
			printf("deviceVersion=%hu, deviceVariant=%hhu\n", deviceVersion, deviceVariant);

			// Reset Signal Generators
			SG1Widget.reset();
			SG2Widget.reset();
		}
		librador_set_device_mode(2);
		// need to move this somewhere better if we want to do this dynamically, but
		// cannot run too often as this causes the usb sampling bug
		librador_set_oscilloscope_gain(16);
	}
	
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

		connectToLabrador();

		// Load pinout images
		GLuint psu_tmp_texture = 0;
		GLuint sg_tmp_texture = 0;
		GLuint osc_tmp_texture = 0;
		int w, h;

		// All textures have the same width and height (for now)
		bool psu_ret = LoadTextureFromFile(".\\misc\\media\\psu-pinout.png",
			&psu_tmp_texture, &w, &h);

		bool sg_ret = LoadTextureFromFile(".\\misc\\media\\sg-pinout.png",
			&sg_tmp_texture, &w, &h);

		bool osc_ret = LoadTextureFromFile(".\\misc\\media\\osc-pinout.png",
			&osc_tmp_texture, &w, &h);

		PSUWidget.setPinoutImg((intptr_t)psu_tmp_texture, w, h);
		SG1Widget.setPinoutImg((intptr_t)sg_tmp_texture, w, h);
		SG2Widget.setPinoutImg((intptr_t)sg_tmp_texture, w, h);
		OSCWidget.setPinoutImg((intptr_t)osc_tmp_texture, w, h);

		IM_ASSERT(psu_ret);
		IM_ASSERT(sg_ret);
		IM_ASSERT(osc_ret);

		init_constants();


		// Loads README.md contents for in-app documentation
		loadREADME();
		
		SetGlobalStyle();
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

			ImDrawList* draw_list = ImGui::GetWindowDrawList();

			// Menu Bar
			static bool showDemoWindows = false;
			static bool showHelpWindow = false;
			if (ImGui::BeginMenuBar())
			{
				// Demo windows for styling/docs [TODO: REMOVE in finished product]
				if (ImGui::BeginMenu("Menu"))
				{
					ImGui::MenuItem("Show Demos", "", &showDemoWindows);
					ImGui::EndMenu();
				}

				// Device
				if (ImGui::BeginMenu("Device"))
				{
					if (connected)
					{
						// Print firmware info
						uint16_t deviceVersion = librador_get_device_firmware_version();
						uint8_t deviceVariant = librador_get_device_firmware_variant();
						ImGui::TextColored(constants::GRAY_TEXT, "Version: %hu", deviceVersion);
						ImGui::TextColored(constants::GRAY_TEXT, "Firmware: %hhu", deviceVariant);
					}
					else
					{
						ImGui::TextColored(constants::GRAY_TEXT, "No Labrador board detected");
					}
					ImGui::EndMenu();
				}
				if (ImGui::BeginMenu("Help"))
				{
					ImGui::MenuItem("User Guide", NULL, &showHelpWindow);
					ImGui::EndMenu();
				}

				if (connected)
				{
					TextRight("Labrador Connected     ");
				}
				else
				{

					TextRight("No Labrador Found     ");
					if (frames % labRefreshRate == 0)
					{
						std::cout << "Attempting to connect to Labrador\n";
						connectToLabrador();
					}
				}

				const float radius = ImGui::GetTextLineHeight() * 0.4;
				const ImU32 status_colour = ImGui::GetColorU32(
				    connected ? ImVec4(0, 1, 0, 1) : ImVec4(1, 0, 0, 1));
				const ImVec2 p1 = ImGui::GetCursorScreenPos();
				draw_list->AddCircleFilled(
				    ImVec2(p1.x - 10, p1.y + ImGui::GetTextLineHeight() - radius), radius, status_colour); 

				ImGui::EndMenuBar();
				
				
			}

			// Apply custom padding
			const int padding = 6;
			ImGuiStyle& style = ImGui::GetStyle();
			style.WindowPadding = ImVec2(padding, padding); // Custom padding within window
			
			// Get window dimensions
			ImVec2 window_size = ImGui::GetWindowSize();
			float plot_width = (window_size.x - 2*style.WindowPadding.x) * 0.60f - padding;
			float plot_height = (window_size.y - 2*style.WindowPadding.y) * 1.00f - padding;
			
			// Left Column Widgets
			style.ItemSpacing = ImVec2(0, 0); // No padding for left and right columns
			int menu_height = ImGui::GetFrameHeight();
			ImGui::BeginChild("Left Column",
			    ImVec2(plot_width, window_size.y - 2*style.WindowPadding.y - menu_height),
			    false);
			style.ItemSpacing = ImVec2(padding, padding);

			// Render scope
			// TODO: could potentially combine scope and scope controls because they will
			// have a lot of shared responsibilities
			PlotWidgetObj.setSize(ImVec2(plot_width, plot_height));
			PlotWidgetObj.Render();

			
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

			// Render Oscilloscope Widget
			OSCWidget.Render();
			

			ImGui::EndChild(); // End right column
			ImGui::End();

			// Updates state of labrador to match widgets
			if (connected)
			{
				// Call controlLab functions for each widget
				if (frames % labRefreshRate == 0)
				{
					// Check board status by setting PSU Widget
					connected = PSUWidget.controlLab();
					if (!connected) librador_reset_usb();
				}

				// Signal generators update on change
				SG1Widget.controlLab();
				SG2Widget.controlLab();
			}

			if (showDemoWindows)
			{
				// Show ImGui and ImPlot demo windows
				ImGui::ShowDemoWindow();
				ImPlot::ShowDemoWindow();
			}
			else SetGlobalStyle();

			if (showHelpWindow) renderHelpWindow(&showHelpWindow);
			for (ControlWidget* w : widgets)
			{
				if (w->show_help) w->renderHelp();
			}
		}
		frames++;
    }

	void ShutDown()
	{
		printf("Shutting Down\n");

		// Turn off Signal Generators
		SG1Widget.reset();
		SG2Widget.reset();
	}

	void loadREADME()
	{
		// Load documentation
		std::string filename = "README.md";
		std::ifstream file(filename);

		if (!file.is_open())
		{
			throw std::runtime_error("Unable to open file: " + filename);
		}

		std::stringstream buffer;
		std::string line;
		std::string curr_header = "";

		while (std::getline(file, line))
		{
			if (line.compare(0, 4, "### ") == 0)
			{
				line.erase(0, 4);
				// Write the current buffer to the correct widget
				// Widget Label must be contained within README header
				for (ControlWidget* w : widgets)
				{
					if ((w->getLabel()).find(curr_header) != std::string::npos)
					{
						w->setHelpText(buffer.str());
					}	
				}
				buffer.str("");
				buffer.clear();
				curr_header = line;
			}
			else if (line != "" && curr_header != "")
			{
				replace_all(line, "**", "");
				buffer << line << '\n';
			}
		}
	}

	void renderHelpWindow(bool* p_open)
	{
		
		if (!ImGui::Begin("Labrador User Guide", p_open))
		{
			ImGui::End();
			return;
		}
		if (!ImGui::IsWindowFocused())
		{
			*p_open = false;
			ImGui::End();
			return;
		}

		static char search[50] = "";
		ImGui::InputTextWithHint("##help_search", "Search...", search, 50);
		ImGui::SameLine();
		bool expand = ImGui::Button("Expand all");
		ImGui::SameLine();
		bool collapse = ImGui::Button("Collapse all");
		std::string search_str = std::string(search);

		for (ControlWidget* w : widgets)
		{
			ImGui::SeparatorText(w->getLabel().c_str());
			w->renderHelpText(expand, collapse, search_str.length() > 2 ? search_str : "");
		}
		ImGui::End();
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
        ImGuiIO& ioa = ImGui::GetIO();
        if (!ioa.WantCaptureMouse)
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
	//MultimeterControl MMWidget
	//    = MultimeterControl("Multimeter", ImVec2(0, 0), IM_COL32(0,0,0, 255));
	SGControl SG1Widget
	    = SGControl("Signal Generator 1 (SG1)", ImVec2(0, 0), constants::SG1_ACCENT, 1);
	SGControl SG2Widget
	    = SGControl("Signal Generator 2 (SG2)", ImVec2(0, 0), constants::SG2_ACCENT, 2);
	OSCControl OSCWidget
	    = OSCControl("Plot Settings", ImVec2(0, 0), constants::OSC_ACCENT);
	PlotWidget PlotWidgetObj 
		= PlotWidget("Plot Widget",ImVec2(0, 0),&OSCWidget);
	ControlWidget* widgets[4] = { &PSUWidget, &SG1Widget, &SG2Widget, &OSCWidget };

};

