# SolarTrackker
During the 2020 lockdowns, I took on a fun project to design and prototype a solar tracker. This project aimed to optimize the efficiency of solar panels by ensuring they are always facing the sun.

https://github.com/StephanVorster/SolarTrackker/assets/48912531/4927339c-f8eb-4e79-99d9-341e807ec8dd


## Overview

The solar tracker utilizes a motor to orient the solar panels in the direction of the brightest light source. The control system relies on a photo transistor-based light sensor system to detect the position of the sun and adjust the orientation of the panels accordingly. An Arduino Uno microcontroller serves as the brain of the system, coordinating the movements of the stepper motor based on the input from the light sensors.

## Features

- Light tracking: The system tracks the sun's position in both the azimuth and elevation directions, ensuring maximum exposure to sunlight throughout the day.
- Precise control: Stepper motors provide precise control over the orientation of the solar panels, allowing for fine adjustments to optimize energy generation.
- Light sensor feedback: The photo transistor-based light sensor system continuously monitors the intensity of sunlight and adjusts the position of the panels accordingly.
- Arduino-based control: The Arduino Uno microcontroller serves as the control unit, executing the tracking algorithms and coordinating the movements of the stepper motors.

## Components Used

- Arduino Uno (or compatible microcontroller)
- Two stepper motors
- Photo transistor-based light sensor system
- Solar panels
- Supporting hardware (mounting brackets, gears, etc.)
- Basic electronic components (wires, resistors, etc.)

Discaimer: this project is a for fun project and not meant to be used in a production environment in it's current form.
