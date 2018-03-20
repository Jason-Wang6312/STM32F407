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
    float pitch,roll,yaw; 		//欧拉角
    short aacx,aacy,aacz;		//加速度传感器原始数据
    short gyrox,gyroy,gyroz;	//陀螺仪原始数据
//    short temp;                 //温度
     
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
 //       temp = MPU_Get_Temperature();	//得到温度值
        MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
        MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
//        mpu6050_send_data(aacx,aacy,aacz,gyrox,gyroy,gyroz);//用自定义帧发送加速度和陀螺仪原始数据
        usart1_report_imu((int)roll* 100,(int)pitch* 100,(int)yaw* 100);
        }
    }
}