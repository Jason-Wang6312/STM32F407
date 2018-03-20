#include "nvic_config.h"

/*设置中断优先级*/
void usart1_nvic_config(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    
    //优先级分组
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    
    //配置结构体参数
    NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
}

void tim1_nvci_config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn; //设置定时器1 中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //设置抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //设置子优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //使能IRQ 中断
    NVIC_Init(&NVIC_InitStructure);
    
}