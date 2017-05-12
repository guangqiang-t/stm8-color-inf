#include "bsp_uart.h"
#include <stdio.h>

void uart1_config(void)
{
  UART1_DeInit();
  UART1_Init(115200,
              UART1_WORDLENGTH_8D,
              UART1_STOPBITS_1,
              UART1_PARITY_NO,
              UART1_SYNCMODE_CLOCK_DISABLE,
              UART1_MODE_TXRX_ENABLE);//115200 8N1
  
}

//int fputc(int ch, FILE *f)
//{
//  /* Loop until the end of transmission */
//  while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
//  /* Write a character to the UART1 */
//  UART1_SendData8(ch);
//  return (ch);
//}

void uart1_send_char(uint8_t ch)
{
    /* Loop until the end of transmission */
  while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
  /* Write a character to the UART1 */
  UART1_SendData8((uint8_t)ch);
}

void uart1_put_string(uint8_t *p)
{
  while(*p)
  {
    uart1_send_char(*p++);
  }
}

/**
  * @brief Retargets the C library printf function to the UART.
  * @param c Character to send
  * @retval char Character sent
  */
int putchar (int ch)
{ 
  /* Loop until the end of transmission */
  while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
  /* Write a character to the UART1 */
  UART1_SendData8((uint8_t)ch);
  return (ch);
}


