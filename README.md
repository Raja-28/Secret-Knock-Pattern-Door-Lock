## Secret-Knock-Pattern-Door-Lock

## Overview

This project implements a door lock system that unlocks only when a secret knock pattern is correctly detected. Using an Arduino Nano/Uno, a relay module, a solenoid lock, and other components, this project detects knocks via a sensor or analog input and compares them to a predefined knock sequence. If the correct knock sequence is detected, the relay unlocks the door.

## Components Used
- **Arduino Nano/Uno**
- **5V Relay Module**
- **Solenoid Lock**
- **Speaker**
- **LED**
- **Resistors**: 220Ω, 10kΩ, 1MΩ
- **Push Button**
- **Breadboard**
- **Jumper Wires**

## Wiring Instructions

### Solenoid Lock (Relay)
- **Relay IN** -> Pin 7 on Arduino
- **Relay VCC** -> 5V
- **Relay GND** -> GND
- **NO (Normally Open)** -> One end of the solenoid lock
- **Other solenoid lock wire** -> 5V

### Push Button
- **One pin of the button** -> Pin 2
- **Other pin** -> GND

### LED
- **Anode** -> Pin 13
- **Cathode** -> 220Ω resistor -> GND

### Speaker
- **Positive Pin** -> Pin 8 on Arduino
- **Negative Pin** -> GND

### Knock Sensor (Piezo or Analog Input)
- **Signal Pin** -> A0 on Arduino
- **Other pin** -> GND
- **1MΩ Resistor** between signal pin and GND

## How It Works

1. **Knock Detection**: The Arduino listens for knock patterns through the knock sensor (which can be a piezo sensor connected to analog pin A0).
2. **Pattern Matching**: When knocks are detected, the Arduino compares the time interval between knocks to a predefined secret pattern.
3. **Unlocking the Door**: If the knock pattern matches the stored secret knock, the Arduino activates the relay, which controls the solenoid lock, unlocking the door. An LED lights up, and a sound is played through the speaker to indicate success.
4. **Reset**: If the knock pattern is incorrect, the door remains locked, and a failure sound is played.

## Code Explanation

- **Relay Control**: The relay module is used to control the solenoid lock, turning it on to unlock the door.
- **Knock Detection**: A sensor (connected to pin A0) detects knocks. The timing between knocks is recorded and compared with the predefined secret knock pattern.
- **Button for Listening Mode**: The push button starts the system, putting it into listening mode to detect knocks.
- **LED and Speaker Feedback**: The LED indicates success when the door unlocks, and the speaker plays different tones for success and failure.

## Setup Instructions

1. **Wiring**: Connect the components as per the wiring instructions above.
2. **Upload Code**: Upload the provided code to your Arduino board using the Arduino IDE.
3. **Test the Knock Pattern**: The default knock pattern is stored as `{100, 200, 150}` milliseconds, but this can be adjusted in the code. Try knocking the pattern to unlock the door.
4. **Customization**: Change the `secretKnock[]` array to your desired knock pattern by modifying the values.

## Customization

- **Knock Sensitivity**: Adjust the sensitivity of the knock sensor by tweaking the `tolerance` and knock detection logic.
- **Different Lock Mechanisms**: You can swap the solenoid lock with any other electronic lock or mechanism.
- **Sound and Feedback**: Customize the feedback tones or LED patterns to match the project requirements.

## Application Ideas

- **Secure Entry Systems**: Use a knock-based entry system for rooms or lockers where keys are not needed.
- **Puzzle Box**: Create interactive puzzle boxes that unlock with a secret knock sequence.
- **Escape Rooms**: Use this system as part of a puzzle for players to solve by tapping the right pattern to unlock doors.

## License

This project is licensed under the MIT License.
