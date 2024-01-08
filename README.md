# **   Heart Rate Measurment Project Made by Mohamed Osama  **

## Hardware used :
 1. PIC18F4620
 2. HeartRate Digital Sensor
 3. 20x4 LCD
 
 ## Software used :
 ### MCAL LAYER :
 1. GPIO Driver
 2. Interrupt DRIVER
 3. Timer3 Driver
 4. CCP Module Driver
   
### HAL LAYER :
1. LCD Driver

 ## Features :
1. Uses The CCP1 Module in Capture Mode
2. Captures the period between the Pulses of the HeartRate Sensor
3. It Calculates The BPM by dividing 60 / The period between the Pulses
4. Shows the Calulated BPM on The LCD
