#  SAA1064 Arduino lib

Hey! This library has been designed to work with the Xserve Raid front panel LightShow board. The functionality of this library allows you to set the range between 0 and 23 (including) and set the value for this range, so you can enable indicators from 5 to 15 if you want. You also can enable and disable every led directly. If you want to enable the network indicator, you can use the same methods with id equals 0.

###  Includes

List of libraries required for assembly:

1. Wire.h

###  Use

1. It is necessary to connect ADR and **V**EE pins of the top SAA1064 on the board. This is necessary for they receive different addresses.

<p align="center">
  <img alt="Pinning sceme" src="https://user-images.githubusercontent.com/75093384/150635924-b2bd34b2-f1c1-4d93-9b3e-e07ff283e40c.png">
</p>

2. It is necessary to connect the SDA and SCL pins on connector to combine the two I2C lines into one.  
3. In the constructor of the class, create two objects and pass addresses to them. If you connected everything correctly, then the left row will receive the address 0x38, and the right row will receive the address 0x3B.
