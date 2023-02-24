# STM32 clock with 7-segment display

 - STM32F303xD documentation: https://www.st.com/resource/en/datasheet/stm32f303re.pdf
 - HCF4056BE documentation: https://www.st.com/resource/en/datasheet/cd00002658.pdf
 - 5161BS documentation: http://www.xlitx.com/datasheet/5161BS.pdf

## Overview
The above project is an example of using the STM32F3 microcontroller to control a 7-segment display via a 4056 decoder (*7seg_4056.c*). For demonstration purposes, RTC control has also been added (*clock.c*).

## Hardware
The following HW has been used:

 - 1x Nucleo-64 development board;
 - 1x BCD to 7-segment decoder HCF4056BE;
 - 2x push buttons;
 - 5x 1.2kΩ resistors;
 - 4x 7-segment displays 5161BS
 - 1x breadboard

![STM32 clock scheme](https://i.imgur.com/88TFxSO.jpeg)

## Software
Software is written using STM32CubeMX Code Generator - *stm32-clock.ioc* file is attached. In addition to the generated peripheral files, I developed the following ones:

 - *main.c*;
 - *7seg_4056.h* & *7seg_4056.c* - 4056 decoder and 7-segment display library;
 - *clock.h* & *clock.c* - RTC library;

```
WARNING: rtc.c file is also edited. 
In case of using Code Generator replace 65 and 66 lines with following:
		sTime.Hours = rtc_time.d_hours * 10 + rtc_time.u_hours;
		sTime.Minutes = rtc_time.d_minutes * 10 + rtc_time.u_minutes;
```
