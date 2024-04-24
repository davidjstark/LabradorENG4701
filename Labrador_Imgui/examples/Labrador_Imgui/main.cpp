// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <Windows.h> // Added for libusbk
#include "libusbk.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

// This example can also compile and run with Emscripten! See 'Makefile.emscripten' for details.
#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

KUSB_HANDLE handle = NULL; // global var !!
#define BOARD_VID 0x03eb // labrador specific
#define BOARD_PID 0xba94
#define GOBINDAR_PID 0xa000 // two PIDs, trying the first one BOARD_PID
unsigned char inBuffer[256]; // for usb send

// Helper functions (hacked in here for the moment, to be moved to another file)
unsigned char usbInit(unsigned long VIDin, unsigned long PIDin) {

    //This function gets you a USB handle, as well as any other data needed to send a control transfer over USB.
    //You should be able to call usbSendControl() immediately after this function has returned success!!

    unsigned char success;
    KLST_DEVINFO_HANDLE deviceInfo = NULL;
    UINT deviceCount = 0;
    DWORD ec = ERROR_SUCCESS;
    KLST_HANDLE deviceList = NULL;

    //List libusbk devices connected
    if (!LstK_Init(&deviceList, (KLST_FLAG)0)) {
        printf("Error initializing device list\n");
        return 1;
    } //else qDebug() << "Device List initialised!";

    /*
    LstK_Count(deviceList, &deviceCount);
    if (!deviceCount) {
        qDebug("Device list empty");
        LstK_Free(deviceList);	// If LstK_Init returns TRUE, the list must be freed.
        return 0;
    } //else qDebug() << "Device Count initialised!";
*/

//Look for Labrador!
    LstK_FindByVidPid(deviceList, VIDin, PIDin, &deviceInfo);
    LstK_Free(deviceList);
    if (deviceInfo == NULL) {
        printf("Could not find device VID = %04X, PID = %04X\n", VIDin, PIDin);
        return 2;
    }

    //Open Labrador!!
    success = UsbK_Init(&handle, deviceInfo);
    if (!success) {
        ec = GetLastError();
        printf("UsbK_Init failed. ErrorCode: %08Xh\n", ec);
        return 3;
    }
    else printf("Device opened successfully!\n");

    if (handle == NULL) {
        return 4; //Unkown error, only exists on 32 bit???
    }

    return 0;
}

void usbSendControl(uint8_t RequestType, uint8_t Request, uint16_t Value, uint16_t Index, uint16_t Length, unsigned char* LDATA) {

    //This function sends a control transfer over USB.
    //LDATA is a pointer to the buffer that is going to be sent to the device.  If no buffer is to be sent, LDATA should be NULL (and any implementation should be able to handle this case!!).
    //The Linux implementation of this is trivially simple.  Have a look!

    //////////////////////////////////////////////////////////////////////////////////////////
    //IF YOU'RE SEEING AN ERROR, CHECK THAT REQUESTTYPE AND REQUEST ARE FORMATTED AS HEX
    //////////////////////////////////////////////////////////////////////////////////////////    

    WINUSB_SETUP_PACKET setupPacket;
    unsigned char controlSuccess;
    UINT bytesTransferred = 0;
    unsigned char* controlBuffer;
    DWORD errorCode = ERROR_SUCCESS;

    /*if (!connected) {
        qDebug() << "Not connected.  Ignoring Control Request!!!";
    }*/
    //Error checking
    if (handle == NULL) {
        printf("Null handle error in usbSendControl\n");
        return;
    }

    //Fill the setup packet
    setupPacket.RequestType = RequestType;
    setupPacket.Request = Request;
    setupPacket.Value = Value;
    setupPacket.Index = Index;
    setupPacket.Length = Length;

    //Check for case of null LDATA
    if (LDATA == NULL) {
        controlBuffer = inBuffer;
    }
    else controlBuffer = LDATA;

    //Send the packet
    controlSuccess = UsbK_ControlTransfer(handle, setupPacket, controlBuffer, setupPacket.Length, &bytesTransferred, NULL);
    if (controlSuccess) {
        printf("%d BYTES TRANSFERRED\n", bytesTransferred);
    }
    else {
        errorCode = GetLastError();
        printf("UsbK_ControlTransfer failed with error code %d\n", errorCode);
        if (errorCode == 170) { //Device not connected?? (According to test)
            // killMe();
        }
    }
}


// Main code
int main(int, char**)
{
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // USB Stuff
    int ec = usbInit(BOARD_VID, BOARD_PID); // Connect to Labrador
    printf("Usb Init: %d\n", ec);

    usbSendControl(0x40, 0xa3, 29, 0, 0, NULL); // 4.5 volts roughly to the PSU, after board has been calibrated with Chris's software

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
#ifdef __EMSCRIPTEN__
    ImGui_ImplGlfw_InstallEmscriptenCanvasResizeCallback("#canvas");
#endif
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    // - Our Emscripten build process allows embedding fonts to be accessible at runtime from the "fonts/" folder. See Makefile.emscripten for details.
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != nullptr);

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    unsigned int frames = 0;

    // Main loop
#ifdef __EMSCRIPTEN__
    // For an Emscripten build we are disabling file-system access, so let's not attempt to do a fopen() of the imgui.ini file.
    // You may manually call LoadIniSettingsFromMemory() to load settings from your own storage.
    io.IniFilename = nullptr;
    EMSCRIPTEN_MAINLOOP_BEGIN
#else
    while (!glfwWindowShouldClose(window))
#endif
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        static float voltage = 4.5f;

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("Aiming to push this voltage to Power Supply on Labrador board with libusbk library."); // Display some text (you can use a format strings too)

            ImGui::SliderFloat("Voltage (PSU)", &voltage, 4.5f, 6.0f, "%.1f V");            // Edit 1 float using a slider from 0.0f to 1.0f

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        if (frames % 60 == 0) {
            // will run every 60 frames (1 sec on my monitor)
            if (handle == NULL) {
                printf("Labrador not connected.\n");
            }
            else { // Send a Control signal to Labrador to set voltage on PSU
                int dutyTemp = (int)29 + (voltage - 4.5) * (11 / 1.5) + 0.5; // maps from range (4.5, 29) to (29, 40)
                printf("Sent to PSU: %d\n", dutyTemp);
                usbSendControl(0x40, 0xa3, dutyTemp, 0, 0, NULL);
            }
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);

        frames++;
    }
#ifdef __EMSCRIPTEN__
    EMSCRIPTEN_MAINLOOP_END;
#endif

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
