#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include <array>
#include <iomanip>
#include <sstream>

#include "RGBHSV.h"




// Simple helper function to load an image into a OpenGL texture with common settings
bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
{
	// Load from file
	int image_width = 0;
	int image_height = 0;
	unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
	if (image_data == NULL)
		return false;

	// Create a OpenGL texture identifier
	GLuint image_texture;
	glGenTextures(1, &image_texture);
	glBindTexture(GL_TEXTURE_2D, image_texture);

	// Setup filtering parameters for display
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

	// Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
	stbi_image_free(image_data);

	*out_texture = image_texture;
	*out_width = image_width;
	*out_height = image_height;

	return true;
}
bool print_once = true;
void SetYellowStyle(ImGuiStyle* dst = NULL)
{
	ImGui::StyleColorsClassic();
	ImGuiStyle* style = dst ? dst : &ImGui::GetStyle();
	ImVec4* colors = style->Colors;

	for (int ImGuiCol = ImGuiCol_Text; ImGuiCol != ImGuiCol_COUNT; ImGuiCol++)
	{
		rgb ImGuiCol_rgb;
		ImGuiCol_rgb.r = colors[ImGuiCol].x;
		ImGuiCol_rgb.g = colors[ImGuiCol].y;
		ImGuiCol_rgb.b = colors[ImGuiCol].z;

		hsv ImGuiCol_hsv = rgb2hsv(ImGuiCol_rgb);
		ImGuiCol_hsv.h += 180;
		if (ImGuiCol_hsv.h > 360)
		{
			ImGuiCol_hsv.h -= 360;
		}
		if (print_once)
		{
			printf("Saturation: %lf\n", ImGuiCol_hsv.s);
			printf("Value: %lf\n\n", ImGuiCol_hsv.v);
		}
		ImGuiCol_hsv.s = 0.9;
		ImGuiCol_hsv.v = 0.8;
		ImGuiCol_rgb = hsv2rgb(ImGuiCol_hsv);
		colors[ImGuiCol].x = ImGuiCol_rgb.r;
		colors[ImGuiCol].y = ImGuiCol_rgb.g;
		colors[ImGuiCol].z = ImGuiCol_rgb.b;
	}
	print_once = false;
}

class OscillatorControl {
public:
	// ImGui State variables
	bool DisplayCheck = true;
	int KSComboCurrentItem = 0;
	int AttenComboCurrentItem = 0;
	float SliderVal = 0.0f;
	bool ACCoupledCheck = false;
	bool PauseButtonPressUp = false;
	ImVec4 PauseTint = ImVec4(1, 1, 1, 1);
	// ImGui const data
	// Drop down content
	const char* KSComboList[2] = { "375 KSPS","750 KSPS" };
	const char* AttenComboList[3] = { "1x","5x","10x" };
	ImGuiIO& io = ImGui::GetIO();
	ImFont* font = io.Fonts->AddFontFromFileTTF("fonts/roboto/Roboto-Regular.ttf", 24.0f);
	ImFont* fontSmall = io.Fonts->AddFontFromFileTTF("fonts/roboto/Roboto-Regular.ttf", 18.0f);
	// Layout Parameters
	float ComboWidth = 100.0f;
	ImVec2 Pos;
	ImVec2 Size = ImVec2(279, 258);
	ImVec2 ContentPos = ImVec2(10, 42);
	ImVec2 RowColumnSize = ImVec2(158, 36);
	ImVec2 ButtonPos = ImVec2(110, 168); // relative to Pos
	const char* Name;
	// Load Textures
	int PauseTextureWidth = 0;
	int PauseTextureHeight = 0;
	GLuint PauseTexture = 0;
	bool ret;
	OscillatorControl(const char* name, ImVec2 pos = ImVec2(0, 0)) {
		Pos = pos;
		Name = name;
		ret = LoadTextureFromFile("images/pause.png", &PauseTexture, &PauseTextureWidth, &PauseTextureHeight);
		IM_ASSERT(ret);
	}
	void Draw()
	{
		ImGui::SetNextWindowSize(Size);
		ImGui::SetNextWindowPos(Pos);
		ImGui::PushFont(font);
		ImGui::Begin(Name, NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		ImGui::SetCursorPos(ContentPos+RowColumnSize*ImVec2(0, 0));
		ImGui::Text("Display");
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(1, 0));
		ImGui::Checkbox(std::string((DisplayCheck ? "ON" : "OFF") + std::string("##Display")).c_str(), &DisplayCheck);
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(0, 1));
		ImGui::Text("Sample Rate");
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(1, 1));
		ImGui::SetNextItemWidth(ComboWidth);
		ImGui::PushFont(fontSmall);
		ImGui::Combo("##SampleRate", &KSComboCurrentItem, KSComboList, IM_ARRAYSIZE(KSComboList));
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(1, 2));
		ImGui::SetNextItemWidth(ComboWidth);
		ImGui::Combo("##Attenuation", &AttenComboCurrentItem, AttenComboList, IM_ARRAYSIZE(AttenComboList));
		ImGui::PushFont(font);
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(0, 2));
		ImGui::Text("Attenuation");
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(0, 3));
		ImGui::Text("Offset");
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(1, 3));
		ImGui::SetNextItemWidth(ComboWidth);
		ImGui::SliderFloat("##Offset", &SliderVal, -20, 20);
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(0, 4));
		ImGui::Text("AC Coupled");
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(1, 4));
		ImGui::Checkbox(std::string((ACCoupledCheck ? "ON" : "OFF") + std::string("##ACCoupled")).c_str(), &ACCoupledCheck);
		ImGui::SetCursorPos(ContentPos + ButtonPos);
		for (int style_col = ImGuiCol_Button; style_col < ImGuiCol_Button + 3; style_col++)
		{
			ImGui::PushStyleColor(style_col, ImVec4(0.f, 0.f, 0.f, 0.f));
		}
		PauseButtonPressUp = ImGui::ImageButton("##PauseOsc1", (void*)(intptr_t)PauseTexture, ImVec2(PauseTextureWidth, PauseTextureHeight), ImVec2(0, 0), ImVec2(1, 1), ImVec4(0, 0, 0, 0), PauseTint);
		if (ImGui::IsItemActive())
		{
			PauseTint = ImVec4(0.7, 0.7, 0.7, 0.7);
		}
		else if (ImGui::IsItemHovered())
		{
			PauseTint = ImVec4(0.9, 0.9, 0.9, 0.9);
		}
		else
		{
			PauseTint = ImVec4(1, 1, 1, 1);
		}
		for (int i = 0; i < 3; i++)
		{
			ImGui::PopStyleColor();
		}
		ImGui::PopFont();
		ImGui::End();
	}
};

class PlotControl {
public:
	// ImGui State variables
	bool Cursor1Check = false;
	bool Cursor2Check = false;
	bool SignalPropertiesCheck = false;
	bool PlotPropertiesCheck = false;
	int TriggerSourceComboCurrentItem = 0;
	int ExportComboCurrentItem = 0;
	float LevelSliderVal = 0;
	bool ExportButtonPressUp = false;
	// ImGui const data
	ImGuiIO& io = ImGui::GetIO();
	ImFont* font = io.Fonts->AddFontFromFileTTF("fonts/roboto/Roboto-Regular.ttf", 24.0f);
	ImFont* fontSmall = io.Fonts->AddFontFromFileTTF("fonts/roboto/Roboto-Regular.ttf", 18.0f);
	ImFont* fontTiny = io.Fonts->AddFontFromFileTTF("fonts/roboto/Roboto-Regular.ttf", 16.0f);
	const char* TriggerSourceComboList[4] = { "CH1 (Rising)","CH1 (Falling)","CH2 (Rising)","CH2 (Falling)" };
	const char* ExportComboList[6] = { "clipboard","png","jpg","gif","pdf","csv"};
	// Layout Parameters
	ImVec2 Pos;
	ImVec2 Size = ImVec2(279, 258);
	ImVec2 ContentPos = ImVec2(10, 42); // relative to Pos
	ImVec2 RowColumnSize = ImVec2(180, 36);
	float TriggerSourceComboWidth = 110.0f;
	ImVec2 TriggerSourcePos = ImVec2(75, 0); // relative to ContentPos
	float LevelSliderWidth = 75.0f;
	ImVec2 LevelSliderPos = ImVec2(189, 0);
	ImVec2 ExportButtonPos = ImVec2(10, 180);
	ImVec2 ExportButtonSize = ImVec2(100, 25);
	ImVec2 ToPos = ImVec2(120, 182);
	float ExportComboWidth = 100;
	ImVec2 ExportComboPos = ImVec2(150, 182);
	const char* Name;
	PlotControl(const char* name, ImVec2 pos = ImVec2(0,0)) {
		Pos = pos;
		Name = name;
	}
	void Draw()
	{
		ImGui::SetNextWindowSize(Size);
		ImGui::SetNextWindowPos(Pos);
		ImGui::PushFont(font);
		ImGui::Begin(Name, NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		ImGui::SetCursorPos(ContentPos);
		ImGui::Text("Trigger");
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(0, 1));
		ImGui::Text("Cursor 1");
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(0, 2));
		ImGui::Text("Cursor 2");
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(0, 3));
		ImGui::Text("Signal Properties");
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(0, 4));
		ImGui::Text("Plot Properties");
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(1, 1));
		ImGui::Checkbox(std::string((Cursor1Check ? "ON" : "OFF") + std::string("##Cursor1")).c_str(), &Cursor1Check);
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(1, 2));
		ImGui::Checkbox(std::string((Cursor2Check ? "ON" : "OFF") + std::string("##Cursor2")).c_str(), &Cursor2Check);
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(1, 3));
		ImGui::Checkbox(std::string((SignalPropertiesCheck ? "ON" : "OFF") + std::string("##SignalProperties")).c_str(), &SignalPropertiesCheck);
		ImGui::SetCursorPos(ContentPos + RowColumnSize * ImVec2(1, 4));
		ImGui::Checkbox(std::string((PlotPropertiesCheck ? "ON" : "OFF") + std::string("##PlotProperties")).c_str(), &PlotPropertiesCheck);
		ImGui::SetCursorPos(ContentPos+TriggerSourcePos);
		ImGui::SetNextItemWidth(TriggerSourceComboWidth);
		ImGui::PushFont(fontTiny);
		ImGui::Combo("##TriggerSource", &TriggerSourceComboCurrentItem, TriggerSourceComboList, IM_ARRAYSIZE(TriggerSourceComboList));
		ImGui::SetCursorPos(ContentPos + LevelSliderPos);
		ImGui::SetNextItemWidth(LevelSliderWidth);
		ImGui::SliderFloat("##Offset", &LevelSliderVal, 0, 20);
		ImGui::PushFont(font);
		ImGui::SetCursorPos(ContentPos + ExportButtonPos);
		ExportButtonPressUp = ImGui::Button("Export", ExportButtonSize);
		ImGui::SetCursorPos(ContentPos + ToPos);
		ImGui::Text("to");
		ImGui::SetCursorPos(ContentPos + ExportComboPos);
		ImGui::SetNextItemWidth(ExportComboWidth);
		ImGui::PushFont(fontSmall);
		ImGui::Combo("##Export", &ExportComboCurrentItem, ExportComboList, IM_ARRAYSIZE(ExportComboList));
		ImGui::PopFont();
		ImGui::End();
	}
};

class MultimeterControl {
public:
	// ImGui State variables
	float Number = 0.0f;
	int UnitsVoltsComboCurrentItem = 0;
	int UnitsAmpsComboCurrentItem = 0;
	int UnitsOhmsComboCurrentItem = 2;
	// ImGui const data
	ImGuiIO& io = ImGui::GetIO();
	ImFont* font = io.Fonts->AddFontFromFileTTF("fonts/roboto/Roboto-Regular.ttf", 24.0f);
	ImFont* fontSmall = io.Fonts->AddFontFromFileTTF("fonts/roboto/Roboto-Regular.ttf", 18.0f);
	ImFont* fontTiny = io.Fonts->AddFontFromFileTTF("fonts/roboto/Roboto-Regular.ttf", 16.0f);
	ImFont* fontDigital = io.Fonts->AddFontFromFileTTF("fonts/digital-7-font/Digital7-rg1mL.ttf", 90.0f);
	const char* UnitsVoltsComboList[2] = { "V","mV" };
	const char* UnitsAmpsComboList[3] = { "A","mA","\u03BCA" };
	const char* UnitsOhmsComboList[5] = { "M\u03A9","k\u03A9" ,"\u03A9" ,"m\u03A9" ,"\u03BC\u03A9" };
	// Layout Parameters
	ImVec2 Pos;
	ImVec2 Size = ImVec2(549,269);
	ImVec2 NumberPos = ImVec2(180,90);
	ImVec2 UnitsComboPos = ImVec2(250, 130);
	const char* Name;
	MultimeterControl(const char* name, ImVec2 pos = ImVec2(0, 0))
	{
		Pos = pos;
		Name = name;
	}
	void Draw()
	{
		ImGui::SetNextWindowSize(Size);
		ImGui::SetNextWindowPos(Pos);
		ImGui::PushFont(font);
		ImGui::Begin(Name, NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		ImGui::SetCursorPos(NumberPos);
		ImGui::PushFont(fontDigital);
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << Number;
		std::string Number_string = stream.str();
		ImGui::Text(Number_string.c_str());
		ImGui::PushFont(font);
		ImGui::SetCursorPos(UnitsComboPos);
		ImGui::PopFont();
		ImGui::End();
	}
};

int main()
{
	// Standard GLFW Initialization
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(1440, 1022, "Labrador", NULL, NULL);
	glfwMakeContextCurrent(window);
	// Initialize OpenGL loader library glad
	gladLoadGL();
	glViewport(0, 0, 1440, 1022);

	

	

	// Init ImGui Stuff
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsClassic();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	

	// Application stuff
	OscillatorControl osc1("Oscilloscope 1 (OSC1)",ImVec2(10,747));
	OscillatorControl osc2("Oscilloscope 2 (OSC2)",ImVec2(299, 747));
	PlotControl pltctrl("Plot", ImVec2(585, 747));
	MultimeterControl mmctrl("Multimeter", ImVec2(879, 736));

	


	// main while loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Init New Frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// Draw Application objects
		osc1.Draw();
		osc2.Draw();
		pltctrl.Draw();
		mmctrl.Draw();
		

		// Render
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}