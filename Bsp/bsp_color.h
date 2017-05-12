#ifndef _bsp_color_H_
#define _bsp_color_H_

#include "stm8s.h"

enum frep_percent{pd=0,p2=1,p20=2,p100=3};
enum fliter_color{fr=0,fb=1,fc=2,fg=3};

extern volatile int16_t g_color_r,g_color_g,g_color_b;
extern float g_color_h,g_color_s,g_color_v;

void color_config(void);
void set_frep_percent(uint8_t p);
void set_fliter_color(uint8_t cf);
void start_color_get(void);
void end_color_get(void);
void tim3_config(void);
int16_t get_freq(void);
void get_color(void);
void RGB2HSV( float *h, float *s, float* v, int16_t r, int16_t g, int16_t b);
int16_t MAX(int16_t a,int16_t b,int16_t c );
int16_t MIN(int16_t a,int16_t b,int16_t c );
uint8_t _is_red(void);


#endif //_bsp_color_H_

