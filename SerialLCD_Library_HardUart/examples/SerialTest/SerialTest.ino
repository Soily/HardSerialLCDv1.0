//  * ------------
//  *  Control a Serial1 LCD Display
//  *  
//  *  Tested on a Seeed Starter Kit Serial LCD.
//	*  The Serial LCD is connected directly to hardware UART (Serial1)
//  *  No Software-Serial is used to make it working (Arduino breakout-board)
//  *  
//  *   
//  *  Copyleft 2006 by djmatic
//  *  Updated to be Arduino Intel IoT-IDE 
//  *  January 04 2014
//  *  
//  *   ------------
//  *
//  *


#include <SerialLCD_HardUart.h>

// Declare your program variables here

SerialLCD_HardUart SerialTest;

// Arduino and LCD setup 
void setup()
{
    SerialTest.begin();
}

//  MAIN CODE
void loop()
{ 
  SerialTest.print("Test Man");
  delay(1000);
  
  //backlightOn(0);  // turn the backlight on all the time
}

