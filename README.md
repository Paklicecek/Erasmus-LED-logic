# EU Erasmus - Smart Charging Tables

This project is a collaborative Erasmus effort between four schools. Together, we built four interactive "smart tables" that provide practical device charging while featuring a dynamic light show built into the 12 stars of the EU flag.

## What is Inside?
* **The Brain:** An ESP32 Microcontroller that handles all the logic, timing, and power management.
* **The EU Stars:** 12 LEDs positioned exactly under the 12 stars of the EU flag on the tabletop.
* **Charging Stations:** Integrated wired and wireless charging modules for phones and laptops.
* **Energy Saver Button:** A dedicated hardware push-button to control the LEDS state.

## How and Why it Works
* **Dynamic Visuals:** Instead of static lights, the ESP32 uses a randomizer engine to seamlessly transition between 5 different animations (Fade, Full Circle, Snake, Fade Away, and Odd/Even). This ensures that it is not just frantically blinking all the time.
* **Instant Energy Saving:** To keep the tables energy efficient, we programmed a Deep Sleep mode. Pressing the button instantly kills the lights and shuts down the ESP32's main processor to save power when the table isn't being used. 
* **Smart Responsiveness:** Microcontrollers usually struggle to register button presses while running complex light animations. We wrote a custom `smartDelay` function that checks the power button every 10 milliseconds, ensuring the table reacts instantly to the user without any lag.
