#ifndef _MACHINE_SPECIFIC_H
#define _MACHINE_SPECIFIC_H

/*       Name   WiringPi   */
#define H_MOSI   12
#define H_MISO   13
#define H_SCLK    14
#define H_101   21
#define H_100    22
#define H_108    23
#define H_97    24
#define H_CE0    10
#define H_118    11
#define H_99    26
#define H_98   27
#define H_102   5
#define H_103   6

/*      button   Pin      */
#define KEY1   H_MOSI
#define KEY2   H_97
#define KEY3   H_MISO
#define KEY4   H_CE0
#define KEY5   H_SCLK
#define KEY6   H_118
#define KEY7   H_101
#define KEY8   H_99
#define KEY9   H_100
#define KEY0   H_98
#define KEYEQ   H_108
#define KEYADD   H_102
#define KEYSUB   H_103

/**
  * Keypad scan delay.
  */
#define KEYPAD_SCAN_DELAY 1000


/**
  * CLCD connection.
  */
#define CLCD_D4		2
#define CLCD_D5		3
#define CLCD_D6		1
#define CLCD_D7		4
#define CLCD_RS 	7
#define CLCD_EN 	0

#endif /* _MACHINE_SPECIFIC_H */
