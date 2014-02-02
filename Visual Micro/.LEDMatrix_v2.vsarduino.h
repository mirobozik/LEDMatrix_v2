//Board = Arduino Uno
#define __AVR_ATmega328P__
#define ARDUINO 105
#define F_CPU 16000000L
#define __AVR__
extern "C" void __cxa_pure_virtual() {;}

//
//
void effect_1(int delayVal);
void effect_2(int delayVal);
void effect_3(int delayVal);
void effect_4(int delayVal, int colIndex);
void effect_5(int delayValMin, int delayValMax);

#include "D:\applications\arduino-1.0.5\hardware\arduino\variants\standard\pins_arduino.h" 
#include "D:\applications\arduino-1.0.5\hardware\arduino\cores\arduino\arduino.h"
#include "D:\projects_arduino\LEDMatrix_v2\LEDMatrix_v2.ino"
