<?xml version="1.0"?><doc>
<members>
<member name="T:ControlWidget" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="4">
<summary>
Abstract class that draws child that can be populated by a control widget
</summary>
</member>
<member name="M:ControlWidget.#ctor(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,ImVec2,System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="10">
<summary>
Constructor
</summary>
<param name="label">Name of controller</param>
<param name="size">Child window size</param>
<param name="borderColor">Accent colour</param>
</member>
<member name="M:ControlWidget.setSize(ImVec2)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="22">
<summary>
Update size of child window
</summary>
<param name="new_size">New size</param>
</member>
<member name="M:ControlWidget.Render" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="31">
<summary>
Generic function to render control widget with correct style
</summary>
</member>
<member name="T:PSUControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\PSUControl.hpp" line="4">
<summary>Power Suppy Unit Widget
</summary>
</member>
<member name="M:PSUControl.renderControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\PSUControl.hpp" line="15">
<summary> 
Render UI elements for power supply unit
</summary>
</member>
<member name="M:PSUControl.controlLab" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\PSUControl.hpp" line="26">
<summary>
Set the Power Supply Voltage on the labrador board.
</summary>
</member>
<member name="T:OSCControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\OSCControl.hpp" line="4">
<summary>Oscilloscope Control Widget
</summary>
</member>
<member name="M:OSCControl.renderControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\OSCControl.hpp" line="15">
<summary> 
Render UI elements for oscilloscope control
</summary>
</member>
<member name="M:OSCControl.controlLab" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\OSCControl.hpp" line="23">
<summary>
Control sampling settings on labrador board
</summary>
</member>
<member name="M:ToggleSwitch(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Boolean*,System.UInt32)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\UIComponents.hpp" line="3">
<summary>
Adapted from https://github.com/ocornut/imgui/issues/1537#issuecomment-355562097
</summary>
<param name="id"></param>
<param name="state"></param>
<param name="accentColour"></param>
</member>
<member name="T:SGControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SGControl.hpp" line="7">
<summary>Signal Generator Widget
</summary>
</member>
<member name="M:SGControl.renderControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SGControl.hpp" line="21">
<summary> 
Render UI elements for Signal Generator
</summary>
</member>
<member name="M:SGControl.controlLab" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SGControl.hpp" line="109">
<summary>
Set the Signal Generator on the labrador board.
</summary>
</member>
<member name="T:MultimeterControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\MultimeterControl.hpp" line="4">
<summary>Multimeter Widget
</summary>
</member>
<member name="M:MultimeterControl.renderControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\MultimeterControl.hpp" line="15">
<summary> 
Render UI elements for multimeter
</summary>
</member>
<member name="M:MultimeterControl.controlLab" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\MultimeterControl.hpp" line="23">
<summary>
Read multimeter from labrador board
</summary>
</member>
</members>
</doc>