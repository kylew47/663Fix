#include "Spi.h"

#define SPI_Simulation	   	0
#define SPI_ModeSet			SPI_Simulation		//SPI_ModeSet=SPI_SimulationΪʹ��ģ��SPI��ʽ��
	 					  						//SPI_ModeSet=1Ϊʹ���ڲ�Ӳ��SPI1��ʽ��
												//SPI_ModeSet=2Ϊʹ���ڲ�Ӳ��SPI2��ʽ��

/**
 *	@brief  SPIx_NCS�˿ڳ�ʼ��
 *  @param  SPIx : where x can be 1, 2 or 3 to select the SPI peripheral
 *  @return None 
 */
void SPIx_NCS_Init(SPI_TypeDef* SPIx)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	if(SPI1 == SPIx)
	{
		RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA, ENABLE );	//PORTAʱ��ʹ�� 
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;  				// PA4 ���� 
	 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  		//�������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//����GPIO���ٶ�
	 	GPIO_Init(GPIOA, &GPIO_InitStructure);

	 	GPIO_SetBits(GPIOA,GPIO_Pin_4);	   						//����SPI_NCS
	}
	else if(SPI2 == SPIx)
	{
		RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );	//PORTAʱ��ʹ�� 
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;  			// PB12 ���� 
	 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  		//�������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//����GPIO���ٶ�
	 	GPIO_Init(GPIOB, &GPIO_InitStructure);

	 	GPIO_SetBits(GPIOB,GPIO_Pin_12);		  				//����SPI_NCS		
	}
	else 
	{
		;
	}

}
/**
 *	@brief  SPIx��ʼ��
 *  @param  SPIx : where x can be 1, 2 or 3 to select the SPI peripheral
 *  @return None 
 */
SPI_InitTypeDef  SPI_InitStructure;
void SPIx_Init(void)
{

	GPIO_InitTypeDef GPIO_InitStructure;										    //����GPIO�ṹ��
  	if(SPI1 == SPI_ModeSet)
	{
		RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA|RCC_APB2Periph_SPI1, ENABLE );	//ʹ��GPIOA��SPI1ʱ��
	 												 
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;			//ʹ��SPI1_SCK��SPI1_MISO��SPI1_MOSI
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  							//�����������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;							//����GPIO���ٶ�
		GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	 	GPIO_SetBits(GPIOA,GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);	  					//����SPI1_SCK��SPI1_MISO��SPI1_MOSI�˿�
	
		SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  		//����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
		SPI_InitStructure.SPI_Mode = SPI_Mode_Master;								//����SPI����ģʽ:����Ϊ��SPI
		SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;							//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
		SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;									//ѡ���˴���ʱ�ӵ���̬:ʱ�����ո�
		SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;								//���ݲ����ڵڶ���ʱ����
		SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;									//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
		SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;		//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ256
		SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;							//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
		SPI_InitStructure.SPI_CRCPolynomial = 7;									//CRCֵ����Ķ���ʽ

		SPI_Init(SPI_ModeSet, &SPI_InitStructure);  	//����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
	 
		SPI_Cmd(SPI_ModeSet, ENABLE); 					//ʹ��SPI����
	
		SPIx_NCS_Init(SPI_ModeSet);					//ʹ��SPIx_NCS��
			
	//	SPIx_ReadWriteByte(SPIx,0xff);			//��������		
	 

	}
	else if(SPI2 == SPI_ModeSet)
	{
		RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );					//PORTBʱ��ʹ�� 
		RCC_APB1PeriphClockCmd(	RCC_APB1Periph_SPI2,  ENABLE );					//SPI2ʱ��ʹ�� 	
	 
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  						//PB13/14/15����������� 
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_InitStructure);									//��ʼ��GPIOB
	
	 	GPIO_SetBits(GPIOB,GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);  				//PB13/14/15����
	
		SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;  	//����SPI�������˫�������ģʽ:SPI����Ϊ˫��˫��ȫ˫��
		SPI_InitStructure.SPI_Mode = SPI_Mode_Master;							//����SPI����ģʽ:����Ϊ��SPI
		SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;						//����SPI�����ݴ�С:SPI���ͽ���8λ֡�ṹ
		SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;								//����ͬ��ʱ�ӵĿ���״̬Ϊ�ߵ�ƽ
		SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;							//����ͬ��ʱ�ӵĵڶ��������أ��������½������ݱ�����
		SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;								//NSS�ź���Ӳ����NSS�ܽţ����������ʹ��SSIλ������:�ڲ�NSS�ź���SSIλ����
		SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;	//���岨����Ԥ��Ƶ��ֵ:������Ԥ��ƵֵΪ256
		SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;						//ָ�����ݴ����MSBλ����LSBλ��ʼ:���ݴ����MSBλ��ʼ
		SPI_InitStructure.SPI_CRCPolynomial = 7;								//CRCֵ����Ķ���ʽ

		SPI_Init(SPI_ModeSet, &SPI_InitStructure);  	//����SPI_InitStruct��ָ���Ĳ�����ʼ������SPIx�Ĵ���
	 
		SPI_Cmd(SPI_ModeSet, ENABLE); 					//ʹ��SPI����
	
		SPIx_NCS_Init(SPI_ModeSet);					//ʹ��SPIx_NCS��
			
	//	SPIx_ReadWriteByte(SPIx,0xff);			//��������		
		 
 	
	}
	else if(SPI_Simulation==SPI_ModeSet)								//ģ��SPI�ڷ�ʽ
	{						    	
  		RCC_APB2PeriphClockCmd(SPI_GPIO_SCLK, ENABLE);					//ģ��SPI��ʱ��ʹ��
	
		GPIO_InitStructure.GPIO_Pin = SPI_NCS_GPIO_PIN;					// ����ģ��SPI��CS�˿�����
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 		//�������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 		//IO���ٶ�Ϊ50MHz
		GPIO_Init(SPI_NCS_GPIO, &GPIO_InitStructure);					//�����趨������ʼ��
		GPIO_SetBits(SPI_NCS_GPIO,SPI_NCS_GPIO_PIN);									//

		GPIO_InitStructure.GPIO_Pin = SPI_SCLK_GPIO_PIN;				// ����SPI��SCLK�˿�����
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 		//�������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 		//IO���ٶ�Ϊ50MHz
		GPIO_Init(SPI_SCLK_GPIO, &GPIO_InitStructure);					//�����趨������ʼ��
		GPIO_SetBits(SPI_SCLK_GPIO,SPI_SCLK_GPIO_PIN);


		GPIO_InitStructure.GPIO_Pin = SPI_MOSI_GPIO_PIN;				// ����SPI��MOSI�˿�����
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 		//�������
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 		//IO���ٶ�Ϊ50MHz
		GPIO_Init(SPI_MOSI_GPIO, &GPIO_InitStructure);					//�����趨������ʼ��.5
		GPIO_SetBits(SPI_MOSI_GPIO,SPI_MOSI_GPIO_PIN);

		GPIO_InitStructure.GPIO_Pin  = SPI_MISO_GPIO_PIN;				//����SPI��MISO�˿�
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 		//IO���ٶ�Ϊ50MHz
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 			//����PA6��Ϊ���븡��ģʽ
		GPIO_Init(SPI_MISO_GPIO, &GPIO_InitStructure);					//�����趨������ʼ��GPIOA
		GPIO_ResetBits(SPI_MISO_GPIO,SPI_MISO_GPIO_PIN);
	}
}   

/**
 *	@brief  SPI�����ٶȷ�Ƶ����
 *  @param  SPIx : where x can be 1, 2 or 3 to select the SPI peripheral
 *  @param  data : SpeedSet=>	SPI_BaudRatePrescaler_2   2��Ƶ   (SPI 36M@sys 72M)
 *								SPI_BaudRatePrescaler_8   8��Ƶ   (SPI 9M@sys 72M)
 *								SPI_BaudRatePrescaler_16  16��Ƶ  (SPI 4.5M@sys 72M)
 *								SPI_BaudRatePrescaler_64  64��Ƶ      
 *								SPI_BaudRatePrescaler_128 128��Ƶ      
 *								SPI_BaudRatePrescaler_256 256��Ƶ (SPI 281.25K@sys 72M)
 *  @return None 
 */  
void SPIx_SetSpeed(SPI_TypeDef* SPIx,u8 SpeedSet)
{
	SPI_InitTypeDef  SPI_InitStructure;

	SPI_InitStructure.SPI_BaudRatePrescaler = SpeedSet ;
  	SPI_Init(SPIx, &SPI_InitStructure);
	SPI_Cmd(SPIx,ENABLE);
} 

/**
 *	@brief  Sends one byte over SPI.//����һ���ֽ�
 *  @param  SPIx : where x can be 1, 2 or 3 to select the SPI peripheral
 *  @param  data : data to send	(8 bit)
 *  @return None 
 */
void SPI_SendByte(SPI_TypeDef* SPIx, uint8_t data) 
{	
	/* Wait for SPIx Tx buffer empty */
	while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET);

	/* Send byte through the SPIx peripheral */
	SPI_I2S_SendData(SPIx, data);
}

/**  
 *	@brief  Sends one byte over SPI and recovers a response.//����һ���ֽں����һ���ֽ�
 *  @param  SPIx : where x can be 1, 2 or 3 to select the SPI peripheral
 *  @param  data : data to send
 *  @return data response from SPIx 
 */
uint8_t SPI_SendReceiveByte(SPI_TypeDef* SPIx, uint8_t data) 
{	
	/* Wait for SPI1 Tx buffer empty */
	while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_TXE) == RESET);

	/* Send byte through the SPI1 peripheral */
	SPI_I2S_SendData(SPIx, data);	

	/* Wait for SPI1 data reception	*/
	while(SPI_I2S_GetFlagStatus(SPIx, SPI_I2S_FLAG_RXNE) == RESET);

	/* Read & return SPI1 received data	*/
	return SPI_I2S_ReceiveData(SPIx);
}

/**
 *	@brief  Send a byte array over SPI.//����һ�����ݺ����һ������
 *  @param  SPIx	 	: where x can be 1, 2 or 3 to select the SPI peripheral
 *  @param  pCommand  	: pointer on the buffer to send
 *  @param  length	 	: length of the buffer to send
 *  @param  pResponse 	: pointer on the buffer response
 *  @return None 
 */
void SPI_SendReceiveBuffer(SPI_TypeDef* SPIx, uc8 *pCommand, uint16_t length, uint8_t *pResponse) 
{
	uint16_t i;

	for(i=0; i<length; i++)
	{
		pResponse[i] = SPI_SendReceiveByte(SPIx, pCommand[i]);
	}

}

//ʹ��ģ��SPI��ʽ����//
/*********************************************************/
//���ͣ� ����spi���ߵĶ�дʱ�����еļĴ����������ڴ�ʱ�򣬷ǳ���Ҫ
//		 ����żУ��
//���룺Ҫд���16���Ʋ���
//
//������ڲ����ص�16���Ʋ���
//
/********************************************************/
uint8_t SPI_Send(uint8_t data)
{
	uint8_t i=0,temp=0;
	uint8_t MISO=0;
	for(i=0;i<8;i++)
	{
		SPI_SCLK_0;			//ʱ������
		if(data&0x80)
		{
			SPI_MOSI_1;		//MOSI����
		}	
		else
		{
			SPI_MOSI_0;		//MOSI����
		}	
		data<<=1;			//��������
//		delay_us(1);
		SPI_SCLK_1;			//ʱ���������һλ���ݴ���
		temp<<=1;			//
		MISO=Read_MISO();  	//��ȡMISO�ڵ�ƽ
		if(MISO)
		{	
			temp|=0x01;
//			delay_us(1);
		}
	}
	SPI_SCLK_0;			//
	SPI_MOSI_0;			//
	return  temp;
}

//SPI����,������У��
uint8_t SPI_ParitySend(uint8_t data)
{
	uint8_t i=0,temp=0;
	uint8_t odd=0;		//����
	uint8_t even=0;		//ż��
	for(i=0;i<8;i++)
	{
		SPI_SCLK_0;			//ʱ������
		if(data&0x80)
		{
			SPI_MOSI_1;		//MOSI����
			even=~even;
		}	
		else
		{
			SPI_MOSI_0;		//MOSI����
			odd=~odd;
		}	
		data<<=1;			//��������
		delay_us(10);
		SPI_SCLK_1;			//ʱ���������һλ���ݴ���

	}
	if(odd==0)
	{	
		SPI_MOSI_1;		//MOSI����
	}	
	else
	{
		SPI_MOSI_0;		//MOSI����
	}
	delay_us(10);
	SPI_MOSI_1;		//MOSI����
	delay_us(10);
	SPI_SCLK_0;			//
	SPI_MOSI_0;			//
	return  temp;	
}
//SPI��ȡ
uint8_t SPI_Receive(void)
{
	uint8_t i=0,temp=0,MISO=0;
	for(i=0;i<8;i++)
	{
		SPI_SCLK_0;			//ʱ������
/*		if(data&0x80)
		{
			SPI_MOSI_1;		//MOSI����
		}	
		else
		{
			SPI_MOSI_0;		//MOSI����
		}	
		data<<=1;			//��������
		*/
//		delay_us(1);
		SPI_SCLK_1;			//ʱ���������һλ���ݴ���
		temp<<=1;
		MISO=Read_MISO();  //��ȡMISO�ڵ�ƽ
		if(MISO)
		{	
			temp|=0x01;
//			delay_us(1);
		} 
	}
	SPI_SCLK_0;			//
	SPI_MOSI_0;			//
	return  temp;	
}
/*********************************************************/
//���ͣ�д�Ĵ�������  ������żУ��
//
//���룺�Ĵ�����ַ �Լ�Ҫд��Ĳ���
//
//�����
//
/********************************************************/
void resig_write(uint8_t cmd,uint8_t data)
{
	SPI_SCLK_0;		//ʱ������
	SPI_NCS_0;		//����ѡͨSPI��
	cmd<<=1;		//FM1702ͨ��SPI�ӿ�д����Э�飺��λΪ0
	cmd=cmd&0x7e;	//��λΪ0
//	spi_send(cmd);		//����cmd��ַ
//	spi_send(data);		//����data����
	SPI_Send(cmd);
	SPI_Send(data);
	SPI_NCS_1;		//���߽�ֹSPI��
}


//����д֮ǰ������żУ��
void resig_ParityCheck_write(uint8_t cmd,uint8_t data)
{
	SPI_SCLK_0;		//ʱ������
	SPI_NCS_0;		//����ѡͨSPI��
	cmd<<=1;		//FM1702ͨ��SPI�ӿ�д����Э�飺��λΪ0
	cmd=cmd&0x7e;	//��λΪ0
//	spi_send(cmd);		//����cmd��ַ
//	spi_send(data);		//����data����
	SPI_ParitySend(cmd);
	SPI_ParitySend(data);
	SPI_NCS_1;		//���߽�ֹSPI��
}
/*********************************************************/
//���ͣ����Ĵ�������
//
//���룺�Ĵ�����ַ 
//
//������üĴ���Ŀǰ��ֵ
//
/********************************************************/
uint8_t resig_read(uint8_t reg)
{
	uint8_t temp;
	SPI_SCLK_0;		//SPI��ʱ������
//	delay_us(2);
	SPI_NCS_0;		//ѡͨSPIģʽ
	reg<<=1;		//FM1702SPI�Ľӿ�Э�飺��λΪ0
	reg|=0x80;		//��λΪ1
//	spi_send(reg);		//SPI�ڽ��з���reg����
//	temp=spi_receive();	// ��ȡ����ֵ
	SPI_Send(reg);
	temp=SPI_Send(0x00);
	SPI_NCS_1;		//SPI��ѡͨ��ֹ
	return temp; 
	
}


































