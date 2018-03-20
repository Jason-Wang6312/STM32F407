#include "tim_config.h"

void tim1_config(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    
    tim1_nvci_config();
        
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);                         //����TIM1��ʱ��

    /*
    �����ⶨʱ�����֣�����������ߣ� APB1/APB2 ���ķ�Ƶϵ��Ϊ 1����ô�Ͳ���Ƶ��
    �����Ϊ 1������ 2/4/8/16 2/4/8/16 2/4/8/16 ���� ��ô�ͻ� 2��Ƶ�� Fabpx*2 ������Ϊ��ʱ��������
    */
    //ʱ����Ԫ�ĳ�ʼ�� 168M
    TIM_TimeBaseInitStructure.TIM_Prescaler = 16800-1;                          //ʱ��Ԥ��Ƶ��
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;             //���ϼ���ģʽ
    TIM_TimeBaseInitStructure.TIM_Period = 10000-1;                              //�Զ���װ�ؼĴ�����ֵ
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;                 //������Ƶ
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0x00;
    TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStructure);
    
    TIM_ClearFlag(TIM1,TIM_FLAG_Update);   //�������������ʱ������ĸ��±�־
    TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);   //ʹ���жϣ��ж��¼�Ϊ��ʱ����н�¼�
    TIM_Cmd(TIM1,ENABLE);    //ʹ�ܶ�ʱ��
}