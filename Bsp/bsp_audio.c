#include "bsp_audio.h"
#include "bsp_delay.h"

void audio_config(void)
{
  GPIO_Init(GPIOE,(GPIO_Pin_TypeDef)(GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_6),GPIO_MODE_OUT_PP_LOW_SLOW);
  GPIO_Init(GPIOE,(GPIO_Pin_TypeDef)(GPIO_PIN_1),GPIO_MODE_IN_FL_NO_IT);
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
void wait_audio_stoped(void)
{
  BitStatus pre=RESET;
  BitStatus now=RESET;
  uint16_t i=0;
  volatile uint8_t flag=1;

  while(flag)
  {
  pre=now;
  now=GPIO_ReadInputPin(GPIOE,GPIO_PIN_1);
    if((now == RESET) && (pre == RESET))
    {
      i++;
    }
    delay_us(100);
    if(i>5) 
    {
      printf("audio stoped\r\n");
      flag=0;
    }
  }
}
