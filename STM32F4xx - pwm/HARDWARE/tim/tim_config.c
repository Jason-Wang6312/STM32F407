#include "tim_config.h"
#include "main.h"

void tim1_config(u32 Prescaler,u32 Period)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;   
    NVIC_InitTypeDef NVIC_InitStructure;
        
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);                         //����TIM1��ʱ��
    
    
    /*
    �����ⶨʱ�����֣�����������ߣ� APB1/APB2 ���ķ�Ƶϵ��Ϊ 1����ô�Ͳ���Ƶ��
    �����Ϊ 1������ 2/4/8/16 2/4/8/16 2/4/8/16 ���� ��ô�ͻ� 2��Ƶ�� Fabpx*2 ������Ϊ��ʱ��������
    */
    //ʱ����Ԫ�ĳ�ʼ�� 168M  1S
    TIM_TimeBaseInitStructure.TIM_Prescaler = Prescaler;                          //ʱ��Ԥ��Ƶ��
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;             //���ϼ���ģʽ
    TIM_TimeBaseInitStructure.TIM_Period = Period;                              //�Զ���װ�ؼĴ�����ֵ
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;                 //������Ƶ
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0x00;
    TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStructure);
    
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn; //���ö�ʱ��1 �ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //������ռ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; //���������ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ʹ��IRQ �ж�
    NVIC_Init(&NVIC_InitStructure);
    
    TIM_ClearFlag(TIM1,TIM_FLAG_Update);   //�������������ʱ������ĸ��±�־
    TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);   //ʹ���жϣ��ж��¼�Ϊ��ʱ����н�¼�
    TIM_Cmd(TIM1,ENABLE);    //ʹ�ܶ�ʱ��
}

void TIM1_UP_TIM10_IRQHandler(void)
{
    
    if(TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET)
    {
    GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_6))); 
    GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_7)));
    printf("pwm1val=%6d \n", pwm1val);
    }    
    TIM_ClearFlag(TIM1,TIM_FLAG_Update);//�����ж���������±�־
    TIM_ClearITPendingBit(TIM1,TIM_FLAG_Update);
}
