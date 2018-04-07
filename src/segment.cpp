/*
 * segment.cpp
 *
 * Created: 2-4-2018 21:43:36
 *  Author: Jeroen
 */ 


#include "segment.hpp"


segment::segment()
	:isOn(0),length(0), word()
{
		
}

segment::~segment()
{
	
}

void segment::setLenght(int aLength)
{
	length = aLength;
}

int segment::getLength()
{
	return length;
}

void segment::setColour(int red, int green, int blue, int white)
{	
	if (isOn)
	{
		word.r = red;
		word.g = green;
		word.b = blue;
		word.w = white;
	}
	else
	{
		wordOld.r = red;
		wordOld.g = green;
		wordOld.b = blue;
		wordOld.w = white;
	}

}

cRGBW segment::getColour()
{	
	return word;
}

void segment::setSegmentOn()
{
	isOn = true;
	
	word = wordOld;
}

void segment::setSegmentOff()
{
	isOn = false;
	
	wordOld = getColour();
		
	word.r = 0;
	word.g = 0;
	word.b = 0;
	word.w = 0;
}

bool segment::isSegmentOn()
{
	return isOn;
}