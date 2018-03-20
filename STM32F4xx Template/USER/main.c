#include "sysclock_config.h"
#include "gpio_config.h"
#include "usart_config.h"
#include "tim_config.h"
#include "IRQHandler_config.h"

#include "delay.h"

int main()
{
    Clock_Config();
    gpio_config();
    usatr1_config();
    tim1_config();
    GPIO_WriteBit(GPIOA,GPIO_Pin_6 | GPIO_Pin_7,Bit_RESET);
    while(1)
    {
    
//    printf("ok \n");
//    Delay_s(1);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_6 | GPIO_Pin_7,Bit_SET);
//    USART_SendData(USART1,0xff);
//    Delay_s(1);
    }
}