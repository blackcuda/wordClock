/*
 * timeclock.cpp
 *
 * Created: 15-4-2018 15:52:59
 *  Author: Jeroen
 */ 


#ifndef TIMECLOCK_HPP_
#define TIMECLOCK_HPP_

#include <string.h>
#include <stdlib.h>	// for itoa() call
#include "timetoled.hpp"

extern "C"{
	#include "../modules/ds_rtc_lib/library-gcc/rtc.h"
	#include "../modules/ds_rtc_lib/library-gcc/test/uart.h"
}

class timeClock
{
	public:
		// Constructor
		timeClock();
		
		// Destructor
		~timeClock();
		
		struct time {
			uint8_t hour;
			uint8_t minute;
			uint8_t second;
		};
				
		void setTime(uint8_t aHour, uint8_t aMinute, uint8_t aSecond);
		tm* getTime();
		
		timeText parseTime(tm* aTime);
		
	private:
 
 		struct tm* theTime;
};


#endif /* CLOCK_HPP */