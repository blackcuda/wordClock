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

void timer1_init()
{
	OCR1A = 0x3D08;
	
	TCCR1B |= (1 << WGM12);
	// Mode 4, CTC on OCR1A
	
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

void pinChange_init()
{
	DDRB &= ~((1 << DDB0) | (1 << DDB1) | (1 << DDB3)); // PB0,PB1,PB2 (PCINT0, PCINT1, PCINT2 pin) are now inputs.
	PORTB |= ((1 << PORTB0) | (1 << PORTB1) | (1 << PORTB3)); // PB0, PB1 and PB2 are now inputs with pull-up enabled.
	
	PCMSK0 |= ((1 << PCINT0) | (1 << PCINT1) | (1 << PCINT3)); // Set PCINT0 to trigger an interrupt on state change.
	PCICR |= (1 << PCIE0); // Set PCIE0 to enable PCMSK0 scan.
		
	sei();
}

bool callClockTime;
bool newADCValue;
bool button1Pressed = false;
bool button2Pressed = false;
bool button3Pressed = false;
uint8_t valueADC;
volatile uint8_t portbHistory = 0xFF;     // default is high because the pull-up

int main(void)
{
	//DDRB  = 0xFF;
	//PORTB &= (1<<5);

	timer1_init();
	uartInit(); // init uart
	adc1_init();
	pinChange_init();
	
 	struct cRGBW led[LED_AMOUNT];
			
	for (int i = 0; i < LED_AMOUNT; i++)
	{
		led[i].r = 0;
		led[i].g = 0;
		led[i].b = 0;
		led[i].w = 0;
	}
	
	ws2812_setleds_rgbw(led, LED_AMOUNT);
	
	timeClock theClock;
	light clockLight;

				
	//struct tm* theTime = NULL;
	//rtc_set_time_s(17, 49, 40);
	
    while (1) 
    {
 		if(callClockTime)
		{
			callClockTime = false;
			
			clockLight.update();

// 			theTime = theClock.getTime();
// 				 	
// 			int second = theTime->sec;
// 			int minute = theTime->min;
// 			int hour = theTime->hour;
// 			char bufSec[10];
// 			char bufMin[10];
// 			char bufHour[10];
// 		
// 			itoa(second, bufSec, 10);
// 			itoa(minute, bufMin, 10);
// 			itoa(hour, bufHour, 10);
		 
			//uartSendString("hello world \n");
// 			uartSendByte(bufHour[0]);
// 			uartSendByte(bufHour[1]);
// 			uartSendString(":");
// 			uartSendByte(bufMin[0]);
// 			uartSendByte(bufMin[1]);
// 			uartSendString(":");
// 			uartSendByte(bufSec[0]);
// 			uartSendByte(bufSec[1]);

		//	uartSendString("ADC Value: ");
			
// 			char digitArray[3];
// 			int henk = 101;
// 			itoa(valueADC, digitArray, 10);
//  			uartSendByte(digitArray[0]);
//  			uartSendByte(digitArray[1]);
//  			uartSendByte(digitArray[2]);
// 			uartSendString("\n\r");
		}
		
		if(button1Pressed)
		{
			button1Pressed = false;
			
			clockLight.changeColour();
		}
		
		if(button2Pressed)
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
			
			clockLight.changeColour();
		}
	
	//	_delay_ms(10);
	}
}


ISR(TIMER1_COMPA_vect) {
	callClockTime = true;
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
// 		// 
// 	}
}


bool button1_in = false;
bool button2_in = false;
bool button3_in = false;

ISR(PCINT0_vect)
{		
	uint8_t changedBits = PINB ^portbHistory;
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
