#include "bsp_delay.h"

void set_clk_HSI16(void)
{
  CLK_HSICmd(ENABLE);
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
}


void delay_us(uint16_t time)
{
#if 1
  while(time--)
  {
     asm("nop");asm("nop");asm("nop");
     asm("nop");asm("nop");asm("nop");
     asm("nop");asm("nop");asm("nop");
     //asm("nop");asm("nop");asm("nop");
  }
#else

#endif
}

void delay_ms(uint16_t time)
{
  while(time--)
  {
    delay_us(1000);
  }
}