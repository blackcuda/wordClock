/*
 * timeclock.cpp
 *
 * Created: 15-4-2018 15:52:50
 *  Author: Jeroen
 */ 


#include "timeClock.hpp"



timeClock::timeClock()
	:theTime()
{
	twi_init_master(); // Init I2C
	rtc_init(); // Init RTC
}


timeClock::~timeClock()
{
	
}


void timeClock::setTime(uint8_t aHour, uint8_t aMinute, uint8_t aSecond)
{
	rtc_set_time_s(aHour, aMinute, aSecond);
}

tm* timeClock::getTime()
{
	theTime = rtc_get_time();
	
	return theTime;
}

timeText timeClock::parseTime(tm* aTime)
{
	int hour = aTime->twelveHour;
	int min = aTime->min;
	//int second = aTime->sec;
	
	timeText timeT = {};
		
	timeT.het = true;
		
	if((min % 5) == 0)
	{
		timeT.is = true;
	}
	else
	{
		timeT.was = true;
	}

	if (min == 0 || min == 30 )
	{
		timeT.precies = true;
	}
		
	int remainder = min % 5;
	min = min - remainder;
		
	if (min == 0)
	{
		timeT.uur = true;
	}
		
	if (min == 5 || min == 25 || min == 35 || min == 55)
	{
		timeT.vijf = true;
	}
		
	if (min == 10 || min == 20 || min == 40 || min == 50)
	{
		timeT.tien = true;
	}
		
	if (min == 15 || min == 45)
	{
		timeT.kwart = true;
	}
		
	if (min == 5 || min == 10 || min == 15 || min == 35 || min == 40)
	{
		timeT.over = true;
	}
		
	if (min == 20 || min == 25 || min == 45 || min == 50 || min == 55)
	{
		timeT.voor = true;
	}
		
	if (min == 20 || min == 25 || min == 30 || min == 35 || min == 40)
	{
		timeT.half = true;
	}
		
	if (min >= 20)
	{
		hour ++;
	}
		
	switch(hour) {
		case 0 :
		timeT.twaalfUur = true;
		break;
		case 1 :
		timeT.eenUur = true;
		break;
		case 2 :
		timeT.tweeUur = true;
		break;
		case 3 :
		timeT.drieUur = true;
		break;
		case 4 :
		timeT.vierUur = true;
		break;
		case 5 :
		timeT.vijfUur = true;
		break;
		case 6 :
		timeT.zesUur = true;
		break;
		case 7 :
		timeT.zevenUur = true;
		break;
		case 8 :
		timeT.achtUur = true;
		break;
		case 9 :
		timeT.negenUur = true;
		break;
		case 10 :
		timeT.tienUur = true;
		break;
		case 11 :
		timeT.elfUur = true;
		break;
		case 12 :
		timeT.twaalfUur = true;
		break;
	}

	return timeT;
}


