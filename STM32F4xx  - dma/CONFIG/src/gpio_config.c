#include "gpio_config.h"

/*GPIO ��ʼ������*/
void gpio_config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);                       //ʱ��ʹ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;                      //ѡ������
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;                               //ѡ��ģʽ
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;                          //ѡ������
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                              //ѡ��˿�ģʽPP����OD��©
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;                                //ѡ������UP����down����NOPULL����
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_WriteBit(GPIOA,GPIO_Pin_6 | GPIO_Pin_7,Bit_SET);                       //��ʼ��Ϊ�ߵ�ƽ
}