/*
 * wordClock.c
 *
 * Created: 25-3-2018
 * Author : Jeroen
 */ 

#define F_CPU 16000000UL // 16MHz
#define LED_AMOUNT 97

#include <avr/io.h>
#include <util/delay.h>
//#include "light_ws2812.h"
#include "../modules/light_ws2812/light_ws2812_AVR/Light_WS2812/light_ws2812.h"


struct cRGBW led[LED_AMOUNT];
	
int main(void)
{
	
	DDRB = 0xFF;         //PB as output
	PORTB= 0x00;         //keep all LEDs off
	
	
    while (1) 
    {			
		for (int i = 0; i < LED_AMOUNT; i++)
		{
			led[i].r = 160;
			led[i].g = 38;
			led[i].b = 50;
			
			
			ws2812_setleds_rgbw(led, LED_AMOUNT);
			_delay_ms(10);
		}
		
		for (int i = 0; i < LED_AMOUNT; i++)
		{
			led[i].r = 0;
			led[i].g = 0;
			led[i].b = 0;
		}
		
		ws2812_setleds_rgbw(led, LED_AMOUNT);			
    }
}



