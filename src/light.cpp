/*
 * light.cpp
 *
 * Created: 7-4-2018 18:02:52
 *  Author: Jeroen
 */ 

#include "light.hpp"

light::light()
	:led(), aSegment(), brightness(0)
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
	
	for(int i = 0; i < SEGMENT_AMOUNT; i++)
	{
		aSegment[i].setSegmentOn();
	}
	
	for(int i = 0; i < SEGMENT_AMOUNT; i++)
	{
		if(i%2 == 0)
		aSegment[i].setColour(0,20,0,0);
		else
		{
			aSegment[i].setColour(0,0,20,0);
		}
	}

	setLight();
}

light::~light()
{
	
}

void light::setLight()
{
	int ledIndex = 0;
	int j = 0;
	
	for(int i = 0; i < SEGMENT_AMOUNT; i++)
	{
		for(j = ledIndex; j < ledIndex + aSegment[i].getLength(); j++)
		{
			led[j] = aSegment[i].getColour();
		}
		ledIndex = j;
	}
	
	ws2812_setleds_rgbw(led, LED_AMOUNT);
}

void light::setLightOn()
{
	setBrightness(255);
}

void light::setLightOff()
{
	setBrightness(0);
}

void light::setBrightness(int aBrightness)
{
	brightness = aBrightness;	
}

