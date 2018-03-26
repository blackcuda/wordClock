/*
 * timeToLed.h
 *
 * Created: 25-3-2018 21:46:11
 *  Author: Jeroen
 */ 


#ifndef TIMETOLED_H_
#define TIMETOLED_H_

struct timeText {
	_Bool het;
	_Bool is;
	_Bool was;
	_Bool vijfVoor;
	_Bool tienVoor;
	_Bool kwart;
	_Bool voor;
	_Bool over;
	_Bool precies;
	_Bool half;
	_Bool een;
	_Bool twee;
	_Bool drie;
	_Bool vier;
	_Bool vijf;
	_Bool zes;
	_Bool zeven;
	_Bool acht;
	_Bool negen;
	_Bool tien;
	_Bool elf;
	_Bool twaalf;
	_Bool uur;
};

struct timeText timeToText();
void textToLed(struct timeText t);


#endif /* TIMETOLED_H_ */