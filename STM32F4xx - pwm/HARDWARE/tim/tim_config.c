#include "tim_config.h"
#include "main.h"

void tim1_config(u32 Prescaler,u32 Period)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;   
    NVIC_InitTypeDef NVIC_InitStructure;
        
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);                         //开启TIM1的时钟
    
    
    /*
    。另外定时器部分，如果所在总线（ APB1/APB2 ）的分频系数为 1，那么就不倍频，
    如果不为 1（比如 2/4/8/16 2/4/8/16 2/4/8/16 ）， 那么就会 2倍频（ Fabpx*2 ）后，作为定时器钟输入
    */
    //时基单元的初始化 168M  1S
    TIM_TimeBaseInitStructure.TIM_Prescaler = Prescaler;                          //时钟预分频数
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;             //向上计数模式
    TIM_TimeBaseInitStructure.TIM_Period = Period;                              //自动重装载寄存器的值
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;                 //采样分频
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0x00;
    TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn; //设置定时器1 中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //设置抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //设置子优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //使能IRQ 中断
    NVIC_Init(&NVIC_InitStructure);
    
    TIM_ClearFlag(TIM1,TIM_FLAG_Update);   //必须先清除配置时候产生的更新标志
    TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);   //使能中断，中断事件为定时器工薪事件
    TIM_Cmd(TIM1,ENABLE);    //使能定时器
}

void TIM1_UP_TIM10_IRQHandler(void)
{
    
    if(TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)
    {
    GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_6))); 
    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_7)));
    printf("pwm1val=%6d \n", pwm1val);
    }    
    TIM_ClearFlag(TIM1,TIM_FLAG_Update);//进入中断先清除更新标志
    TIM_ClearITPendingBit(TIM1,TIM_FLAG_Update);
}
