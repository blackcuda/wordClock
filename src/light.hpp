/*
 * light.h
 *
 * Created: 7-4-2018 18:03:11
 *  Author: Jeroen
 */ 


#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "util.hpp"
#include "segment.hpp"
#include "timetoled.hpp"

class light
{	
	public:	
		light();
		~light();
		
		void setLight();	
		void setBrightness(int aBrightness);	
		void setLightOn();
		void setLightOff();
	
	private:	
		cRGBW led[LED_AMOUNT];
		segment aSegment[SEGMENT_AMOUNT];
		int brightness;
};

#endif /* LIGHT_HPP_ */