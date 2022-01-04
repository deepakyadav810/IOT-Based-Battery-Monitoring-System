# IOT-Based-Battery-Monitoring-System

Idea -  
In this project we propose a system where we provide internet connection using a series of network devices and create a common resource sharing platform for less internet consumption and that can be extended by the help of mobile networking vehicles to expand existing connections for remote areas of the village. 

The whole system is divided into 3 parts 
Central Server : This will be the server connected to nearby data stationand would be the core of this system
Local Server : This server will be connected to the centralise server as it can't provide connection for the whole village
Vehicles : These are the vehicles that are going to have the whole networking module embedded with a GPS sensor. 

In the Vehicles GPS server and the network module are connected to the car battery. Which means all the power consumption for providing internet through the network module and tracking the car through gps will be fulfilled by the car's battery. This may affect all other internal devices such as speedometer, LEDs, touch functions, ACs modules, etc to dysfunction or stop working. Hence this gives a drawback to the network module.
In order to solve this battery problem we have implemented an IOT based battery monitoring system which will tell the car user about the battery status as well as to the local server. Even if due to some technical error like user and local server not getting notified or human misstep it will automatically disable the network 
module to prevent dysfunctions.

Using Arduino we will collect the data from the battery and transmit it to the user and the local server. This idea can also be implemented in ‘raspberry pi’, but due to online implementation of the project we are using Arduino. The major components used are :
Arduino Uno R3 
LCD 16 X 2
Breadboard
Multimeter
Potentiometer
9V/Car Battery

