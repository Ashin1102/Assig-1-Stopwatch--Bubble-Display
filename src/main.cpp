#include <Arduino.h>
#include "SevSeg.h"

u_int8_t Reset_Button = 2;// Reset Interupt button pin
u_int8_t  StartStop_Button = 11;// Start or Stop Interupt button pin

// Global Variables
int Previous_StartStopButton= 0;
int flag=0;
int Previous_ResetButton= 0;
uint32_t long timer;
int deciSecond=0;
void StartStop_Interrupt();
void Reset_Interrupt();

// An instance of object
SevSeg myDisplay;

void setup() {

int displayType = COMMON_CATHODE; //display is common cathode

//The pins that are connected to the mosfet gate pins that are sink from cathode to ground

 int digit1 = 21; //Pin 1
 int digit2 = 23; //Pin 10
 int digit3 = 22; //Pin 4
 int digit4 = 20; //Pin 6
  // put your setup code here, to run once:

  // Pins connected to anode
 int segA = 3; //Pin 12
 int segB = 4; //Pin 11
 int segC = 9; //Pin 3
 int segD = 6; //Pin 8
 int segE = 10; //Pin 2
 int segF = 5; //Pin 9
 int segG = 7; //Pin 7
 int segDP= 8; //Pin 5

 int numberOfDigits = 4 ;// 4 digit display

myDisplay.Begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA,
segB, segC, segD, segE, segF, segG, segDP);

 myDisplay.SetBrightness(100); // set brightness level to 100%

 timer = millis(); // timer variable store the time the microcontroller start working

 pinMode(2, INPUT_PULLUP); // Assigned  pullup resistor attached to the button
 pinMode(11, INPUT_PULLUP);//Assigned  pullup resistor attached to the button
 
// Run the interupt pin start/stop function when pin goes low
 attachInterrupt(digitalPinToInterrupt(StartStop_Button ), StartStop_Interrupt, FALLING); //Interrupt activated when Start_Stop_Button pressed
 
 // Run the interupt pin start/stop function when pin goes low
 attachInterrupt(digitalPinToInterrupt( Reset_Button), Reset_Interrupt, FALLING); // Interruptactivated when Reset_Button Pressed

}

void loop() {

  // Display the floating point number that the time of stop watch associated with

  char tempString[10]; //Used for sprintf to store the string form of the timer
 sprintf(tempString, "%04d", deciSecond); //Convert deciSecond into a string that is right adjusted

 myDisplay.DisplayString(tempString, 3); //(numberToDisplay, decimal point locationin binary number [4 means the third digit])


 //Check if 10ms has elapsed
 if (millis() - timer >= 100 && flag==0)
 {
 timer = millis();// keeps updating the start time point untill start time is pressed
 deciSecond++;// This just gets the variable going for the loop to handlr next time
 }
 }


 void StartStop_Interrupt() // Interrupt activated when Start_Stop_Button pressed

 {
 int Previous_StartStopButton = digitalRead(StartStop_Button);// check if the pushbutton is pressed.
 // if it is, the buttonState is HIGH:

 if (Previous_StartStopButton== LOW && flag==0)
 {

 flag=1;
 }
 else if(Previous_StartStopButton== LOW && flag==1)
 {
 flag=0;
 }
 }

 void Reset_Interrupt() // Interrupt activated when Reset_Button pressed
 {
 int Previous_ResetButton=digitalRead (Reset_Button);

 if (Previous_ResetButton==LOW)

 {

 deciSecond=0;

 }
  }