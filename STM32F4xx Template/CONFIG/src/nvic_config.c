#include "nvic_config.h"

/*�����ж����ȼ�*/
void usart1_nvic_config(void)
{
    NVIC_InitTypeDef NVIC_InitStruct;
    
    //���ȼ�����
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    
    //���ýṹ�����
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
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn; //���ö�ʱ��1 �ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //������ռ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //���������ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ʹ��IRQ �ж�
    NVIC_Init(&NVIC_InitStructure);
    
}