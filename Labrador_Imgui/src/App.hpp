// Source: https://github.com/ZenSepiol/Dear-ImGui-App-Framework/blob/main/src/app/sample_app/app.hpp
#include "AppBase.hpp"
#include "implot_internal.h"
#include <iostream>
#include <string>
#include <librador.h>

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
			printf("librador_init FAILED with error code %d\tExiting...", error);
			std::exit(error);
		}

		// Initialise the USB
		error = librador_setup_usb();
		if (error)
		{
			printf("librador_setup_usb FAILED with error code %d\tExiting...", error);
			std::exit(error);
		}
		printf("Device Connected Successfully!\n");

		// Print firmware info
		uint16_t deviceVersion = librador_get_device_firmware_version();
		uint8_t deviceVariant = librador_get_device_firmware_variant();
		printf("deviceVersion=%hu, deviceVariant=%hhu\n", deviceVersion, deviceVariant);
    }

    // Anything that needs to be called cyclically INSIDE of the main application loop
    void Update()
    {
		static float voltage = 4.5;
		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to
		// create a named window.
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

		if (false)
		{
			ImGui::ShowDemoWindow();
		}

		if (frames % 60 == 0)
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
};