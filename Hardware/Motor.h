#ifndef __MOTOR_H
#define __MOTOR_H
void Motor1_Init(void);
void Motor1_SetSpeed(int8_t Speed);
void Motor2_Init(void);
void Motor2_SetSpeed(int8_t Speed);
void Motor_Forward(uint8_t Speed);
void Motor_Backward(uint8_t Speed);
void Motor_TurnLeft(uint8_t Speed,float Angle);
void Motor_TurnRight(uint8_t Speed,float Angle);
void Motor_Stop(void);
#endif
