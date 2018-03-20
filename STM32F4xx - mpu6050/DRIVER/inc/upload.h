#ifndef __upload_H
#define __upload_H

#include "usart_config.h"

void usart1_niming_report(u8 fun,u8*data,u8 len);
void mpu6050_send_data(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz);
void usart1_report_imu(int roll,int pitch,int yaw);

#endif