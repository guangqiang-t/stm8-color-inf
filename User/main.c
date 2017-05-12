#include "stm8s.h"
#include <stdio.h>
#include "bsp_delay.h"
#include "bsp_uart.h"
#include "bsp_led.h"
#include "bsp_audio.h"
#include "bsp_color.h"

#define MIAN_LOG(x) printf x


uint8_t inf_gen(void);


int main (void)
{
  uint16_t n=0;
  uint16_t n_raw=0;
  uint16_t play_cnt=0;
  set_clk_HSI16();
  GPIO_Init(GPIOD,(GPIO_Pin_TypeDef)(GPIO_PIN_0),GPIO_MODE_IN_FL_NO_IT);
  uart1_config();
  MIAN_LOG(("uart init ok\r\n"));
  led_config();
  MIAN_LOG(("self test\r\n"));
  audio_config();
  MIAN_LOG(("audio init ok\r\n"));
  color_config();
  MIAN_LOG(("color init ok\r\n"));
  MIAN_LOG(("start scan color...\r\n"));
  printf("this id \%f test %f\r\n",-1.2);
  while(1)
  {
    printf("enter color scan\r\n");
    get_color();
    n=_is_red();
    if(n)
    {
      printf("__IsRed\r\n");
      if(inf_gen())
      { 
        printf("inf_gen\r\n");         
          if(n_raw==0)
          {
          n_raw=2;
          }
       }
       
      if(n_raw)
      {
        n_raw--;
        printf("play  audio \r\n");
        play_edge();
        wait_audio_stoped();
      }
      
     
    }
    delay_ms(1000);
  }
  return 0;
}

//---------------------------------------------------------


uint8_t inf_gen(void)
{
  BitStatus pre=RESET;
  BitStatus now=RESET;
  uint16_t i=0;
  volatile uint8_t cnt=10;

  while(cnt--)
  {
  pre=now;
  now=GPIO_ReadInputPin(GPIOD,GPIO_PIN_0);
    if((now != RESET) && (pre != RESET))
    {
      i++;
    }
    delay_us(100);
    if(i>3) 
    {
      printf("inf_gen\r\n");
      return 1;
    }
  }
  return 0;
}





#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    printf("Wrong parameters value: file %s on line %d\r\n",file,line);
  /* Infinite loop */
  while (1)
  {

  }
}
#endif