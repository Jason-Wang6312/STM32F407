#include "usart_config.h"

void usatr1_config(u32 bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    usart1_nvic_config();
    
    USART_InitTypeDef USART_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);                       //ʱ��usartʹ��
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);                       //ʱ��gpioʹ��
    
    /*������������*/
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_USART1);                     
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_USART1);
    
    /*����TX,RXΪ����*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;                     //ѡ������
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;                                //ѡ��ģʽ
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;                          //ѡ������
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                              //ѡ��˿�ģʽPP����OD��©
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;                                //ѡ������UP����down����NOPULL����
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /*����usart1
    **������  ����λ  ֹͣλ  У��λ
      115200   8       1      NO
    */
    USART_InitStructure.USART_BaudRate = bound;                                //������
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;                 //�ֳ�8λ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;                      //1ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;                         //��У��
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;             //ʹ�ܽ��ܷ���
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  //������
    USART_Init(USART1,&USART_InitStructure);
    USART_Cmd(USART1,ENABLE);
    
    //���ж�
    USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
    
}


//�ض���printf
int fputc(int ch, FILE *f)
{
    while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET)
    {
    }
    USART_SendData(USART1,(uint8_t) ch);
    return ch;
}

