#ifndef __MOTOR_H_
#define __MOTOR_H_

#include "stm32f10x.h"

//void MotorGPIO_Configuration(void);
//void run(void);

void TIM4_PWM_Init(unsigned short arr,unsigned short psc);
void SetMotorSpeed(unsigned char ucChannel,signed char cSpeed);

void ZYSTM32_run(signed char speed,int time);       //ǰ������
void ZYSTM32_brake(int time);               //ɲ������
void ZYSTM32_Left(signed char speed,int time);      //��ת����
void ZYSTM32_Spin_Left(signed char speed,int time); //����ת����
void ZYSTM32_Right(signed char speed,int time);     //��ת����
void ZYSTM32_Spin_Right(signed char speed,int time);//����ת����
void ZYSTM32_back(signed char speed,int time);      //���˺���

// 新增差速巡线接口
void ZYSTM32_SetSpeed(signed char leftSpeed, signed char rightSpeed);
void ZYSTM32_KeepForward(signed char speed);
void ZYSTM32_SoftLeft(signed char baseSpeed, signed char diff);
void ZYSTM32_SoftRight(signed char baseSpeed, signed char diff);
void ZYSTM32_HardLeft(signed char speed);
void ZYSTM32_HardRight(signed char speed);

//�������IO���� 
/* 
LEFT_MOTOR_GO	  PB8	�����������
LEFT_MOTOR_PWM	PB9	����PWM

RIGHT_MOTOR_GO	PA6     �ҵ���������
RIGHT_MOTOR_PWM	PB10	  �ҵ�����PWM
 */
 
#define LEFT_MOTOR_GO             GPIO_Pin_7
#define LEFT_MOTOR_GO_GPIO        GPIOB
#define LEFT_MOTOR_GO_SET         GPIO_SetBits(LEFT_MOTOR_GO_GPIO,LEFT_MOTOR_GO)
#define LEFT_MOTOR_GO_RESET       GPIO_ResetBits(LEFT_MOTOR_GO_GPIO,LEFT_MOTOR_GO)

#define LEFT_MOTOR_PWM            GPIO_Pin_8
#define LEFT_MOTOR_PWM_GPIO       GPIOB
#define LEFT_MOTOR_PWM_SET        GPIO_SetBits(LEFT_MOTOR_PWM_GPIO,LEFT_MOTOR_PWM)
#define LEFT_MOTOR_PWM_RESET      GPIO_ResetBits(LEFT_MOTOR_PWM_GPIO,LEFT_MOTOR_PWM)

#define RIGHT_MOTOR_GO             GPIO_Pin_4
#define RIGHT_MOTOR_GPIO           GPIOA
#define RIGHT_MOTOR_GO_SET         GPIO_SetBits(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_GO)
#define RIGHT_MOTOR_GO_RESET       GPIO_ResetBits(RIGHT_MOTOR_GPIO,RIGHT_MOTOR_GO)

#define RIGHT_MOTOR_PWM            GPIO_Pin_9
#define RIGHT_MOTOR_PWM_GPIO       GPIOB
#define RIGHT_MOTOR_PWM_SET        GPIO_SetBits(RIGHT_MOTOR_PWM_GPIO,RIGHT_MOTOR_PWM)
#define RIGHT_MOTOR_PWM_RESET      GPIO_ResetBits(RIGHT_MOTOR_PWM_GPIO,RIGHT_MOTOR_PWM)

#endif
