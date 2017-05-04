#ifndef _bsp_led_H_
#define _bsp_led_H_

void led_config(void);
void led_on(uint8_t index);
void led_off(uint8_t index);
void led_self_test(void);

#endif//_bsp_led_H_
