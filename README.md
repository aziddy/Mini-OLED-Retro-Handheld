# Mini-OLED-Retro-Handheld
I have no idea why built this, but I love video games and building things
<br>

<p align="center" style="vertical-align: top; position: relative" >
  
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/ezgif-7-e783d192cd6b.gif?raw=true" width="400"/>  
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/IMG_20200119_235728.jpg?raw=true" width="399"/>  
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/IMG_20200120_173605.jpg?raw=true" width="400"/>  
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/ezgif-7-f63e35a263ec.gif?raw=true" width="400"/>  




</p>

<br>
<br>

## Component List

* Some PCB Power Switch
* Adafruit Feather 328P
* 4 Tactile Switches
* Double Sided Protoboard
* Some random LiPo battery I ripped from some portable speaker
* OLED Display 128x64 Pixel I2C, 0.96 inch, SSD1306 
* 3D printed parts

<p align="center" style="vertical-align: top; position: relative" >
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/parts/1988_d9ab1bc4-37ee-4b47-8687-ac5aa7976e0a2.jpg?raw=true" width="300"/>
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/parts/6-6-6-H-4legs-tact-switch.jpg_350x350.jpg?raw=true" width="300"/>
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/parts/c3422_large_miniature_pcb_mount_slide_switch.jpg?raw=true" width="300"/>
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/parts/thumb.jpg?raw=true" width="300"/>
</p>




<br>

## 3D Design
<p style="vertical-align: top; position: relative" >
Took inspiration from the Nintendo Switch Joy-Con Grip. 
  
Sepearted into two parts **PCB mount** and **Grip** (original grip: https://www.thingiverse.com/thing:2774595).
</p>
<br>
<br>
<p align="center" style="vertical-align: top; position: relative" >
  
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/3dgif.gif?raw=true" width="300"/>

<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/71kFVCPfEEL._AC_SL1500_.jpg?raw=true" width="300"/>

</p>

## Wiring
<p align="center" style="vertical-align: top; position: relative" >
  
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/oled%20boy%20circuit.PNG?raw=true" width="500"/>

</p>

## Build Process

Not too crazy of a build. Measured everything to fit onto a square piece of protoboard that I dremeled.

<p align="center" style="vertical-align: top; position: relative" >
  <img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/IMG_20200117_173503.jpg?raw=true" width="500"/>    
</p>
  
  Followed by some soldering which required some wires because I didn't think too much about the protoboard really only having one double sided layer
  
<p align="center" style="vertical-align: top; position: relative" >  
  <img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/IMG_20200119_235737.jpg?raw=true" width="500"/>  
</p>
  
  The fact that all the componenets fit on one side and that they all fit perfectly makes me sooo happy
<p align="center" style="vertical-align: top; position: relative" > 
  <img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/IMG_20200119_235728.jpg?raw=true" width="500"/>  
</p>


</p>
<br>

## Programming

Instructions to install **SSD1306** and **GFX** libraries to your Arduino IDE https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples

Writing most of the code and installing the libraries was pretty straight foward. But when it comes to rendering images, ohhh boy thats abit of a hassle

You first have to convert your image to only have **two colors** *(OLED only deals with 2)* with a high enough contrast between them

Then you have to transform your image into a format that can be stored in your Arduino's flash memory easily. This site https://javl.github.io/image2cpp/ makes that process easy. You can fiddle around with the **threshold** and **image size** here

When your done messing with the image settings make sure to set the **Code output format** to ***Arduino Code***. Then copy and paste the output code to your code

The output code with the array we get has the PROGMEM keyword because we want the image array to be stored in the Arduino's Flash memory where your program resides instead of RAM, because of how little RAM most microcontrollers have

Read more about PROGMEM https://www.arduino.cc/reference/tr/language/variables/utilities/progmem/




