/*** I2C ***/ 
sudo apt-get install -y i2c-tools
sudo apt install libi2c-dev

- Query i2c devices: 
sudo i2cdetect -r 0 # enumerate bus 0:

     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
50: 50 51 52 53 54 55 56 57 -- -- -- -- -- -- -- -- 
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
70: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 

- Scan the register data:
sudo i2cdump -y 0 0x57

- Write data to register: 
sudo i2cset -y 0 0x57 0x90 0x55 (I2c dev:0, addr: 0x57, reg: 0x90, data: 0x55)

- Read register data:
sudo i2cget -y 0 0x57 0x90

- Use extern "C" if compile for C++ and use -li2c to link the library
extern "C"
{
    #include<linux/i2c-dev.h>
    #include <i2c/smbus.h>
}

