# A Home Made Gaming Device
We are going to make a handheld gaming device with limited parts.
This is the final project for Electronic Club 2023 Spring.

# Quick Start
* Follow the video to put everything into the box, connect the wire
* Download the latest release and extract it
https://github.com/HXLVElectronicClub/2023_Spring_GamingHandheld/releases/latest
* Upload to board

# Follow the video to make it
<a href="http://www.youtube.com/watch?feature=player_embedded&v=ZbSbYy5ZNGo" target="_blank">
 <img src="http://img.youtube.com/vi/ZbSbYy5ZNGo/0.jpg" alt="Watch the video" border="10" />
</a>

## BOM List:
* 32x32 LED matrix display:
https://www.amazon.com/dp/B09Y399S84

* Joystick (different version may not fit in the box)
https://www.amazon.com/dp/B07YZT5NSW

* Button
https://www.amazon.com/dp/B01E38OS7K

* ESP32 Board
https://www.amazon.com/dp/B09GK74F7N
This one is not the same as on the video, but should be similiar enough

* Step down voltage converter
https://www.amazon.com/dp/B00LODGDYE

* Power Switch
https://www.amazon.com/dp/B09R43HCY3

* 9V battery connecter
https://www.amazon.com/dp/B079HYPCZD

* Prototype board and wires
The prototype board is used to solder connector, the switch and the voltage converter

  https://www.amazon.com/dp/B072Z7Y19F
  
  https://www.amazon.com/dp/B07GD1ZCHQ
  
* 3D print part

## Wire Connection
* Joystick

SW  ---    26

VRY ---    25

VRX ---    33

5V  ---    32

GND ---    27


* Display

LED1_CLK  ---   4

LED1_CS   ---   16

LED1_DIN  ---   17

LED2_CLK  ---   21

LED2_CS   ---   22

LED2_DIN  ---   23

VCC/GND connect to power board output

* Button

2 pins connect to 18, 19
