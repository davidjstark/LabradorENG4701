# User Documentation

### Power Supply Unit (PSU)

#### Controls
- **Voltage control**: Adjusts the output voltage level
#### Specifications
- **Voltage Range**: 4.5 V - 12.0 V
- **Maximum Power Supply**: 0.75 W

### Signal Generator

#### Controls
- **Power button**: Turns the signal generator on or off.
- **Voltage control**: Adjusts the output voltage level.
- **Waveform selection**: Chooses the type of waveform output.
- **Frequency slider**: Sets the frequency of the signal.
- **Amplitude slider**: Modifies the amplitude of the waveform.
- **Phase slider**: Shifts the waveform in the time domain.
- **Offset slider**: Shifts the waveform's voltage level.

#### Specifications
- **Voltage Range**: 0.15 V - 9.5 V
- **Maximum Current**: 10 mA
- **Sample Rate**: 1 Msps

### Plot Settings

#### Main Controls

- **Run / Stop**: Starts or stops the signal acquisition and display.
- **Single**: Captures a single trigger event and then stops.
- **Auto**: Automatically adjusts settings for optimal waveform display.
- **Capture**: Export a png image of the current waveform.

#### Channels

For each channel (Channel 1 and Channel 2):

- **Display**: Toggles visibility of the channel (ON/OFF)
- **Time Scale**: Adjusts horizontal time per division (in ms)
- **Voltage Scale**: Sets vertical voltage per division (in ms)
- **Offset**: Shifts the waveform vertically (in ms)

**Equalise**: When checked, synchronizes settings across both channels

#### General Settings

- **Cursor 1 & 2**: Enables/disables measurement cursors
- **Trigger**:
  - Aligns a 'trigger' event with the left most point in the plot window (e.g. OSC1 Rising)
  - **Level**: Sets the voltage level for triggering (in mV)
- **Signal Properties**: Shows detailed signal information when ON
- **Plot Properties**: Displays graph details when ON
- **Capture to**: Selects destination for captured data (e.g. Clipboard)

#### Specifications

- **Sample Rate** 750 ksps
- **Input Voltage Range** -20 V to +20 V

### Plot Window

#### Controls

- **Panning**: Click and drag to pan anywhere on the plot. Click and drag on any axis to pan in one direction.
- **Zooming**: Scroll to zoom anywhere on the plot. Scroll on any axis to zoom on solely on that axis.


#### Measurments

- **Cursors**:
  - Activate cursors in Plot Settings or by right clicking inside the plot window and selecting desired cursors
  - Measurements between the two cursors are displayed below the plot when they are both activated
  - Use these to measure the frequency/amplitude of displayed waveforms
- **Signal Properties**
  - Signal properties are calculated based on the plot window data
  - dT values represent an average time between trigger events (see more info in Plot Settings)
  - dV values represent the difference between Vmin and Vmax

### End