#include "bsp_audio.h"
#include "stm8s.h"
#include "bsp_delay.h"

void audio_config(void)
{
  GPIO_Init(GPIOE,(GPIO_Pin_TypeDef)(GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_6),GPIO_MODE_OUT_PP_LOW_SLOW);
}

void play_edge(void)
{
	GPIO_WriteHigh(GPIOE,GPIO_PIN_3);
	delay_ms(10);
	GPIO_WriteLow(GPIOE,GPIO_PIN_3);
}

void Immidiatly_play(void)
{
  GPIO_WriteHigh(GPIOE,GPIO_PIN_0);
}