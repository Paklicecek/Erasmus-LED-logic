# Erasmus LED Logic

ESP32 code for smart charging tables built during an EU Erasmus+ project with four partner schools.

Each table has wired/wireless phone charging and 12 LEDs placed under the stars of the EU flag on the tabletop.

## How it works
- Cycles randomly through 5 light animations (fade, full circle, snake, fade away, odd/even) so the pattern doesn't get repetitive.
- Uses a custom `smartDelay` loop that checks the hardware push-button every 10ms so you don't have to wait for an animation frame to finish before the button responds.
- Pressing the button turns off the LEDs and puts the ESP32 into deep sleep to save power.
