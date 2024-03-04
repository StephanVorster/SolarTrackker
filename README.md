# SolarTrackker
During the 2020 lockdowns, I took on a fun project to design and prototype a solar tracker. This project aimed to optimize the efficiency of solar panels by ensuring they are always facing the sun.

https://github.com/StephanVorster/SolarTrackker/assets/48912531/4927339c-f8eb-4e79-99d9-341e807ec8dd


## Overview

The solar tracker utilises a motor to orient the solar panels in the direction of the brightest light source. The control system relies on a photo transistor-based light sensor system to detect the position of the sun and adjust the orientation of the panels accordingly. An Arduino Uno microcontroller serves as the brain of the system, coordinating the movements of the stepper motor based on the input from the light sensors.
## Features

- Light tracking: The system tracks the sun's position, ensuring maximum exposure to sunlight throughout the day.
- Precise control: The Stepper motor provides precise control over the orientation of the solar panels, allowing for fine adjustments to optimize energy generation.
- Light sensor feedback: The photo transistor-based light sensor system continuously monitors the intensity of sunlight and adjusts the position of the panels accordingly.
- Arduino-based control: The Arduino Uno microcontroller serves as the control unit, executing the tracking algorithms and coordinating the movements of the stepper motor.

## Components Used

- Arduino Uno (or compatible microcontroller)
- Stepper motor (28BYJ-48)
- Photo transistor-based light sensor system
- 2.5V Solar panels
- Supporting hardware (mounting brackets, gears, etc.)
- Transistors for motor driver developed from first principles 

Discaimer: this project is a for fun project and not meant to be used in a production environment in it's current form.
