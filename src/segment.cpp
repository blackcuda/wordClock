/*
 * segment.cpp
 *
 * Created: 2-4-2018 21:43:36
 *  Author: Jeroen
 */ 


#include "segment.hpp"


segment::segment()
	:isOn(0),length(5), word()
{
		
}

segment::~segment()
{
	
}

int segment::getLength()
{
	return length;
}


void segment::setColour(int red, int green, int blue, int white)
{	
	word.r = red;
	word.g = green;
	word.b = blue;
	word.w = white;
}

cRGBW segment::getColour()
{	
	return word;
}

uint8_t segment::getRed()
 {
	 
	 return word.r;
 }

void segment::setSegmentOn()
{
	isOn = true;
}

void segment::setSegmentOff()
{
	isOn = false;
		
	word.r = 0;
	word.g = 0;
	word.b = 0;
	word.w = 0;
}

bool segment::isSegmentOn()
{
	return isOn;
}

bool segment::isSegmentOff()
{
	return isOn;
}
