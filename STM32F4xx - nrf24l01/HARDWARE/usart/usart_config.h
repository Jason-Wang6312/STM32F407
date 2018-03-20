#ifndef __usart_config_H_
#define __usart_config_H_

/*包含相关的头文件*/
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "nvic_config.h"
#include "stdio.h" //重定向printf

void usatr1_config(u32 bound);
int fputc(int ch, FILE *f);

#endif