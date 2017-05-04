#ifndef _bsp_uaet_H_
#define _bsp_uart_H_

#include "stm8s.h"

void uart1_config(void);
void uart1_send_char(uint8_t ch);
void uart1_put_string(uint8_t *p);

#endif
