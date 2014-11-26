#include "Exti.h"

//��ʼ���ж���������.
//��ʼ��As3911���ж�����

void EXTIx_Init(void)
{
  	GPIO_InitTypeDef GPIO_InitStructure;
 	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;


  	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);	//�ر�jtag

  	RCC_APB2PeriphClockCmd(AS3911_EXIT_CLK|RCC_APB2Periph_AFIO,ENABLE);

 // ��ʼ�� AS3911_PORT_INTR-->GPIOn	  ��������
  	GPIO_InitStructure.GPIO_Pin  = AS3911_EXIT_PIN;
  	GPIO_InitStructure.GPIO_Mode = AS3911_EXIT_GPIO_MODE; 
  	GPIO_Init(AS3911_EXIT_GPIO, &GPIO_InitStructure);

  
 	GPIO_EXTILineConfig(AS3911_EXIT_GPIO_SOURCE,AS3911_EXIT_PIN_SOURCE);		//GPIOn	  �ж����Լ��жϳ�ʼ������

 	EXTI_InitStructure.EXTI_Line=AS3911_EXIT_LINE;				  //ѡ���ж���
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

 
  	NVIC_InitStructure.NVIC_IRQChannel = AS3911_EXIT_IRQ;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//�����ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
    
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�

}

//*****�ر��ж�*********************//
void EXITx_OFF(void)
{ 
	
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	EXTI_InitStructure.EXTI_Line=AS3911_EXIT_LINE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
  	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = AS3911_EXIT_IRQ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;
	NVIC_Init(&NVIC_InitStructure);
}

