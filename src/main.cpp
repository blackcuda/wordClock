/*
 * wordClock.cpp
 *
 * Created: 3-4-2018 20:55:18
 * Author : Jeroen
 */ 

#include <avr/io.h>
#include "segment.hpp"
extern "C"{
	#include "../modules/light_ws2812/light_ws2812_AVR/Light_WS2812/light_ws2812.h"
}


#define F_CPU 16000000UL // 16MHz
#define LED_AMOUNT 92
#define AMOUNT_OF_SEGMENTS 15

enum{
	HET,
	IS,
	PRECIES
	};

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
	
	segment aSegment[AMOUNT_OF_SEGMENTS];
	
    while (1) 
    {
	

		
	//	for(int i = 0; i < AMOUNT_OF_SEGMENTS; i++)
	//	{
			aSegment[HET].setColour(0,8,8,0);
			aSegment[IS].setColour(8,0,8,0);
			aSegment[7].setColour(50,50,8,0);
			aSegment[14].setColour(8,0,8,0);
	//	}

		
		
		//hetSegment.setSegmentOff();
		
		/*
		if (hetSegment.isSegmentOn())
		{
			PORTB |= (1<<5);
		}
		
		if(hetSegment.isSegmentOff())
		{
			PORTB &= (1<<5);
		}
		*/

		if (aSegment[0].getLength() == 4)
		{
			PORTB |= (1<<5);
		}
	
		for(int i = 0; i < AMOUNT_OF_SEGMENTS; i++)
		{
			for(int j = i * aSegment[i].getLength(); j < (i * aSegment[i].getLength()) + aSegment[i].getLength(); j++)
			{
				led[j] = aSegment[i].getColour();
			}
		}
		
		ws2812_setleds_rgbw(led, LED_AMOUNT);
    }
}



