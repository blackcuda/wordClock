/*
 * timeToLed.h
 *
 * Created: 25-3-2018 21:46:11
 *  Author: Jeroen
 */ 


#ifndef TIMETOLED_H_
#define TIMETOLED_H_

#include "../modules/light_ws2812/light_ws2812_AVR/Light_WS2812/light_ws2812.h"
#include "util.hpp"

struct timeText
{
	bool het;
	bool is;
	bool was;
	bool vijf;
	bool tien;
	bool kwart;
	bool voor;
	bool over;
	bool precies;
	bool half;
	bool eenUur;
	bool tweeUur;
	bool drieUur;
	bool vierUur;
	bool vijfUur;
	bool zesUur;
	bool zevenUur;
	bool achtUur;
	bool negenUur;
	bool tienUur;
	bool elfUur;
	bool twaalfUur;
	bool uur;
};

// struct timeText timeToSegment();

#endif /* TIMETOLED_H_ */