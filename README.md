SmartServoFramework 0.9
=======================

## Introduction

This is a C++ multiplatform framework used to drive "smart servos" device like Dynamixel or HerkuleX actuators.
Linux, Mac OS and Windows operating systems are supported. All you need to begin moving stuff around is at least one servo, a serial port adapter and a C++/11 compiler!

> Dynamixel devices from [Robotis](http://www.robotis.com/) and HerkuleX devices from [Dongbu Robot](http://www.dongburobot.com/) are high-performance networked actuators for robots available in wide range of sizes and strengths.  
> They provide adjustable torque, speed, and response, various feedback like position, load, voltage and temperature...

## Prerequisite

### Compiler

You need a C++/11 capable compiler. That includes:

* GCC >= 4.6  
* Clang >= 3.0  
* XCode >= 4.6  
* MSVC >= 2012  

### Serial link

This framework can use any combination of RS-232 ports, USB to TTL adapters, RS-485 adapters... but the servo devices needs the right link!

First make sure that you can access your serial port:
If you are running Windows you will need to install the [FTDI driver for the USB2Dynamixel device](http://www.robotis.com/xe/download_en/646927) or the official [FTDI driver](http://www.ftdichip.com/FTDrivers.htm).
You may also need other drivers depending on your adapter (like the [CP210x](http://www.silabs.com/products/mcu/pages/usbtouartbridgevcpdrivers.aspx)).
If you are running Linux, your user account will need to be in the _'dialout'_ and/or _'uucp'_ groups to access serial port:
> $ sudo useradd -G dialout,uucp $USER

Latency over the serial port will limit the number of instructions you can send each second even more than bandwidth limitations.
To minimize traffic on your serial port (if using FTDI chips):  
- Make sure you have set the "Status Return Level" / "Ack Policy" to '1' to minimize the number of status packets (if you do not need them), or even '2' to disable them all.  
- If you are using Dynamixel devices, you may want to reduce the "Return Delay Time" value to a minimum, from the default of '250' to something like '10'.  
- You can also use [these tips](https://projectgus.com/2011/10/notes-on-ftdi-latency-with-arduino/) to reduce latency on serial ports!  

#### Serial link (Dynamixel servos)

* USB2Dynamixel: Official device that can manage regular RS232, RS485 and TTL communications.  
* USB2AX: Unofficial device designed to manage TTL communication only.  
* "Home made" TTL half-duplex device: (LINK?)  

> Note: Regular "full-duplex TTL" converters will NOT do the trick for "half-duplex TTL" Dynamixel servos (AX series, MX "T" series, XL-320).

#### Serial link (HerkuleX servos)

You need a serial port with a "regular" TTL converter to use HerkuleX devices.

## Framework

This framework can be used with any Dynamixel or HerkuleX devices. Please note that the Dynamixel PRO serie is not supported, as no test devices are available to us.

* **Simple API:** Use this mode to get or set a value to a servo by sending a simple instruction and waiting for the answer.  
* **Controller API:** Setup a controller and attach servo instances to it. Manipulate servo objects and let the controller sync its values with the actual servo hardware in a background thread with a fixed frequency.  

### Documentation

You can dynamically generate an API documentation from the source code using Doxygen. The documentation will be generated inside the "doc" directory.
If you are running a Linux system you can easily generate the documentation from a terminal:
> $ cd SmartServoFramework/  
> $ doxygen Doxyfile  

### Example softwares

Various examples programs are available:

* ex_basic_test: Very simple example that move the servo at ID 0 with the 'UP' and 'DOWN' keys.  
* ex_simple: Control four servos with your keyboard using the 'Simple API'.  
* ex_simple_threaded: Control four servos with your keyboard using the 'Simple API', with servos actions and keyboard handled in two separate threads.  
* ex_controller: Control four servos with your keyboard using the 'Controller API'.  
* ex_sinus_control: Control a servo with sinusoid curve for both speed and position.  
* ex_advance_scanner: Scan serial ports for Dynamixel servos, for all IDs and all (but configurable) serial port speeds.  

### GUI software

SmartServoGui is a fully featured Qt GUI application that helps you discover devices on available serial links, get an overview of all of their registers, and easily changes their settings!

## Licensing

SmartServoFramework is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.
[Consult the licence on the FSF website](http://www.gnu.org/licenses/lgpl-3.0.txt).

Copyright (c) 2014, INRIA, All rights reserved.  
Emeric Grange <emeric.grange@gmail.com>  
Dominique Vaufreydaz <dominique.vaufreydaz@inria.fr>  