#include "IRQHandler_config.h"

/*USART1中断处理*/
void USART1_IRQHandler(void)
{
    u8 rev_data;
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) //判断读寄存器是否非空
    {
      rev_data = USART_ReceiveData(USART1);
      printf("rev_data=%6d \n", rev_data);
      while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
      if(rev_data == 0x00)
      {
        GPIO_ResetBits(GPIOA, GPIO_Pin_6); //点亮LED
      }
      else if(rev_data == 0x01)
      {
        GPIO_SetBits(GPIOA, GPIO_Pin_6); //熄灭LED
      }
      else if(rev_data == 0x02)
      {
        GPIO_ResetBits(GPIOA, GPIO_Pin_7); //点亮LED
      }
      else if(rev_data == 0x03)
      {
        GPIO_SetBits(GPIOA, GPIO_Pin_7); //点亮LED
      }
    }
    USART_ClearITPendingBit(USART1, USART_IT_RXNE);//清除接受中断标志
    USART_ClearFlag(USART1, USART_FLAG_RXNE);

}


void TIM1_UP_TIM10_IRQHandler(void)
{
    
    if(TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)
    {
    GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_6))); 
    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_7)));
   // printf("ok \n");
    }
//    TIM_ClearFlag(TIM1,TIM_FLAG_Update);//进入中断先清除更新标志
    TIM_ClearITPendingBit(TIM1,TIM_FLAG_Update);
}
