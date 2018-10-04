/*
 * wordClock.cpp
 *
 * Created: 3-4-2018 20:55:18
 * Author : Jeroen
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>	// for itoa() call
#include <string.h>

#include "util.hpp"
#include "segment.hpp"
#include "light.hpp"
#include "timeclock.hpp"


extern "C"{

	#include "util/delay.h"
	#include "../modules/light_ws2812/light_ws2812_AVR/Light_WS2812/light_ws2812.h"
	#include "../modules/ds_rtc_lib/library-gcc/rtc.h"
	#include "../modules/ds_rtc_lib/library-gcc/test/uart.h"
}

void timer0_init()
{
	OCR0A = 0xFF;
	//TCNT0 = 0x00; // Reset the count value.
	
	TCCR0A |= (1 << WGM01);
	// Mode 2, CTC on OCR0A (clear timer on compare match)
	
	TIMSK0 |= (1 << OCIE0A);
	// Set interrupt on overflow
	
	TCCR0B |= (1 << CS02); // prescaler = 256.
		
	sei();
}

void timer1_init()
{
	OCR1A = 0x3D08;
	
	TCCR1B |= (1 << WGM12);
	// Mode 4, CTC on OCR1A (clear timer on compare match)
	
	TIMSK1 |= (1 << OCIE1A);
	// Set interrupt on compare match
	
	TCCR1B |= (1 << CS12) | (1 << CS10);
	// Set prescaler to 1024 and start the timer
	
	sei();
}

void adc1_init()
{
	ADMUX = 0x00; // use #0 ADC.
	ADMUX |= (1 << REFS0); // Use AVcc as the voltage reference.
	ADMUX |= (1 << ADLAR); // Adjust for 8 bit resolution;
	
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // 128 prescale for 16MHz.
	ADCSRA |= (1 << ADATE); // Set ADC auto trigger enable.
	
	ADCSRB = 0; // 0 for free running mode.
	
	ADCSRA |= (1 << ADEN); // Enable the ADC.
	ADCSRA |= (1 << ADIE); // Enable interrupts.
	
	ADCSRA |= (1 << ADSC); // Start the ADC conversion.
	
	sei();
}

void pins_init()
{
	DDRB &= ~((1 << DDB0) | (1 << DDB1) | (1 << DDB3)); // PB0,PB1,PB3 (PCINT0, PCINT1, PCINT2 pin) are now inputs.
	PORTB |= ((1 << PORTB0) | (1 << PORTB1) | (1 << PORTB3)); // PB0, PB1 and PB3 are now inputs with pull-up enabled.
}

void pinChange_init()
{
	DDRB &= ~((1 << DDB0) | (1 << DDB1) | (1 << DDB3)); // PB0,PB1,PB2 (PCINT0, PCINT1, PCINT2 pin) are now inputs.
	PORTB |= ((1 << PORTB0) | (1 << PORTB1) | (1 << PORTB3)); // PB0, PB1 and PB2 are now inputs with pull-up enabled.
	
	PCMSK0 |= ((1 << PCINT0) | (1 << PCINT1) | (1 << PCINT3)); // Set PCINT0 to trigger an interrupt on state change.
	PCICR |= (1 << PCIE0); // Set PCIE0 to enable PCMSK0 scan.
		
	sei();
}

bool callClockTime;
bool newTimer;
bool newADCValue;

bool button1Pressed = false;
bool button2Pressed = false;
bool button3Pressed = false;

uint16_t valueADC;
volatile uint8_t portbHistory = 0xFF;     // default is high because the pull-up

int main(void)
{
	pins_init();
	timer0_init();
	timer1_init();
	uartInit(); // init uart
	adc1_init();
	//pinChange_init();
	
	timeClock theClock;
	light clockLight;
	
	systemStates currentState = STARTUP_STATE;
	
	uint8_t pinB0PreviousReading = 0;
	uint8_t pinB1PreviousReading = 0;
	uint8_t pinB3PreviousReading = 0;
	
    while (1) 
    {
		switch(currentState)
		{
			case STARTUP_STATE:
				
				break;
			case CLOCK_STATE:
			
				break;
			default: 
				break;
		}
		
 		if(callClockTime)
		{
			callClockTime = false;
			
			int lightSensorValue = (int)((double)valueADC / 255 * 10);
			
			clockLight.setBrightness(lightSensorValue);
			clockLight.update();

 			//char digitArray[4];
			 
			//digitArray[0] = 0;
			//digitArray[1] = 0;
			//digitArray[2] = 0;
			//digitArray[3] = 0;

/*				 
 			itoa(lightSensorValue, digitArray, 10);
  			uartSendByte(digitArray[0]);
  			uartSendByte(digitArray[1]);
  			uartSendByte(digitArray[2]);
 			uartSendString("\n");
			 */
			//uartSendString("call clockTimer \n");

		}
		
		if(newTimer)
		{			
			//uint8_t pinMask = (1 << PINB0) | (1 << PINB1) | (1 << PINB3); // Mask for PINB0, PINB1, PINB3
			
			// when the state differs from the previous state. 
			uint8_t pinB0State = (~PINB) & (1 << PINB0); // the state can only be high for the pins in the pinmask.
			uint8_t pinB1State = (~PINB) & (1 << PINB1); // the state can only be high for the pins in the pinmask.
			uint8_t pinB3State = (~PINB) & (1 << PINB3); // the state can only be high for the pins in the pinmask.
			
			// pinstate shiften & met PINB3 daarna shiften met PINB3 naar rechts. Als 1 deze waarde niet gelijk is 

			if((pinB0State != pinB0PreviousReading) && (pinB0PreviousReading == (1 << PINB0)))
			{				
				if(!button1Pressed)
				{	
					button1Pressed = true;
				}
				else
				{
					button1Pressed = false;
				}
			}
			
			if((pinB1State != pinB1PreviousReading) && (pinB1PreviousReading == (1 << PINB1)))
			{
				if(!button2Pressed)
				{
					button2Pressed = true;
				}
				else
				{
					button2Pressed = false;
				}
			}
			
			if((pinB3State != pinB3PreviousReading) && (pinB3PreviousReading == (1 << PINB3)))
			{
				if(!button3Pressed)
				{
					button3Pressed = true;
				}
				else
				{
					button3Pressed = false;
				}
			}
			
			pinB0PreviousReading = pinB0State;
			pinB1PreviousReading = pinB1State;
			pinB3PreviousReading = pinB3State;
			
			newTimer = false;
		}
		
		if(button1Pressed)
		{
			button1Pressed = false;
			
			//char digitArray[2];
						
			//digitArray[0] = 0;
			//digitArray[1] = 0;
			
			//itoa(button1Counter, digitArray, 10);
			uartSendString("counter = ");
			//uartSendString(digitArray);
			uartSendString("\r\n");
			uartSendString("Color changed \n");
			
			clockLight.changeColour();
		}
		
		
/*		if(button2Pressed)
		{
			button2Pressed = false;
			
			tm* presentTime;
			
			presentTime = theClock.getTime();
			
			uint8_t presentHour = presentTime->twelveHour;
			uint8_t presentMinute = presentTime->min;
			uint8_t presentSecond = presentTime->sec;
			
			rtc_set_time_s(presentHour + 1, presentMinute, presentSecond);
		}
				
		if(button3Pressed)
		{
			button3Pressed = false;
			
			tm* presentTime;
			
			presentTime = theClock.getTime();
			
			uint8_t presentHour = presentTime->twelveHour;
			uint8_t presentMinute = presentTime->min;
			uint8_t presentSecond = presentTime->sec;
			
			rtc_set_time_s(presentHour, presentMinute + 1, presentSecond);
		}
		*/

	}
}

ISR(TIMER1_COMPA_vect) {
	callClockTime = true;
}

ISR(TIMER0_COMPA_vect) {
	newTimer = true;
}

ISR(ADC_vect)
{
	newADCValue = true;
	
	valueADC = ADCH;
	
// 	tmp = ADMUX; // Read the value of the ADMUX register.
// 	tmp &= 0x0F; // AND the first 4 bits (value of ADC pin being used).
// 	
// 	ADCvalue = ADCH; // Read the sensor value;
// 	
// 	if(tmp == 0)
// 	{
//  
// 	}
}


//bool button1_in = false;
//bool button2_in = false;
//bool button3_in = false;

/*
ISR(PCINT0_vect)
{		
	uint8_t changedBits = PINB ^ portbHistory;
	portbHistory = PINB;
	
	if(changedBits & (1 << PINB0)) //PCINT0 changed
	{
		if(!button1_in)
		{
			button1_in = true;
		}
		else
		{
			button1Pressed = true;
			button1_in = false;
		}
	}
	
	if(changedBits & (1 << PINB1)) //PCINT1 changed
	{
		if(!button2_in)
		{
			button2_in = true;
		}
		else
		{
			button2Pressed = true;
			button2_in = false;
		}
	}
	
	if(changedBits & (1 << PINB3)) //PCINT1 changed
	{
		if(!button3_in)
		{
			button3_in = true;
		}
		else
		{
			button3Pressed = true;
			button3_in = false;
		}
	}
}
*/