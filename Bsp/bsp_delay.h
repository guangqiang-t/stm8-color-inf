#ifndef bsp_delay_H_
#define bsp_delay_H_

#include "stm8s.h"

void set_clk_HSI16(void);

void delay_us(uint16_t time);
void delay_ms(uint16_t time);
void Immidiatly_play(void);

#endif
