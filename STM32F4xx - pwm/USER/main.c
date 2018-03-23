#include "sysclock_config.h"
#include "gpio_config.h"
#include "usart_config.h"
#include "tim_config.h"
#include "delay.h"
#include "pwm.h"

u16 pwm1val = 500;

int main()
{   
    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//���ȼ�����
    
    Clock_Config();
    gpio_config();
    usatr1_config(115200);
    tim1_config(16800-1,10000-1);
    TIM4_PWM_Init(336-1,5000-1);	//APB1 42M*2=84M,Ԥ��Ƶ84M/336=250k���Զ���װ��5000��pwmƵ��=250k/5000=50
    
      TIM_SetCompare1(TIM4,pwm1val);
      TIM_SetCompare2(TIM4,pwm1val);
      TIM_SetCompare3(TIM4,pwm1val);
      TIM_SetCompare4(TIM4,pwm1val);
      Delay_s(5);
      pwm1val = 250;
      TIM_SetCompare1(TIM4,pwm1val);
      TIM_SetCompare2(TIM4,pwm1val);
      TIM_SetCompare3(TIM4,pwm1val);
      TIM_SetCompare4(TIM4,pwm1val);
    
    while(1)
    {
      TIM_SetCompare1(TIM4,pwm1val);
      TIM_SetCompare2(TIM4,pwm1val);
      TIM_SetCompare3(TIM4,pwm1val);
      TIM_SetCompare4(TIM4,pwm1val);
      
    }
}

