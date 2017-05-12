#include "bsp_color.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include <stdio.h>

volatile int16_t g_color_r=0,g_color_g=0,g_color_b=0;
float g_color_h=0.0,g_color_s=0.0,g_color_v=0.0;
void color_config(void)
{
	  GPIO_Init(GPIOD,(GPIO_Pin_TypeDef)(GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7),GPIO_MODE_OUT_PP_HIGH_SLOW);
	  GPIO_Init(GPIOD,(GPIO_Pin_TypeDef)(GPIO_PIN_5),GPIO_MODE_OUT_PP_HIGH_SLOW);
          GPIO_Init(GPIOD,(GPIO_Pin_TypeDef)(GPIO_PIN_2),GPIO_MODE_IN_FL_NO_IT);
	  set_frep_percent(p2);
          set_fliter_color(fc);
}

void set_frep_percent(uint8_t p)
{
	switch(p)
	{
		case pd:
		{
			GPIO_WriteLow(GPIOD,GPIO_PIN_3);
			GPIO_WriteLow(GPIOD,GPIO_PIN_4);
			break;
		}
		case p2:
		{
			GPIO_WriteLow(GPIOD,GPIO_PIN_3);
			GPIO_WriteHigh(GPIOD,GPIO_PIN_4);
			break;
		}
		case p20:
		{
			GPIO_WriteHigh(GPIOD,GPIO_PIN_3);
			GPIO_WriteLow(GPIOD,GPIO_PIN_4);
			break;
		}		
		case p100:
		{
			GPIO_WriteHigh(GPIOD,GPIO_PIN_3);
			GPIO_WriteHigh(GPIOD,GPIO_PIN_4);
			break;
		}
		default:break;
	}
}

void set_fliter_color(uint8_t cf)
{
		switch(cf)
	{
		case fr:
		{
			GPIO_WriteLow(GPIOD,GPIO_PIN_7);
			GPIO_WriteLow(GPIOD,GPIO_PIN_6);
			break;
		}
		case fb:
		{
			GPIO_WriteLow(GPIOD,GPIO_PIN_7);
			GPIO_WriteHigh(GPIOD,GPIO_PIN_6);
			break;
		}
		case fc:
		{
			GPIO_WriteHigh(GPIOD,GPIO_PIN_7);
			GPIO_WriteLow(GPIOD,GPIO_PIN_6);
			break;
		}		
		case fg:
		{
			GPIO_WriteHigh(GPIOD,GPIO_PIN_7);
			GPIO_WriteHigh(GPIOD,GPIO_PIN_6);
			break;
		}
		default:break;
	}
	
}

void start_color_get(void)
{
  GPIO_WriteLow(GPIOD,GPIO_PIN_5);
}

void end_color_get(void)
{
  GPIO_WriteHigh(GPIOD,GPIO_PIN_5);
}

void tim3_config(void)
{
  TIM3_DeInit();
  TIM3_ICInit(TIM3_CHANNEL_1,TIM3_ICPOLARITY_RISING,TIM3_ICSELECTION_DIRECTTI,TIM3_ICPSC_DIV1,0x00);
  TIM3_ITConfig(TIM3_IT_CC1,ENABLE);
  TIM3_Cmd(ENABLE);
  TIM3_ClearFlag(TIM3_FLAG_CC1);
}

void tim2_config(void)
{

}

int16_t get_freq(void)
{
  BitStatus pre=RESET;
  BitStatus now=RESET;
  uint16_t freq=0;
  uint16_t i=0;
  
  for(i=0;i<2000;i++)
  {
    pre=now;//shift
    now=GPIO_ReadInputPin(GPIOD,GPIO_PIN_2);
    if((now != RESET) && (pre == RESET))
    {
      freq++;
    }
    delay_us(100);
  }
  
  return freq;
}


void get_color(void)
{
  
  led_on(1);led_on(2);led_on(3);led_on(4);

  set_fliter_color(fr);
  start_color_get();
  delay_ms(10);
  g_color_r=get_freq();
  end_color_get();
  printf("%d  ",g_color_r);
  
  
  set_fliter_color(fg);
  start_color_get();
  delay_ms(10);
  g_color_g=get_freq();
  end_color_get();
  printf("#%d  ",g_color_g);
  
  
  set_fliter_color(fb);
  start_color_get();
  delay_ms(10);
  g_color_b=get_freq();
  end_color_get();
  printf("#%d\r\n",g_color_b);
  RGB2HSV(&g_color_h,&g_color_s,&g_color_v,g_color_r,g_color_g,g_color_b);
  //printf("%f  %f  %f\r\n",g_color_h,g_color_s,g_color_v);
  led_off(1);led_off(2);led_off(3);led_off(4);
}

#if 0

#else

void RGB2HSV( float *h, float *s, float* v, int16_t r, int16_t g, int16_t b)
{
   float min, max, delta;
   double th=0;
   //r*=2;
   //g*=2;
   //b*=2;
//   if(r>255)r=255;
//   if(g>255)g=255;
//   if(b>255)b=255;
    min = MIN( r, g, b );
    max = MAX( r, g, b );
    *v = max;               // v
    delta = max - min;
    if( max != 0 )
        *s = (float)((float)(delta) /(float) (max));       // s
    else
    {
        // r = g = b = 0        // s = 0, v is undefined
        *s = 0;
        *v = 0;
        *h = -1;
        return;
    }
    if( r == max )
        th = 0 + (float)( g - b ) / (float)(delta); // between yellow & magenta
    else if( g == max )
        th = 2 + (float)( b - r ) / (float)(delta); // between cyan & yellow
    else
        th = 4 + (float)( r - g ) / (float)(delta); // between magenta & cyan
    th =th * 6.0;               // degrees
    if( th < 0 )
    {
        th += 360;
        *h=th;
    }
    else
    {
        *h=th;    
    }
}
#endif

int16_t MIN(int16_t a,int16_t b,int16_t c)
{
	uint16_t min=0;
	min = (a<=b) ?a:b;
	min = (min<=c) ?min:c;
        return min;;
}

int16_t MAX(int16_t a,int16_t b,int16_t c )
{
	uint16_t max=0;
	max = (a>=b) ?a:b;
	max = (max>=c) ?max:c;
        return max;
}

uint8_t _is_red(void)
{
  if(g_color_r > (1.5*(g_color_g+g_color_b)))
  {
      return 1;
  }
  else
  {
      return 0;
  }
}
