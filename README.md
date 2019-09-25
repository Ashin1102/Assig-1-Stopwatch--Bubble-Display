# Assig-1-Stopwatch--Bubble-Display
           
	   

INTRODUCTION
The stopwatch is a hand held timepiece designed to measure the amount of time that elapses from a particular time between it is activated and deactivated. The timing functions are traditionally controlled by two buttons. Pressing the start button starts the timer running, and pressing the button a second time stops it, leaving the elapsed time displayed. A press of the reset button then resets the stopwatch to zero.” (Ref: - “Stop Watch-Wikipedia)

“The second part of the project focus on reaction time, the reaction time is the interval between the reception of a stimulus and the initiation of the response.” (Ref: - “Reaction Time, Wikipedia)




OBJECTIVE
	The objective of the project is to design and construct a minimal stop watch using the bubble display with a start & stop switch, reset buttons, the teensy 3.2 board and bubble display.





PROGRAM CONCEPT
The main part of this project ids to write the program using Version Studio Code as per the project requirements which includes:- a start and Stop button, a reset button, and replace the delays with Millis().As the external interrupt is being used in this project, so we have to consider the denouncing time for this project.
The second part of the project is designing a hardware prototype which can be done within a breadboard. As per the designed circuit the connections for the bubble display has to be made on the bread board by connecting 8 output pins of the teensy board to the8 anode pins of the bubble display using an current limiting resistors to protect the LED of the display. The N –channel Enhancement type MOSFET is used to switch the cathode corresponding to each digits of the bubble display controlled by the pull-down (to keep the MOSFET OFF during start up) resistors and inputs from the teensy 3.2 development board.


COMPONENTS USED
•	BUBBLE DISPLAY (QDSP-6064)
The bubble display is used to display 4 digits at a time.  Here the bubble display is the combination of 4- 7 segment display with common cathode type which can program according to what we want to display The brightness of the display can be adjusted during the programming

•	MOSFET (IRLU8743)
The MOSFET is a voltage controlled field effect transistor that has oxide gate which insulated from the semiconductor. Here a pull-down resistor is used to avoid the by limiting the current due to the high capacitive gate which can draw large amount of current when turns ON

•	RESISTOR
The limiting resistors and Pull-down are used here to protect the device and Avoid Floating of MOSFET.

•	PUSH BUTTONS – 2Nos
The Push buttons are used for Start / Stop and Reset

DEVELOPMENT BOARD(Teensy 3.2)

DESIGN PROCEDURE



•	Power up the teensy 3.2. 
•	The value of the resistor is determined by adjusting the output current in the range of mA. Here the Voltage is 3.3V and the maximum current will give the value of the resistor as 340 Ohm. Hence the above resistor will limit the current to the led in the display
•	Pull-down resistor of 10Kohm is connected to MOSFET to avoid floating of the MOSFET
•	The Push buttons are used to control Start or Stop and reset of the timer.

METHODOLOGY


•	Design a concept to implement the project objective
•	Design the circuit for the hardware using the provided components to achieve the task
•	Using Version Studio code, write the program using the ’’SevnSeg’’ library to implement the required task
•	Upload the program to Teensy 3.2 development board 
•	Make sure that the minimal stop watch is function properly using Start/Stop Switch and reset button



LIMITATIONS
•	The limitation of the project is there some problem with debouncing the buttons
•	The timer sometimes stops without any error
•	The second display goes intermittently blank once reset button is pressed once the start button is pressed it starts displaying.
RESULT
Video Link: https://youtu.be/KSmPkJjt17w

CONCLUSION
The minimal stopwatch is developed using Teensy 3.2 development board and Bubble display, Start/Stop button and Reset Push buttons. 
DATA SHEET
https://www.alldatasheet.com/datasheet pdf/pdf/1009960/ISC/IRLB8748.html
https://cdn.sparkfun.com/datasheets/Components/LED/BB_QDSP_DS.pdf



