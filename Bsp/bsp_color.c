#include "bsp_color.h"


enum frep_percent{pd=0,p2=1,p20=2,p100=3};
enum fliter_color{fr=0,fb=1,fc=2,fg=3};

void color_config(void)
{
	  GPIO_Init(GPIOD,(GPIO_Pin_TypeDef)(GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6|GPIO_PIN_7),GPIO_MODE_OUT_PP_LOW_SLOW);
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
			GPIO_WriteLow(GPIOD,GPIO_PIN_3);
			GPIO_WriteHigh(GPIOD,GPIO_PIN_4);
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
			GPIO_WriteLow(GPIOD,GPIO_PIN_7);
			GPIO_WriteHigh(GPIOD,GPIO_PIN_6);
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