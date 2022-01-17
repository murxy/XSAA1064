
#include <Wire.h>	// This library is required to be included as well
#include <XSAA1064.h>


XSAA1064 LeftColumn = XSAA1064(0x38);
XSAA1064 RightColumn = XSAA1064(0x3B);

void setup() {
LeftColumn.begin();
RightColumn.begin();
}

void loop() {
for (uint8_t i = 0; i < 101; i++){
  LeftColumn.value(i, 1);
  RightColumn.value(100-i, 1);
  delay(10);
}
void loop() {
for (uint8_t i = 0; i < 101; i++){
  LeftColumn.value(100-i, 0);
  RightColumn.value(i, 0);
  delay(10);
}
}
