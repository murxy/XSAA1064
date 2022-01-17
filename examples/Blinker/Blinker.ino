
#include <Wire.h>	// This library is required to be included as well
#include <XSAA1064.h>


SAA1064 LeftColumn = SAA1064(0x38);
SAA1064 RightColumn = SAA1064(0x3B);

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
