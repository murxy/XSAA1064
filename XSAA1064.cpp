/******************************************************************************
 * Includes
 ******************************************************************************/
#include "XSAA1064.h"
#include <Wire.h>

/******************************************************************************
 * Definitions
 ******************************************************************************/
#define REG_CONTROL 0x00
#define REG_DIGIT1 0x01
#define REG_DIGIT2 0x02
#define REG_DIGIT3 0x03
#define REG_DIGIT4 0x04

/******************************************************************************
 * Constructors
 ******************************************************************************/
XSAA1064::XSAA1064(uint8_t address) {
    _Address = address;
}


/******************************************************************************
 * User API
 ******************************************************************************/
void XSAA1064::begin(uint8_t address) {
}
void XSAA1064::begin() {
    Wire.begin();
    Wire.beginTransmission(_Address);
    const uint8_t arr[2]{ REG_CONTROL, 0x27 };
    Wire.write(arr, 2);
    Wire.endTransmission();
    delay(100);
}

void XSAA1064::allon() {
    Wire.beginTransmission(_Address);
    const uint8_t arr[5]{ REG_DIGIT1, 0x7F, 0x7F, 0x7F, 0x7F };
    Wire.write(arr, 5);
    Wire.endTransmission();
}

void XSAA1064::alloff() {
    Wire.beginTransmission(_Address);
    const uint8_t arr[5]{ REG_DIGIT1, 0, 0, 0, 0 };
    Wire.write(arr, 5);
    Wire.endTransmission();
}

void XSAA1064::value(uint8_t perc, uint8_t link) {
    Wire.beginTransmission(_Address);
    if(perc == 0) {
        uint8_t arr[5]{ REG_DIGIT1, (0 + link), 0, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 0 && perc < 6) {
        uint8_t arr[5]{ REG_DIGIT1, (B00000010 + link), 0, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 5 && perc < 10) {
        uint8_t arr[5]{ REG_DIGIT1, (B00000010 + link), 0, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 9 && perc < 15) {
        uint8_t arr[5]{ REG_DIGIT1, (B00000110 + link), B00000010, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 14 && perc < 19) {
        uint8_t arr[5]{ REG_DIGIT1, (B00000110 + link), B00000110, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 18 && perc < 23) {
        uint8_t arr[5]{ REG_DIGIT1, (B00001110 + link), B00000110, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 18 && perc < 27) {
        uint8_t arr[5]{ REG_DIGIT1, (B00001110 + link), B00001110, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 26 && perc < 32) {
        uint8_t arr[5]{ REG_DIGIT1, (B00011110 + link), B00001110, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 31 && perc < 36) {
        uint8_t arr[5]{ REG_DIGIT1, (B00011110 + link), B00011110, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 35 && perc < 41) {
        uint8_t arr[5]{ REG_DIGIT1, (B00111110 + link), B00011110, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 40 && perc < 45) {
        uint8_t arr[5]{ REG_DIGIT1, (B00111110 + link), B00111110, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 44 && perc < 49) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B00111110, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 48 && perc < 54) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, 0, 0 };
        Wire.write(arr, 5);
    } else if(perc > 53 && perc < 58) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, B00000001, 0 };
        Wire.write(arr, 5);
    } else if(perc > 57 && perc < 62) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, B00000001, B00000001 };
        Wire.write(arr, 5);
    } else if(perc > 61 && perc < 67) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, B00000011, B00000001 };
        Wire.write(arr, 5);
    } else if(perc > 66 && perc < 71) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, B00000011, B00000011 };
        Wire.write(arr, 5);
    } else if(perc > 70 && perc < 75) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, B00000111, B00000011 };
        Wire.write(arr, 5);
    } else if(perc > 74 && perc < 80) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, B00000111, B00000111 };
        Wire.write(arr, 5);
    } else if(perc > 79 && perc < 84) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, B00001111, B00000111 };
        Wire.write(arr, 5);
    } else if(perc > 83 && perc < 88) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, B00001111, B00001111 };
        Wire.write(arr, 5);
    } else if(perc > 87 && perc < 93) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, B00011111, B00001111 };
        Wire.write(arr, 5);
    } else if(perc > 92 && perc < 97) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, B00111111, B00001111 };
        Wire.write(arr, 5);
    } else if(perc > 96 && perc < 101) {
        uint8_t arr[5]{ REG_DIGIT1, (B01111110 + link), B01111110, B01111111, B00001111 };
        Wire.write(arr, 5);
    }
    Wire.endTransmission();
}
