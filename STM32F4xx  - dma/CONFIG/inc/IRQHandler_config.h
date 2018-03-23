#ifndef __IRQHandler_config_H_
#define __IRQHandler_config_H_

/*包含相关的头文件*/
#include "stm32f4xx.h"
#include "usart_config.h"

void USART1_IRQHandler(void);
void TIM1_UP_TIM10_IRQHandler(void);

#endif