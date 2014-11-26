#ifndef __SPI_H
#define __SPI_H

#include "stm32f10x_spi.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "Delay/Delay.h"


#define SPI_GPIO_SCLK	RCC_APB2Periph_GPIOA//|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOA		  //SPI�˿�ʱ�Ӷ���

#define SPI_MOSI_GPIO		GPIOA//GPIOB					 //MOSI�˿�
#define SPI_MOSI_GPIO_PIN	GPIO_Pin_7//GPIO_Pin_0

#define SPI_NCS_GPIO		GPIOA//GPIOB					 //NCS�˿�
#define SPI_NCS_GPIO_PIN	GPIO_Pin_4//GPIO_Pin_1

#define SPI_SCLK_GPIO		GPIOA//GPIOB					 //SCLK�˿�
#define SPI_SCLK_GPIO_PIN	GPIO_Pin_5//GPIO_Pin_13

#define SPI_MISO_GPIO		GPIOA//GPIOC					 //MISO�˿�
#define SPI_MISO_GPIO_PIN	GPIO_Pin_6//GPIO_Pin_5

//*******************SPI�˿�����**************************************//
#define SPI_SELECT() 	GPIO_ResetBits(SPI_NCS_GPIO , SPI_NCS_GPIO_PIN )  	   		//SPI��ѡ��
#define SPI_DESELECT() 	GPIO_SetBits  (SPI_NCS_GPIO, SPI_NCS_GPIO_PIN)	
 
#define SPI_NCS_1  		{GPIO_SetBits(SPI_NCS_GPIO,SPI_NCS_GPIO_PIN);}		        //SPI_CS����
#define SPI_NCS_0  		{GPIO_ResetBits(SPI_NCS_GPIO,SPI_NCS_GPIO_PIN);}			//SPI_CS����

#define SPI_SCLK_1  	{GPIO_SetBits(SPI_SCLK_GPIO,SPI_SCLK_GPIO_PIN);}			//SPI_SCLK����
#define SPI_SCLK_0  	{GPIO_ResetBits(SPI_SCLK_GPIO,SPI_SCLK_GPIO_PIN);}			//SPI_SCLK����

#define Read_MISO()  	GPIO_ReadInputDataBit(SPI_MISO_GPIO,SPI_MISO_GPIO_PIN);		//��MISO��ƽ

#define SPI_MOSI_1  	{GPIO_SetBits(SPI_MOSI_GPIO,SPI_MOSI_GPIO_PIN);}			//SPI_MOSI����
#define SPI_MOSI_0  	{GPIO_ResetBits(SPI_MOSI_GPIO,SPI_MOSI_GPIO_PIN);}			//SPI_MOSI����


//*********************�ڲ�Ӳ��SPI��������*******************************//
void SPIx_NCS_Init(SPI_TypeDef* SPIx); 				  	    													  
void SPIx_Init(void);			 //��ʼ��SPI��
void SPIx_SetSpeed(SPI_TypeDef* SPIx,u8 SpeedSet); //����SPI�ٶ�   

void SPI_SendByte(SPI_TypeDef* SPIx, uint8_t data) ;
void SPI_SendReceiveBuffer(SPI_TypeDef* SPIx, uc8 *pCommand, uint16_t length, uint8_t *pResponse);
uint8_t SPI_SendReceiveByte(SPI_TypeDef* SPIx, uint8_t data);


//***************ģ��SPI��������***************************************//
uint8_t SPI_Send(uint8_t data);
uint8_t SPI_ParitySend(uint8_t data);
uint8_t SPI_Receive(void);

void resig_write(uint8_t reg,uint8_t da);
uint8_t resig_read(uint8_t reg);
void resig_ParityCheck_write(uint8_t cmd,uint8_t data);
		 
#endif

