# BlinkLEDs

This is a program written as C++ in Sketch (Arduino IDE) where the two LEDs blinked at random intervals and the Light Dependent Resistor (LDR) is used to count the number of blinks of each LED every 60 seconds. The number of counts is displayed using 7-segment LED displays and the data is manually exported to Excel to be plotted as a bar graph. 

> [!IMPORTANT] 
> Please use Arduino IDE to run the program. In order to run the program successfully, please connect the circuit according to schematic diagram. I have added notes in the code for you to help you understand the code. 

## Schematic Diagram 

![](https://i.imgur.com/rHCvEz5.png)

## Circuit Description

1) Both 7-segment LED single digits common cathode lights up with equal brightness and LEDs also lights up with equal brightness.
2) The 240 ohm resistor is connected in series with LED in each segment in 7 segment display as a current limiting resistor.
3) The 220 ohm resistor is connected in series with LED as a current limiting resistor.
4) The 2k ohm is connected in series with the LDR as a fixed resistor, Rs and the reading from the LDR is obtained from the pin analog pin A0 and it is connected to Vout of the voltage divider.
5) The decoders are used to reduce the number of pins used to connect to the 7 segment display.
6) The decoders has 4 BCD (binary coded decimal) inputs and 7 output lines which is connected to each segment in 7 segment display.
7) Common cathode 7 segment display is used instead of common anode because it is easier to do programming as it will light up when the logic input is 1 (HIGH).

## Code Explanation

In the function setup, the digital pins 11 and 12 (LED1 and LED2 respectively) are initialized as the OUTPUT, and the digital pins 2 to 6 are initialized as the OUTPUT for the first decoder. In contrast, the digital pins 6 to 9 are initialized as the OUTPUT for the second decoder. Initially, the number 0 will displayed on both 7 segment displays. In function setup, there will be commands to label the heading of each column in Excel and commands to label the custom boxes 1 and 2 and each of the custom boxes is ticked. The randomSeed is to randomize the pseudo-random number generator with a random input from an unconnected pin.

In the loop function, the variable randInterval1 is initialized and assigned with random number from 8000 to 60000 while the variable randInterval2 is initialized and assigned with random number from 2000 to 60000. The variable timerun stores the time in ms since the program run by Arduino.

The first if loop (which will contain codes of blinking of each LEDs and codes to count the number of blinking of each LEDs) will run when the timerun is lower than 60000ms (1 minute). If timerun exceeds 1 minute, then the program will not run this loop.

In this if loop, this will blink the LED as well as count the number of blinking. When millis() (a function that returns the time program ran in ms) minus LED1timer (which is initialized to 0 as a global variable) is equal or more than the randomized interval 1, then LED1state will change either LOW or HIGH. When it is HIGH, then the value read from the LDR is within the range. When it is within the range, the count1 which is initially 0 will increase by 1 and afterwards the count1 will enter a switch loop, if it is 1, then number 1 will be displayed (this is the same for LED2 but in different range)

If millis() - LED1 timer is less than the first randomize interval, then the LED1state will be LOW (before that, LED1 is HIGH and turned on, now LED1 will be turned off. In the end, the LED1 timer will store the value of time passed since the loop started (not the program started).

When the timerun (time elapsed since the program ran) reaches equal or more than 1 minute, the program will run the second if loop, the program will stop transferring data to excel and LEDs will be turned off, the 7 segment displays will display 0.

