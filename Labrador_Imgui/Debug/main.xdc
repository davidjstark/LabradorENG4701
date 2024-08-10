<?xml version="1.0"?><doc>
<members>
<member name="T:ControlWidget" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="4">
<summary>
Abstract class that draws child that can be populated by a control widget
</summary>
</member>
<member name="M:ControlWidget.#ctor(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,ImVec2,System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="10">
<summary>
Constructor
</summary>
<param name="label">Name of controller</param>
<param name="size">Child window size</param>
<param name="borderColor">Accent colour</param>
</member>
<member name="M:ControlWidget.setSize(ImVec2)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="23">
<summary>
Update size of child window
</summary>
<param name="new_size">New size</param>
</member>
<member name="M:ControlWidget.Render" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="32">
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
<member name="M:PSUControl.renderHelp" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\PSUControl.hpp" line="26">
<summary>
Render help message in popup window
</summary>
</member>
<member name="M:PSUControl.controlLab" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\PSUControl.hpp" line="34">
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
<member name="M:OSCControl.renderHelp" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\OSCControl.hpp" line="23">
<summary>
Render help message in popup window
</summary>
</member>
<member name="M:OSCControl.controlLab" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\OSCControl.hpp" line="31">
<summary>
Control sampling settings on labrador board
</summary>
</member>
<member name="M:ToggleSwitch(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Boolean*,System.UInt32)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\UIComponents.hpp" line="8">
<summary>
Adapted from https://github.com/ocornut/imgui/issues/1537#issuecomment-355562097
</summary>
<param name="id"></param>
<param name="state"></param>
<param name="accentColour"></param>
</member>
<member name="M:DropDown(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte*!System.Runtime.CompilerServices.IsConst*,System.Int32*,System.Int32)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\UIComponents.hpp" line="77">
<summary>
Generic dropdown for list of strings
</summary>
<param name="id"></param>
<param name="options"></param>
<param name="active"></param>
<param name="size"></param>
<returns></returns>
</member>
<member name="M:renderSliderwUnits(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single*,System.Single,System.Single,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,Unit*!System.Runtime.CompilerServices.IsConst*,System.Int32*)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\UIComponents.hpp" line="110">
<summary>
Generic Slider with Units
</summary>
<param name="type">Type of slider</param>
<param name="result">Resulting float</param>
<param name="min">Lower bound</param>
<param name="max">Upper bound</param>
<param name="prompt">Prompt/format over slider</param>
<param name="units">List of unit objects</param>
<param name="unit_idx">Index of selected unit</param>
</member>
<member name="M:GenericSignal.renderControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SignalType.hpp" line="21">
<summary>
Generic UI elements for Signal Control
</summary>
</member>
<member name="M:GenericSignal.controlLab(System.Int32)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SignalType.hpp" line="68">
<summary>
Set the Signal Generator on the labrador board.
</summary>
</member>
<member name="T:SineSignal" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SignalType.hpp" line="85">
<summary>Sine Signal Generator Widget
</summary>
</member>
<member name="M:SineSignal.controlLab(System.Int32)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SignalType.hpp" line="133">
<summary>
Set the Signal Generator on the labrador board.
</summary>
</member>
<member name="T:SquareSignal" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SignalType.hpp" line="144">
<summary>Square Signal Generator Widget
</summary>
</member>
<member name="M:SquareSignal.controlLab(System.Int32)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SignalType.hpp" line="194">
<summary>
Set the Signal Generator on the labrador board.
</summary>
</member>
<member name="T:SawtoothSignal" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SignalType.hpp" line="204">
<summary>Sawtooth Signal Generator Widget
</summary>
</member>
<member name="M:SawtoothSignal.controlLab(System.Int32)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SignalType.hpp" line="253">
<summary>
Set the Signal Generator on the labrador board.
</summary>
</member>
<member name="T:TriangleSignal" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SignalType.hpp" line="263">
<summary>Triangle Signal Generator Widget
</summary>
</member>
<member name="M:TriangleSignal.controlLab(System.Int32)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SignalType.hpp" line="312">
<summary>
Set the Signal Generator on the labrador board.
</summary>
</member>
<member name="T:SGControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SGControl.hpp" line="8">
<summary>Signal Generator Widget
</summary>
</member>
<member name="M:SGControl.renderControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SGControl.hpp" line="37">
<summary> 
Render UI elements for Signal Generator
</summary>
</member>
<member name="M:SGControl.renderHelp" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SGControl.hpp" line="60">
<summary>
Render help message in popup window
</summary>
</member>
<member name="M:SGControl.controlLab" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\SGControl.hpp" line="71">
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
<member name="M:MultimeterControl.renderHelp" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\MultimeterControl.hpp" line="23">
<summary>
Render help message in popup window
</summary>
</member>
<member name="M:MultimeterControl.controlLab" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\MultimeterControl.hpp" line="31">
<summary>
Read multimeter from labrador board
</summary>
</member>
</members>
</doc>