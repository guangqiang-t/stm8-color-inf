#ifndef _bsp_color_H_
#define _bsp_color_H_

#include "stm8s.h"

extern enum frep_percent;
extern enum fliter_color;

void color_config(void);
void set_frep_percent(uint8_t p);
void set_fliter_color(uint8_t cf);
void start_color_get(void);
void end_color_get(void);

#endif //_bsp_color_H_

