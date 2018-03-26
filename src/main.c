/*
 * wordClock.c
 *
 * Created: 25-3-2018
 * Author : Jeroen
 */ 

#define F_CPU 16000000UL // 16MHz

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
//#include "light_ws2812.h"
#include "util.h"
#include "../modules/light_ws2812/light_ws2812_AVR/Light_WS2812/light_ws2812.h"
#include "timetoled.h"


//struct cRGBW led[LED_AMOUNT];
	
int main(void)
{
	
	
	// Get time
	
	//rtc_set_time_s(uint8_t hour, uint8_t min, uint8_t sec);
	
	// Parse time to LED's

	struct cRGBW led[LED_AMOUNT];
	
	for (int i = 0; i < LED_AMOUNT ; i++)
	{
		led[i].r = 0;
		led[i].g = 0;
		led[i].b = 0;
		led[i].w = 0;
	}
	
	ws2812_setleds_rgbw(led, LED_AMOUNT);
	
		
    while (1) 
    {		
		struct timeText t;	
		t = timeToText();
			
		if (t.een)
		{
			for(int i = 0 ; i < 1; i++)
			{
				led[i].r = 50;
			}
		}
		
		if (t.twee)
		{
			for(int i = 1; i < 2; i++)
			{
				led[i].r = 50;
			}
		}
		
		if (t.drie)
		{
			for(int i = 2; i < 3; i++)
			{
				led[i].r = 50;
			}
		}
		
		ws2812_setleds_rgbw(led, LED_AMOUNT);
		
		//textToLed(timeT);
		
		/*	
		for (int i = 0; i < LED_AMOUNT ; i++)
		{
			led[i].r = 50;
			led[i].g = 0;
			led[i].b = 0;
			led[i].w = 0;
			
			ws2812_setleds_rgbw(led, LED_AMOUNT);
			
			led[i].r = 0;
			
			_delay_ms(100);
		}	
		*/
    }
}

