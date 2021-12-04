
#include <Wire.h>	// This library is required to be included as well
#include <SAA1064.h>


SAA1064 Display1 = SAA1064(0x3B);
SAA1064 Display2 = SAA1064(0x38);

void setup() {
Display1.begin();
Display2.begin();
}

void loop() {
for (uint8_t i = 0; i < 101; i++){
  Display1.value(i, 1);
  Display2.value(100-i, 1);
  delay(10);
}
}
