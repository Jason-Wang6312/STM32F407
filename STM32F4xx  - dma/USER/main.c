#include "sysclock_config.h"
#include "gpio_config.h"
#include "usart_config.h"
#include "tim_config.h"
#include "IRQHandler_config.h"
#include "mpu6050.h"
#include "delay.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include "upload.h"

int main()
{
    float pitch,roll,yaw; 		//ŷ����
    short aacx,aacy,aacz;		//���ٶȴ�����ԭʼ����
    short gyrox,gyroy,gyroz;	//������ԭʼ����
//    short temp;                 //�¶�
     
    Clock_Config();
    gpio_config();
    usatr1_config();
    tim1_config();
    IIC_Init();
    GPIO_WriteBit(GPIOA,GPIO_Pin_6 | GPIO_Pin_7,Bit_RESET);
    
    do{
    printf("mpu6050_dmp_init\n");    
    }while(mpu_dmp_init());
    
    while(1)
    {
    if(mpu_dmp_get_data(&pitch,&roll,&yaw) == 0)
        {
 //       temp = MPU_Get_Temperature();	//�õ��¶�ֵ
        MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
        MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
//        mpu6050_send_data(aacx,aacy,aacz,gyrox,gyroy,gyroz);//���Զ���֡���ͼ��ٶȺ�������ԭʼ����
        usart1_report_imu((int)roll* 100,(int)pitch* 100,(int)yaw* 100);
        }
    }
}