#include "sysclock_config.h"
#include "gpio_config.h"
#include "usart_config.h"
#include "tim_config.h"
#include "IRQHandler_config.h"
#include "24l01.h"
#include "delay.h"

int main()
{
//  u8 tmp_buf[32]; 
    //优先级分组
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
    Clock_Config();
    gpio_config();
    usatr1_config(115200);
    tim1_config();
    NRF24L01_Init();
    NRF24L01_TX_Mode();
    while(1)
    {
    
//    printf("ok \n");
//    Delay_s(1);
//    GPIO_WriteBit(GPIOA,GPIO_Pin_6 | GPIO_Pin_7,Bit_SET);
//    USART_SendData(USART1,0xff);
//    Delay_s(1);
    
    NRF24L01_TxPacket("hello\n");
      
    }
}

