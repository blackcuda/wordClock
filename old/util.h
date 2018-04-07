/*
 * Util.h
 *
 * Created: 25-3-2018 20:14:24
 *  Author: Jeroen
 */ 


#ifndef UTIL_H_
#define UTIL_H_


#define LED_AMOUNT 92

#define HET_LOW 0
#define HET_HIGH 2
#define IS_LOW 3
#define IS_HIGH 4
#define WAS_LOW 5
#define WAS_HIGH 7
#define VIJF_LOW 8
#define VIJF_HIGH 11
#define TIEN_LOW 12
#define TIEN_HIGH 15
#define KWART_LOW 16
#define KWART_HIGH 20
#define VOOR_LOW 21
#define VOOR_HIGH 24
#define OVER_LOW 25
#define OVER_HIGH 28
#define PRECIES_LOW 29
#define PRECIES_HIGH 35
#define HALF_LOW 36
#define HALF_HIGH 39
#define ELF_UUR_LOW 40
#define ELF_UUR_HIGH 42
#define VIJF_UUR_LOW 43
#define VIJF_UUR_HIGH 46
#define TWEE_UUR_LOW 47
#define TWEE_UUR_HIGH 50
#define EEN_UUR_LOW 51
#define EEN_UUR_HIGH 53
#define VIER_UUR_LOW 54
#define VIER_UUR_HIGH 57
#define TIEN_UUR_LOW 58
#define TIEN_UUR_HIGH 61
#define TWAALF_UUR_LOW 62
#define TWAALF_UUR_HIGH 67
#define DRIE_UUR_LOW 68
#define DRIE_UUR_HIGH 71
#define NEGEN_UUR_LOW 72
#define NEGEN_UUR_HIGH 76
#define ACHT_UUR_LOW 77
#define ACHT_UUR_HIGH 80
#define ZES_UUR_LOW 81
#define ZES_UUR_HIGH 83
#define ZEVEN_UUR_LOW 84
#define ZEVEN_UUR_HIGH 88
#define UUR_LOW 89
#define UUR_HIGH 91

enum segment 
{ 
	HET,
	IS,
	WAS,
	VIJF,
	TIEN,
	KWART,
	VOOR,
	OVER,
	PRECIES,
	HALF,
	ELF_UUR,
	VIJF_UUR,
	TWEE_UUR,
	EEN_UUR,
	VIER_UUR,
	TIEN_UUR,
	TWAALF_UUR,
	DRIE_UUR,
	NEGEN_UUR,
	ACHT_UUR,
	ZES_UUR,
	ZEVEN_UUR,
	UUR,
};

#define SEGMENT_AMOUNT (UUR - HET); // calculate the amount of segments in the enum segment.




#endif /* UTIL_H_ */