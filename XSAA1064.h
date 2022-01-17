/*
Header file from SAA1064 lib for XServe Raid

www.murxy.link
*/

#ifndef XSAA1064_h
#define XSAA1064_h

#include "Arduino.h"
#include <inttypes.h>

class XSAA1064
{
  protected:
	uint8_t _Address;
  public:
    XSAA1064(uint8_t);
	void begin(uint8_t);
	void begin();
	void allon();
	void alloff();
	void value(uint8_t, uint8_t);
};

#endif
