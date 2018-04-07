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

struct timeText {
	bool het;
	bool is;
	bool was;
	bool vijfVoor;
	bool tienVoor;
	bool kwart;
	bool voor;
	bool over;
	bool precies;
	bool half;
	bool een;
	bool twee;
	bool drie;
	bool vier;
	bool vijf;
	bool zes;
	bool zeven;
	bool acht;
	bool negen;
	bool tien;
	bool elf;
	bool twaalf;
	bool uur;
};

struct timeText timeToSegment();
void textToLed (struct timeText t);

//void setSegmentOn (struct segment);
//void setSegmentOff (struct segment);

#endif /* TIMETOLED_H_ */