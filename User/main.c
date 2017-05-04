#include "stm8s.h"
#include <stdio.h>
#include "bsp_delay.h"
#include "bsp_uart.h"
#include "bsp_led.h"
#include "bsp_audio.h"
#include "bsp_color.h"

int main (void)
{
  set_clk_HSI16();
  uart1_config();
  led_config();
  audio_config();
  color_config();
  led_on(1);led_on(2);led_on(3);led_on(4);
  start_color_get();
  play_edge();
  //Immidiatly_play();
  while(1)
  {

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
    printf("Wrong parameters value: file %s on line %d\r\n", file, line);
  /* Infinite loop */
  while (1)
  {
    
  }
}
#endif