See BACKENDS and EXAMPLES files in the docs/ folder, or on the web at: https://github.com/ocornut/imgui/tree/master/docs

Backends = Helper code to facilitate integration with platforms/graphics api (used by Examples + should be used by your app).
Examples = Standalone applications showcasing integration with platforms/graphics api.

Some Examples have extra README files in their respective directory, please check them too!

Once Dear ImGui is running (in either examples or your own application/game/engine),
run and refer to ImGui::ShowDemoWindow() in imgui_demo.cpp for the end-user API.

---- Labrador ----
- Have attached libusbk functionality to ImGui example
- Has been setup in Visual Studio 2019, no need for any Qt
- Labrador board must be calibrated and setup with official Labrador software
- PSU can be set between 4.5 and 6.0 V via slider (tested with separate multimeter)
- Looks like signal generator is much more complex than PSU so this may take longer to implement
- It seems possible to copy and paste relevant functions from Labrador repo, would need to remove all Qt signals and slots and redesign something that could operate in the ImGui 'gameloop'
