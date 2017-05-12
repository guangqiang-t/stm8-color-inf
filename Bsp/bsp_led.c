#include "stm8s.h"
#include "bsp_led.h"
#include "bsp_delay.h"

void led_config(void)
{
  GPIO_Init(GPIOC,(GPIO_Pin_TypeDef)(GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4),GPIO_MODE_OUT_PP_LOW_SLOW);
  led_self_test();
}

void led_on(uint8_t index)
{
  switch(index)
  {
    case 1:
	{
		GPIO_WriteHigh(GPIOC,GPIO_PIN_4);
		break;
	}
	case 2:
	{
		GPIO_WriteHigh(GPIOC,GPIO_PIN_2);
		break;
	}
	case 3:
	{
		GPIO_WriteHigh(GPIOC,GPIO_PIN_3);
		break;
	}
	case 4:
	{
		GPIO_WriteHigh(GPIOC,GPIO_PIN_1);
		break;
	}
	default:break;
  }
  //printf("led1 is on \r\n");
}


void led_off(uint8_t index)
{
  switch(index)
  {
    case 1:
	{
		GPIO_WriteLow(GPIOC,GPIO_PIN_4);
		break;
	}
	case 2:
	{
		GPIO_WriteLow(GPIOC,GPIO_PIN_2);
		break;
	}
	case 3:
	{
		GPIO_WriteLow(GPIOC,GPIO_PIN_3);
		break;
	}
	case 4:
	{
		GPIO_WriteLow(GPIOC,GPIO_PIN_1);
		break;
	}
	default:break;
  }
}

void led_self_test(void)
{
	led_on(1);
	delay_ms(200);
	led_on(2);
	delay_ms(200);
	led_on(3);
	delay_ms(200);
	led_on(4);
	delay_ms(400);
	led_off(1);
	delay_ms(200);
	led_off(2);
	delay_ms(200);
	led_off(3);
	delay_ms(200);
	led_off(4);
	delay_ms(200);
	
}