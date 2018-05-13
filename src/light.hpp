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
#include "timeclock.hpp"

class light
{	
	public:	
		// Constructor
		light();
		
		// Destructor
		~light();
		
		void setLight();	
		void setSegments(timeText aTimeText);
		void setBrightness(const int aBrightness);	
		void setLightOn();
		void setLightOff();
		void setColour(int red, int green, int blue, int white);
		void changeColour();
		
		void update();
		
	private:	
		cRGBW led[LED_AMOUNT];
		segment aSegment[SEGMENT_AMOUNT];
					
		timeText theTimeText = {};
			
		timeClock theTimeClock = {};
			
		int colour = 0;
			
};

#endif /* LIGHT_HPP_ */