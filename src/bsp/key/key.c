#include "key.h"
#include "bsp\delay\delay.h"
#include "stm32f4xx.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);//ʹ��GPIOA,GPIOEʱ��
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; //KEY0 KEY1 KEY2��Ӧ����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//50M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOE2,3,4
}

uint8 KEY_Scan(void)
{
	if(KEY == 0)
	{
		Delay_Ms(10);//eliminate jitter 	
		if(KEY == 0)	return 1;//button event happened
	}  
	
	return 0;//button event did not happen

}

