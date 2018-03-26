/*
 * timeToLed.c
 *
 * Created: 25-3-2018 21:47:19
 *  Author: Jeroen
 */ 

#include "timetoled.h"
#include "util.h"

struct timeText timeToText ()
{
	
	int min = 0;
	int hour = 1;
	
	struct timeText  timeT;
	
	timeT.het = 1;

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

void textToLed(struct timeText t)
{

}