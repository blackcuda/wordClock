/*
 * segment.cpp
 *
 * Created: 2-4-2018 21:43:36
 *  Author: Jeroen
 */ 


#include "segment.hpp"


segment::segment()
	:isOn(0),length(0), brightness(10), word()
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

void segment::setOutput()
{
	word.r = colour.r * brightness * isOn; // colour is 0 / 25, brightness is 1 / 10, isOn is 0 / 1.
	word.g = colour.g * brightness * isOn;
	word.b = colour.b * brightness * isOn;
	word.w = colour.w * brightness * isOn;
}

cRGBW segment::getOutput()
{
	return word;
}

void segment::setColour(int red, int green, int blue, int white)
{	
	colour.r = red;
	colour.g = green;
	colour.b = blue;
	colour.w = white;
	
	setOutput();
}

cRGBW segment::getColour()
{	
	return colour;
}

void segment::setSegmentOn()
{
	isOn = true;
}

void segment::setSegmentOff()
{
	isOn = false;
}

bool segment::isSegmentOn()
{
	return isOn;
}

void segment::setBrightness(const int aBrightness)
{
	if(aBrightness < 1)
	{
		brightness = 1;
	} 
	else
	{
		brightness = aBrightness;
	}
	
	setOutput();
}