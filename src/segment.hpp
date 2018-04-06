/*
 * segment.hpp
 *
 * Created: 2-4-2018 21:41:02
 *  Author: Jeroen
 */ 

#include <stdbool.h>

extern "C"{
	#include "../modules/light_ws2812/light_ws2812_AVR/Light_WS2812/light_ws2812.h"
}
#ifndef SEGMENT_HPP
#define SEGMENT_HPP

class segment{
	
	public:
	
		// constructor
		segment();
		
		// destructor
		~segment();
		
		int getLength ();

		void setColour (int red, int green, int blue, int white);
		cRGBW getColour ();
		
		uint8_t getRed();
		
		void setSegmentOn();
		void setSegmentOff();
		
		bool isSegmentOn();
		bool isSegmentOff();
		
	private:
	
		bool isOn;
		int length;

		struct cRGBW word;
};	

#endif