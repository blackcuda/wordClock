/*
 * wordClock.cpp
 *
 * Created: 3-4-2018 20:55:18
 * Author : Jeroen
 */ 

#include <avr/io.h>
#include "util/delay.h"
#include "segment.hpp"
#include "light.hpp"
#include "util.hpp"
extern "C"{
	#include "../modules/light_ws2812/light_ws2812_AVR/Light_WS2812/light_ws2812.h"
}


#define F_CPU 16000000UL // 16MHz


int main(void)
{
	
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
	
	light clockLight;
	
    while (1) 
    {		

    }
}



