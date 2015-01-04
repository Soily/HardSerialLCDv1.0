/*
  SerialLCD_HardUart.h - Serial LCD driver Library
  2010 Copyright (c) Seeed Technology Inc.  All right reserved.
 
  Original Author: Jimbo.We
  Contribution: Visweswara R 
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <inttypes.h>
#include <Arduino.h>
#include <SerialLCD_HardUart.h>

SerialLCD_HardUart::SerialLCD_HardUart()
{

}

/********** High level commands, for the user! **********/

// Initialize the Serial LCD Driver. SerialLCD Module initiates the communication.
void SerialLCD_HardUart::begin()
{
    Serial1.begin(9600);
	
	/* Debug Info */
	//Serial.begin(9600);
	//delay(3000);
	//Serial.print("Begin started");
    /*while(1)
    {
        if ( Serial1.available() > 0 &&  Serial1.read()==SLCD_INIT )
        {
            Serial1.write(SLCD_INIT_ACK);
            break;
        }
    }*/
	/* Debug Info */
	//Serial.print("SLCD Init");
    
    delay(2);
    Serial1.write(SLCD_CONTROL_HEADER);   
    Serial1.write(SLCD_POWER_OFF); 
    delay(1);
    Serial1.write(SLCD_CONTROL_HEADER);   
    Serial1.write(SLCD_POWER_ON);
    delay(1);
    Serial1.write(SLCD_INIT_ACK);
    /*
	while(1)
    {
        if (Serial1.available() > 0 &&Serial1.read()==SLCD_INIT_DONE)
            break;
    }*/
	/* Debug Info */
	//Serial.print("Begin successful");
    
	delay(2);
}

// Clear the display
void SerialLCD_HardUart::clear()
{
    Serial1.write(SLCD_CONTROL_HEADER);   
    Serial1.write(SLCD_CLEAR_DISPLAY);   
}

// Return to home(top-left corner of LCD)
void SerialLCD_HardUart::home()
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_RETURN_HOME);  
    delay(2);//this command needs more time;  
}

// Set Cursor to (Column,Row) Position
void SerialLCD_HardUart::setCursor(uint8_t column, uint8_t row)
{
    Serial1.write(SLCD_CONTROL_HEADER); 
    Serial1.write(SLCD_CURSOR_HEADER); //cursor header command
    Serial1.write(column);
    Serial1.write(row);
}

// Switch the display off without clearing RAM
void SerialLCD_HardUart::noDisplay() 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_DISPLAY_OFF);    
}

// Switch the display on
void SerialLCD_HardUart::display() 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_DISPLAY_ON);    
}

// Switch the underline cursor off
void SerialLCD_HardUart::noCursor() 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_CURSOR_OFF);     
}

// Switch the underline cursor on
void SerialLCD_HardUart::cursor() 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_CURSOR_ON);     
}

// Switch off the blinking cursor
void SerialLCD_HardUart::noBlink() 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_BLINK_OFF);     
}

// Switch on the blinking cursor
void SerialLCD_HardUart::blink() 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_BLINK_ON);     
}

// Scroll the display left without changing the RAM
void SerialLCD_HardUart::scrollDisplayLeft(void) 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_SCROLL_LEFT);
}

// Scroll the display right without changing the RAM
void SerialLCD_HardUart::scrollDisplayRight(void) 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_SCROLL_RIGHT);
}

// Set the text flow "Left to Right"
void SerialLCD_HardUart::leftToRight(void) 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_LEFT_TO_RIGHT);
}

// Set the text flow "Right to Left"
void SerialLCD_HardUart::rightToLeft(void) 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_RIGHT_TO_LEFT);
}

// This will 'right justify' text from the cursor
void SerialLCD_HardUart::autoscroll(void) 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_AUTO_SCROLL);
}

// This will 'left justify' text from the cursor
void SerialLCD_HardUart::noAutoscroll(void) 
{
    Serial1.write(SLCD_CONTROL_HEADER);
    Serial1.write(SLCD_NO_AUTO_SCROLL);
}
void SerialLCD_HardUart::Power(void)
{
    Serial1.write(SLCD_CONTROL_HEADER);   
    Serial1.write(SLCD_POWER_ON); 
}
void SerialLCD_HardUart::noPower(void)
{
    Serial1.write(SLCD_CONTROL_HEADER);   
    Serial1.write(SLCD_POWER_OFF); 
}
//Turn off the backlight
void SerialLCD_HardUart::noBacklight(void)
{
    Serial1.write(SLCD_CONTROL_HEADER);   
    Serial1.write(SLCD_BACKLIGHT_OFF);   
}
//Turn on the back light
void SerialLCD_HardUart::backlight(void)
{
    Serial1.write(SLCD_CONTROL_HEADER);   
    Serial1.write(SLCD_BACKLIGHT_ON);   
}
// Print Commands

void SerialLCD_HardUart::print(uint8_t b)
{
    Serial1.write(SLCD_CHAR_HEADER);
    Serial1.write(b);
}
void SerialLCD_HardUart::print(const char b[])
{
    Serial1.write(SLCD_CHAR_HEADER);
    Serial1.write(b);
}

void SerialLCD_HardUart::print(unsigned long n, uint8_t base)
{
    unsigned char buf[8 * sizeof(long)]; // Assumes 8-bit chars.
    unsigned long i = 0;

    if (base == 0) print(n);

    else if(base!=0)
    {
        if (n == 0) {
            print('0');
            return;
        }

        while (n > 0) {
            buf[i++] = n % base;
            n /= base;
        }

        for (; i > 0; i--)
            print((char) (buf[i - 1] < 10 ?
                          '0' + buf[i - 1] :
                          'A' + buf[i - 1] - 10));
    }
}

void SerialLCD_HardUart::print(float data,uint8_t num)
{
  unsigned long temp;
  unsigned long n;
  int i;
  n = (unsigned long)data;
  
 // setCursor(1,0);
  print(n,10);
 

   switch(num)
  {
    case 1:
		{
			temp = data*10;
			Serial1.write('.');
			Serial1.write(temp%10+48);
			break;
		}
	case 2:
		{
			temp = data*100;
			Serial1.write('.');
			Serial1.write(temp%100/10+48);
			Serial1.write(temp%10+48);
		    break;
		}
	case 3:
		{
			temp = data*1000;
			Serial1.write('.');
			Serial1.write(temp/100%10+48);
			Serial1.write(temp%100/10+48);
			Serial1.write(temp%10+48);
			break;
		}
	case 0:break;
	default:break;
  }
  
}
