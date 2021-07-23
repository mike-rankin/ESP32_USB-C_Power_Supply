# ESP32_USB-C_Power_Supply
ESP32 based USB C Programmable Power Supply
The idea for this project came to me when I discovered that usb-c parts exist that communicate to parts inside the wall chargers. These parts ask the charger to deliver the voltage and current values if possible. Small chargers cannot deliver as much power as the larger ones. The small navigation button allows the user to select values with the top button as a power switch.

![IMG_0867](https://user-images.githubusercontent.com/4991664/126777846-82abcd4a-c4ef-4dae-8cf0-9f8feef768e5.jpg)
![Hardware](https://user-images.githubusercontent.com/4991664/122986609-08aba380-d376-11eb-9f85-b85096b66ec9.png)

To upload an Arduino sketch to the board it is connected to a pc using a USB-C cable but the output is only ever +5V. When the board is plugged into a dedicated usb-c charger like the 60 watt apple one that I use, multiple voltages and current options are available. Text on the back of your charger will let you know what values are available.

![wall_charger](https://user-images.githubusercontent.com/4991664/126163268-4a2f0e71-c4ee-4a5f-9668-6173583e491f.png)

A +5V LDO with a maximum input of 36V provides power to the CP2104N USB-C interface chip. Current comsumption is so low for this part that and LDO will not get warm.

![5v](https://user-images.githubusercontent.com/4991664/126161071-a9722e82-cba1-44db-887f-395315d07b23.png)

Because the ESP32 current draw a few hundred milliamps, an earlier revision using an LCD was too hot when +15v and +20V was selected. (power=voltage x current) A small switching buck power supply with a maximum input of +40V now runs cool.

![3_3v](https://user-images.githubusercontent.com/4991664/126161122-873ebbfb-ac19-448a-b2a5-fcb4fcdd7969.png)

Measuring current draw at every voltage would be ideal so I've chosen the INA199 because at this time it is the only component that I can find in stock. Right now it's performance not good si I will try and find something better for the next revision.

![INA](https://user-images.githubusercontent.com/4991664/126161163-176d4ea4-d693-4e62-bd2e-30635613d8ff.png)




