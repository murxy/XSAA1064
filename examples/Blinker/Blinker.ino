
#include <Wire.h>	// This library is required to be included as well
#include <XSAA1064.h>


murxy::XSAA1064 LeftColumn(0x38);
murxy::XSAA1064 RightColumn(0x3B);

void setup() {
    LeftColumn.begin();
    RightColumn.begin();
}

void loop() {
    const uint8_t count = murxy::XSAA1064::ledCount();
    for (uint8_t i = 0; i < count; i++){
        LeftColumn.set(0, i, true);
        RightColumn.set(0, count - i, true);
        delay(10);
    }
}
