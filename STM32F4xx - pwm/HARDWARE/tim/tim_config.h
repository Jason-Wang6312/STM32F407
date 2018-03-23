#ifndef __tim_config_H_
#define __tim_config_H_

/*包含相关的头文件*/
#include "stm32f4xx.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_rcc.h"

void tim1_config(u32 Prescaler,u32 Period);

#endif