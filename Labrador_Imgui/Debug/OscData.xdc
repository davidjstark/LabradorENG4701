<?xml version="1.0"?><doc>
<members>
<member name="M:librador_set_device_mode(System.Int32)" decl="true" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Librador_API\___librador\librador_shared_library\librador.h" line="28">
As above, a1 and a2
</member>
<member name="T:ControlWidget" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="5">
<summary>
Abstract class that draws child that can be populated by a control widget
</summary>
</member>
<member name="M:ControlWidget.#ctor(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;,ImVec2,System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="11">
<summary>
Constructor
</summary>
<param name="label">Name of controller</param>
<param name="size">Child window size</param>
<param name="borderColor">Accent colour</param>
</member>
<member name="M:ControlWidget.setSize(ImVec2)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="24">
<summary>
Update size of child window
</summary>
<param name="new_size">New size</param>
</member>
<member name="M:ControlWidget.Render" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\ControlWidget.hpp" line="33">
<summary>
Generic function to render control widget with correct style
</summary>
</member>
<member name="T:Unit" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\util.h" line="10">
<summary>
Handles conversion of unit and labelling.
</summary>
</member>
<member name="M:ToggleSwitch(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Boolean*,System.UInt32)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\UIComponents.hpp" line="64">
<summary>
Adapted from https://github.com/ocornut/imgui/issues/1537#issuecomment-355562097
</summary>
<param name="id"></param>
<param name="state"></param>
<param name="accentColour"></param>
</member>
<member name="M:DropDown(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte*!System.Runtime.CompilerServices.IsConst*,System.Int32*,System.Int32)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\UIComponents.hpp" line="140">
<summary>
Generic dropdown for list of strings
</summary>
<param name="id"></param>
<param name="options"></param>
<param name="active"></param>
<param name="size"></param>
<returns></returns>
</member>
<member name="M:renderSliderwUnits(std.basic_string&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte,std.char_traits{System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte},std.allocator&lt;System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte&gt;&gt;!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single*,System.Single,System.Single,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,Unit*!System.Runtime.CompilerServices.IsConst*,System.Int32*)" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\UIComponents.hpp" line="173">
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
<member name="T:OSCControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\OSCControl.hpp" line="8">
<summary>Oscilloscope Control Widget
</summary>
</member>
<member name="M:OSCControl.renderControl" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\OSCControl.hpp" line="28">
<summary> 
Render UI elements for oscilloscope control
</summary>
</member>
<member name="M:OSCControl.renderHelp" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\OSCControl.hpp" line="50">
<summary>
Render help message in popup window
</summary>
</member>
<member name="M:OSCControl.controlLab" decl="false" source="C:\University_offline\ENG4701\Repo\LabradorENG4701\Labrador_Imgui\src\OSCControl.hpp" line="62">
<summary>
Control sampling settings on labrador board
</summary>
</member>
</members>
</doc>