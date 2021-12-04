
#  SAA1064 Arduino lib

Hey! This library has been designed to work with the Xserve Raid front panel LightShow board. The functionality of this library allows you to transfer two values of the **uint8_t** format to the indicator, setting the percentage from 0 to 100 and the value of the network indicator.

##  Includes

List of libraries required for assembly:

1. --

##  Use

1. It is necessary to connect 1 and 12 pins of the top SAA1064 on the board. This is necessary so that they receive different addresses.

![Pinning](https://github.com/murxy/SAA1064/blob/main/img/pinning.jpg)

2. It is necessary to connect the SDA and SCL pins on both microcircuits to combine the two I2C lines into one.

3. In the constructor of the class, create two objects and pass addresses to them. If you connected everything correctly, then the left row will receive the address 0x38, and the right row will receive the address 0x3B.

4. Now you can access objects through the constructor and pass values to them using "value"
