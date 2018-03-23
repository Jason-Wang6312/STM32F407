#include "usart_config.h"
#include "main.h"
void usatr1_config(u32 bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStruct;   
    USART_InitTypeDef USART_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);                       //时钟usart使能
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);                       //时钟gpio使能
    
    /*复用引脚配置*/
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);                     
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);
    
    /*配置TX,RX为复用*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;                     //选择引脚
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                //选择模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;                          //选择速率
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                              //选择端口模式PP推挽OD开漏
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;                                //选择上拉UP上拉down下拉NOPULL不拉
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /*配置usart1
    **波特率  传输位  停止位  校验位
      115200   8       1      NO
    */
    USART_InitStructure.USART_BaudRate = bound;                                //波特率
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;                 //字长8位
    USART_InitStructure.USART_StopBits = USART_StopBits_1;                      //1停止位
    USART_InitStructure.USART_Parity = USART_Parity_No;                         //不校验
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;             //使能接受发送
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  //不流控
    USART_Init(USART1,&USART_InitStructure);
    
    //NVIC配置结构体参数
    NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
     
    //开中断
    USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
    USART_Cmd(USART1,ENABLE);
    
}


//重定向printf
int fputc(int ch, FILE *f)
{
    while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET)
    {
    }
    USART_SendData(USART1,(uint8_t) ch);
    return ch;
}

/*USART1中断处理*/
void USART1_IRQHandler(void)
{
    u16 rev_data;
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) //判断读寄存器是否非空
    {
      rev_data = USART_ReceiveData(USART1) * 10;
      //printf("rev_data=%6d \n", rev_data);
      while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
      
      if(rev_data >= 500)
      {
        pwm1val = 500;
      }
      else
      {
          if(rev_data <= 250)
          {
            pwm1val = 250;
          }
          else
          {
            pwm1val = rev_data;
          }
      }
      
//      pwm1val = rev_data;
      
    }
    USART_ClearFlag(USART1, USART_FLAG_RXNE);
    USART_ClearITPendingBit(USART1, USART_IT_RXNE);//清除接受中断标志
    

}
