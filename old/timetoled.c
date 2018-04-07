/*
 * timeToLed.c
 *
 * Created: 25-3-2018 21:47:19
 *  Author: Jeroen
 */ 

#include "timetoled.h"



struct timeText timeToSegment ()
{
	
	int min = 0;
	int hour = 1;
	
	struct timeText  timeT;
	
	timeT.het = 1;
	timeT.is = 1;

	if (min == 0 || min == 30)
	{
		timeT.precies = 1;
	}
	
	if (min == 15 || min == 45)
	{
		timeT.kwart = 1;
	}
	
	if (min >= 20)
	{
		hour ++;
	}
	
	switch(hour) {
		case 1 :
			timeT.een = 1;
			break;
		case 2 :
			timeT.twee = 1;
			break;
		case 3 :
			timeT.drie = 1;
			break;
		case 4 :
			timeT.vier = 1;
			break;
		case 5 :
			timeT.vijf = 1;
			break;
		case 6 :
			timeT.zes = 1;
			break;
		case 7 :
			timeT.zeven = 1;
			break;
		case 8 :
			timeT.acht = 1;
			break;
		case 9 :
			timeT.negen = 1;
			break;
		case 10 :
			timeT.tien = 1;
			break;
		case 11 :
			timeT.elf = 1;
			break;
		case 12 :
			timeT.twaalf = 1;
			break;
	}
		
	return timeT;
}

struct cRGBW led[LED_AMOUNT];
	
void textToLed(struct timeText t)
{
	//segment het_segment;
	
//	het_segment.setColour(10,10,10,10);
	
	
	/*
	for(int i = 0; i < SEGMENT_AMOUNT; i++)
	{
		// IF the segment should be on 
		//if ()
			setSegmentOn(hetSegment);
	}
	*/
/*
	if (t.het)
	{
		for(int i = HET_LOW ; i <= HET_HIGH; i++)
		{
			led[i].r = 50;
		}
	}
	
	if (t.is)
	{
		for(int i = IS_LOW ; i <= IS_HIGH; i++)
		{
			led[i].r = 50;
		}
	}
	
	if (t.was)
	{
		for(int i = WAS_LOW ; i <= WAS_HIGH; i++)
		{
			led[i].r = 50;
		}
	}
	
	if (t.vijfVoor)
	{
		for(int i = VIJF_LOW ; i <= VIJF_HIGH; i++)
		{
			led[i].r = 50;
		}
	}
	
	if (t.tienVoor)
	{
		for(int i = TIEN_LOW ; i <= TIEN_HIGH; i++)
		{
			led[i].r = 50;
		}
	}
	
	if (t.kwart)
	{
		for(int i = KWART_LOW ; i <= KWART_HIGH; i++)
		{
			led[i].r = 50;
		}
	}
	
	if (t.voor)
	{
		for(int i = KWART_LOW ; i <= KWART_HIGH; i++)
		{
			led[i].r = 50;
		}
	}
	
	if (t.kwart)
	{
		for(int i = KWART_LOW ; i <= KWART_HIGH; i++)
		{
			led[i].r = 50;
		}
	}
	
	if (t.kwart)
	{
		for(int i = KWART_LOW ; i <= KWART_HIGH; i++)
		{
			led[i].r = 50;
		}
	}
	
	if (t.kwart)
	{
		for(int i = KWART_LOW ; i <= KWART_HIGH; i++)
		{
			led[i].r = 50;
		}
	}
	
	if (t.kwart)
	{
		for(int i = KWART_LOW ; i <= KWART_HIGH; i++)
		{
			led[i].r = 50;
		}
	}
*/
	ws2812_setleds_rgbw(led, LED_AMOUNT);
}

/*
void setSegmentOn(struct segment)
{		
	for(int i = segment. ; i <=  	segmen;; i++)
	{
		led[i].r = 50;
	}
}
*/





