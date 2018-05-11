/*
 * wordClock.cpp
 *
 * Created: 3-4-2018 20:55:18
 * Author : Jeroen
 */ 



#include <avr/io.h>
#include <avr/interrupt.h>
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

bool callClockTime;

int main(void)
{
	timer1_init();
	uartInit(); // init uart
	
	DDRB  = 0xFF;
	PORTB &= (1<<5);
	
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

				
	struct tm* theTime = NULL;
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

			uartSendString("\n");
		}
		_delay_ms(10);
	}
}


ISR(TIMER1_COMPA_vect) {
	callClockTime = true;
}


