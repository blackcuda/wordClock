/*
 * light.cpp
 *
 * Created: 7-4-2018 18:02:52
 *  Author: Jeroen
 */ 

#include "light.hpp"

light::light()
	:led(), aSegment()
{
	aSegment[HET].setLenght(HET_LENGTH);
	aSegment[IS].setLenght(IS_LENGTH);
	aSegment[WAS].setLenght(WAS_LENGTH);
	aSegment[VIJF].setLenght(VIJF_LENGTH);
	aSegment[TIEN].setLenght(TIEN_LENGTH);
	aSegment[KWART].setLenght(KWART_LENGTH);
	aSegment[VOOR].setLenght(VOOR_LENGTH);
	aSegment[OVER].setLenght(OVER_LENGTH);
	aSegment[PRECIES].setLenght(PRECIES_LENGTH);
	aSegment[HALF].setLenght(HALF_LENGTH);
	aSegment[EEN_UUR].setLenght(EEN_UUR_LENGTH);
	aSegment[TWEE_UUR].setLenght(TWEE_UUR_LENGTH);
	aSegment[DRIE_UUR].setLenght(DRIE_UUR_LENGTH);
	aSegment[VIER_UUR].setLenght(VIER_UUR_LENGTH);
	aSegment[VIJF_UUR].setLenght(VIJF_UUR_LENGTH);
	aSegment[ZES_UUR].setLenght(ZES_UUR_LENGTH);
	aSegment[ZEVEN_UUR].setLenght(ZEVEN_UUR_LENGTH);
	aSegment[ACHT_UUR].setLenght(ACHT_UUR_LENGTH);
	aSegment[NEGEN_UUR].setLenght(NEGEN_UUR_LENGTH);
	aSegment[TIEN_UUR].setLenght(TIEN_UUR_LENGTH);
	aSegment[ELF_UUR].setLenght(ELF_UUR_LENGTH);
	aSegment[TWAALF_UUR].setLenght(TWAALF_UUR_LENGTH);
	aSegment[UUR].setLenght(UUR_LENGTH);
	
	init();
}

light::~light()
{
	
}

void light::init()
{	
	startUpCycle();
	
	
	// TODO read color from non-volatile memory	
	
	for(int i = 0; i < SEGMENT_AMOUNT; i++)
	{
		if(i%2 == 0)
		{
			aSegment[i].setColour(0,25,0,0);
		}
		else
		{
			aSegment[i].setColour(0,0,25,0);
		}
	}
}

void light::setLight()
{
	int ledIndex = 0;
	int j = 0;
	
	for(int i = 0; i < SEGMENT_AMOUNT; i++)
	{
		for(j = ledIndex; j < ledIndex + aSegment[i].getLength(); j++)
		{
			led[j] = aSegment[i].getOutput();
		}
		ledIndex = j;
	}
	
	ws2812_setleds_rgbw(led, LED_AMOUNT);
}

void light::setLightOn()
{
	setBrightness(100);
}

void light::setLightOff()
{
	setBrightness(0);
}

void light::setBrightness(const int aBrightness)
{	
	for(int i = 0; i < SEGMENT_AMOUNT; i++)
	{
		aSegment[i].setBrightness(aBrightness);
	}
}

void light::changeColour()
{
	int red = 0;
	int green = 0;
	int blue = 0;
	int white = 0;
	
	switch(colour) {
		case 0 :
			red = 25;
			break;
		case 1 :
			green = 25;
			break;
		case 2 :
			blue = 25;
			break;
		case 3 :
			white = 25;
			break;
		case 4 :
			red = 13;
			green = 13;
			break;
		case 5 :
			red = 13;
			blue = 13;
			break;
	}
	
	setColour(red, green, blue, white);
	colour++;
	if (colour > 6)
	{
		colour = 0;
	}
}

void light::setColour(int red, int green, int blue, int white)
{
	for(int i = 0; i < SEGMENT_AMOUNT; i++)
	{
		aSegment[i].setColour(red, green, blue, white);
	}
}

void light::setSegments(timeText aTimeText)
{	
	for(int i = 0; i < SEGMENT_AMOUNT; i++)
	{
		aSegment[i].setSegmentOff();	
	}
	
	if(aTimeText.het)
	{
		aSegment[HET].setSegmentOn();	
	}
	
	if(aTimeText.is)
	{
		aSegment[IS].setSegmentOn();
	}
	
	if(aTimeText.was)
	{
		aSegment[WAS].setSegmentOn();
	}
	
	if(aTimeText.vijf)
	{
		aSegment[VIJF].setSegmentOn();
	}
	
	if(aTimeText.tien)
	{
		aSegment[TIEN].setSegmentOn();
	}
	
	if(aTimeText.kwart)
	{
		aSegment[KWART].setSegmentOn();
	}
		
	if(aTimeText.voor)
	{
		aSegment[VOOR].setSegmentOn();
	}
	
	if(aTimeText.over)
	{
		aSegment[OVER].setSegmentOn();
	}
	
	if(aTimeText.precies)
	{
		aSegment[PRECIES].setSegmentOn();
	}
					
	if(aTimeText.half)
	{
		aSegment[HALF].setSegmentOn();
	}
	
	if(aTimeText.eenUur)
	{
		aSegment[EEN_UUR].setSegmentOn();
	}
	
	if(aTimeText.tweeUur)
	{
		aSegment[TWEE_UUR].setSegmentOn();
	}
	
	if(aTimeText.drieUur)
	{
		aSegment[DRIE_UUR].setSegmentOn();
	}
	
	if(aTimeText.vierUur)
	{
		aSegment[VIER_UUR].setSegmentOn();
	}
	
	if(aTimeText.vijfUur)
	{
		aSegment[VIJF_UUR].setSegmentOn();
	}
	
	if(aTimeText.zesUur)
	{
		aSegment[ZES_UUR].setSegmentOn();
	}
	
	if(aTimeText.zevenUur)
	{
		aSegment[ZEVEN_UUR].setSegmentOn();
	}
	
	if(aTimeText.achtUur)
	{
		aSegment[ACHT_UUR].setSegmentOn();
	}
	
	if(aTimeText.negenUur)
	{
		aSegment[NEGEN_UUR].setSegmentOn();
	}
	
	if(aTimeText.tienUur)
	{
		aSegment[TIEN_UUR].setSegmentOn();
	}
	
	if(aTimeText.elfUur)
	{
		aSegment[ELF_UUR].setSegmentOn();
	}
	
	if(aTimeText.twaalfUur)
	{
		aSegment[TWAALF_UUR].setSegmentOn();
	}
	
	if(aTimeText.uur)
	{
		aSegment[UUR].setSegmentOn();
	}	
}

void light::update()
{
	timeText aTimeText;
	
	aTimeText = theTimeClock.parseTime(theTimeClock.getTime());
	
	setSegments(aTimeText);
	
	setLight();
}

void light::startUpCycle()
{

}