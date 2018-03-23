#include "gpio_config.h"

/*GPIO 初始化函数*/
void gpio_config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);                       //时钟使能
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;                      //选择引脚
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;                               //选择模式
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;                          //选择速率
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;                              //选择端口模式PP推挽OD开漏
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;                                //选择上拉UP上拉down下拉NOPULL不拉
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    GPIO_WriteBit(GPIOA,GPIO_Pin_6 | GPIO_Pin_7,Bit_SET);                       //初始化为高电平
}