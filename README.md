# Flicker Lamp

## About
Filcker lamp is a friendly light source that is not meant to light up a room, necessarily, but to respond to the environment and most of all, your presence.
The flicker lamp has two main functionalities
1. It flickers based on your movement 
2. It tracks the change in light in your environment and draws corresponding circles on your computer screen

## The software component of Flicker Lamp
The Flicker Lamp is controlled by the arduino program, esposc.ino.
The arduino program plays two roles:
1. It powers the six LED's in the Flicker Lamp. The basic state of the LED's are set to HIGH and then turns LOW when there is a change of light in the environment. 
2. It sends the light value in the environmnet through UDP messages to whichever device is connected to the same network. 

The circle graphics are controlled by the processing program, udp_led.pde
The processing program takes the light value received by UDP and draws two corresponding circles, whose sizes are determined by the light value modded by 2000 and 1000, respectively. 

There is also a python program, UDP_Rec.py that I used to check whether the UDP messages were being sent.
