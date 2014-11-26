/*==============================================================================================
 *         Copyright (c), NXP Semiconductors
 *
 *       All rights are reserved. Reproduction in whole or in part is
 *      prohibited without the written consent of the copyright owner.
 *  NXP reserves the right to make changes without notice at any time.
 * NXP makes no warranty, expressed, implied or statutory, including but
 * not limited to any implied warranty of merchantability or fitness for any
 *particular purpose, or that the use will not infringe any third party patent,
 * copyright or trademark. NXP must not be liable for any loss or damage
 *                          arising from its use.
 */

/*==============================================================================================
 *
 *   File name:  hw_config.c
 *
 *  Created on:
 *      Author:
 *
 *     Hystory:
 */

/*----------------------------------------------------------------------------------------------
 * Includes
 ---------------------------------------------------------------------------------------------*/
//#include <LPC17xx.h>
#include <ph_TypeDefs.h>
#include <ph_Status.h>
#include <phhalHw.h>
#include <phbalReg.h>
#include <phbalReg_Stub.h>
#include <ph_NxpBuild.h>
#include <ph_Status.h>
#include <phOsal.h>

//#include <lpc17xx_ssp.h>
//#include <lpc17xx_i2c.h>
//#include <lpc17xx_libcfg.h>
//#include <lpc17xx_pinsel.h>
//#include <lpc17xx_gpio.h>
#include "Led/Led.h"

#include "phhwConfig.h"


/*----------------------------------------------------------------------------------------------
 * Local macros and definitions
 ---------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------
 * Global variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Local variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Local function declaration
 ---------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Global function prototypes
 ---------------------------------------------------------------------------------------------*/


/* **************************************
 * Initialize interface link            *
 * **************************************/

/* =============================================================================================
 * Function:	Set_Interface_Link
 *
 * brief:
 *   Initialize interface link
 *   GPIOSetDir sets the direction in GPIO port.
 *   1 out, 0 input
 *
 *   GPIOSetValue sets/clears a bitvalue in a specific bit position
 *   in GPIO portX(X is the port number.)
 *   Our RC523 will act in slave mode. START and STOP conditions are
 *   generated by the master.
 *
 * -------------------------------------------------------------------------------------------*/
static void RC663_GPIO_Init(void)
{
//	GPIO_InitTypeDef GPIO_InitStructure;

//	RCC_APB2PeriphClockCmd(RC663_SPI_IFSEL0_GPIO_CLK, ENABLE);
//	RCC_APB2PeriphClockCmd(RC663_SPI_IFSEL1_GPIO_CLK, ENABLE);

//	GPIO_InitStructure.GPIO_Pin = RC663_SPI_IFSEL0_GPIO_PIN;
//	GPIO_InitStructure.GPIO_Mode = RC663_SPI_IFSEL0_GPIO_MODE;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
//	GPIO_Init(RC663_SPI_IFSEL0_GPIO, &GPIO_InitStructure);
//
//	GPIO_InitStructure.GPIO_Pin = RC663_SPI_IFSEL1_GPIO_PIN;
//	GPIO_InitStructure.GPIO_Mode = RC663_SPI_IFSEL1_GPIO_MODE;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
//	GPIO_Init(RC663_SPI_IFSEL1_GPIO, &GPIO_InitStructure);
	
//	RC663_SPI_IFSEL0_GPIO_L();
//	RC663_SPI_IFSEL1_GPIO_H();


}
void Set_Interface_Link(void)
{

//#if defined NXPBUILD__PHHAL_HW_RC523
//#ifdef SPI_USED
//    /* not any pinout setting from reason the PNEV512B has interface setting realized
//     * by soldere resistors on the PCB
//     */
//#endif /* SPI_USED */
//#ifdef I2C_USED
//
//    	/* Set direction of pins as output to set for I2C address of attached reader */
//        GPIO_SetDir(PORT0, PIN_AD0, SET_OUT);
//        GPIO_SetDir(PORT0, PIN_AD1, SET_OUT);
//        GPIO_SetDir(PORT0, PIN_AD2, SET_OUT);
//
//        /* Set PN512 I2C address to 0x50 */
//        GPIO_ClearValue(PORT0, PIN_AD0);
//        GPIO_ClearValue(PORT0, PIN_AD1);
//        GPIO_ClearValue(PORT1, PIN_AD2);
//#endif /* I2C_USED */
//#endif /* NXPBUILD__PHHAL_HW_RC523 */

#if defined NXPBUILD__PHHAL_HW_RC663
#ifdef SPI_USED
 
      RC663_GPIO_Init();
//    /* Set port pin P2.4 - IFSEL0 to output */
//    GPIO_SetDir(PORT2, PIN_IFSEL0, SET_OUT);
//
//    /* Set port pin P2.5 - IFSEL1 to output */
//    GPIO_SetDir(PORT2, PIN_IFSEL1, SET_OUT);
//
//    /* Select SPI link -> IFSEL0 = 0 & IFSEL1 = 1 */
//    /* IFSEL0 = 0 */
//    GPIO_ClearValue(PORT2, PIN_IFSEL0);
//
//    /* IFSEL1 = 1 */
//    GPIO_SetValue(PORT2, PIN_IFSEL1);
#endif /* SPI_USED */
//#ifdef I2C_USED
//
//    /* Set port pin P2.4 - IFSEL0 to output */
//    GPIO_SetDir(PORT2, PIN_IFSEL0, SET_OUT);
//
//    /* Set port pin P2.5 - IFSEL1 to output */
//    GPIO_SetDir(PORT2, PIN_IFSEL1, SET_OUT);
//
//    /* Select I2C link -> IFSEL0 = 1 & IFSEL1 = 0 */
//    /* IFSEL0 = 1 */
//    GPIO_SetValue(PORT2, PIN_IFSEL0);
//
//    /* IFSEL1 = 0 */
//    GPIO_ClearValue(PORT2, PIN_IFSEL1);
//
//    /* Set port pin P0.17 - I2C address bit AD0 to output */
//    GPIO_SetDir(PORT0, PIN_AD0, SET_OUT);
//
//    /* Set port pin P0.15 - I2C address bit AD1 to output */
//    GPIO_SetDir(PORT0, PIN_AD1, SET_OUT);
//
//    /* Select I2C adresss -> AD0 = AD1 = 0 */
//    /* AD0 = 0 */
//    GPIO_ClearValue(PORT0, PIN_AD0);
//
//    /* AD1 = 0 */
//    GPIO_ClearValue(PORT0, PIN_AD1);
//#endif /* I2C_USED */
#endif /* NXPBUILD__PHHAL_HW_RC663 */
}
/*==============================================================================================
 * Function:	Reset_reader_device
 *
 * brief:	This function resets an attached reader IC. In PIN_RESET macro is a correct pin .
 *
 * -------------------------------------------------------------------------------------------*/
void Reset_reader_device(void)
{
uint32_t volatile i;

//#if defined NXPBUILD__PHHAL_HW_RC523
//	/* Reset for PN512 is 1-0-1 */
//	/* NRST_512 = P0.27 */
//	/* Set port pin to output */
//	GPIO_SetDir(PINSEL_PORT_0, PIN_RESET, SET_OUT);
//
//	/* RSET signal high */
//	GPIO_SetValue(PINSEL_PORT_0, PIN_RESET);
//
//	/* delay of 1 ms */
//	for (i = 0x2800; i > 0; i --);
//
//	/* RSET signal low to Reset PN512 */
//	GPIO_ClearValue(PINSEL_PORT_0, PIN_RESET);
//
//	/* delay of 1 ms */
//	for (i = 0x2800; i > 0; i --);
//
//	/* RSET signal high */
//	GPIO_SetValue(PINSEL_PORT_0, PIN_RESET);
//
//	/* delay of 1 ms */
//	for (i = 0x2800; i > 0; i --);
//#endif
#if defined NXPBUILD__PHHAL_HW_RC663
	/* Set port pin - PDOWN to output */
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RC663_PDOWN_GPIO_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = RC663_PDOWN_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = RC663_PDOWN_GPIO_MODE;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
	GPIO_Init(RC663_PDOWN_GPIO, &GPIO_InitStructure);

	/* send the reset pulse 0-1-0 to reset device */
	/* RSET signal low - PDOWN to '0' */
	RC663_PDOWN_GPIO_L();

	/* delay of ~1,2 ms */
	for (i = 0x2800; i > 0; i --);

	/* RSET signal high to reset the RC663 IC - PDOWN to '1' */
	RC663_PDOWN_GPIO_H();

	/* delay of ~1,2 ms */
	for (i = 0x2800; i > 0; i --);

	/* RSET signal low - PDOWN to '0' */
	RC663_PDOWN_GPIO_L();

	/* delay of ~1,2 ms */
	for (i = 0x2800; i > 0; i --);
#endif

}
/* **************************************
 * handle GPIO                          *
 * **************************************/

/*==============================================================================================
 * Function:	GPIO_Init
 *
 * brief:
 *
 * -------------------------------------------------------------------------------------------*/
//void GPIO_Init(void)
//    {
//    /* there is a different name for the GPIO driver module for each LPC processor which comes
//     * from drivers.
//     * GPIO interface is consolidated via this function calling.
//     */
//
//    // this is empty function for LPC1769
//    //GPIOInit();
//    }

/*==============================================================================================
 * Function:	Set_Port
 *
 * brief:
 *
 * -------------------------------------------------------------------------------------------*/
void Set_Port(void)
    {
#ifndef TUSA
    /* Set LED port pin to output */
	LEDInit();
#endif
    }

/*==============================================================================================
 * Function:	LedOn
 *
 * brief:	switch the LED on
 *
 * -------------------------------------------------------------------------------------------*/
void LedOn(void)
    {
      LED_ON;
    }

/*==============================================================================================
 * Function:	LedOff
 *
 * brief:	switch the LED off
 *
 * -------------------------------------------------------------------------------------------*/
void LedOff(void)
    {
      LED_OFF;
    }

#ifdef NXPBUILD__PHHAL_HW_RC523
/*==============================================================================================
 * Data structure dedicated to keep important data from application.
 *
 * params:		pHal	[in]	Pointer to RdLib HAL data parameter component. Its used to handle
 * 								registers of reader IC when configured the interrupts by the Set_Interrupt()
 * 								function.
 * 				pOsal	[in]	Pointer to OSAL parameter component. Necessary to call a correct
 * 								application callback from within timer interrupt handler.
 * 				pData	[in]	Pointer to data from the application. The data are expected to be
 * 								handled within IRQ handlers of this project.
 * -------------------------------------------------------------------------------------------*/
static struct{
	void			*pHal;
	void			*pOsal;
	volatile void	*pData_ready;
}appData;
/*==============================================================================================
 * Function:	appDataInit
 *
 * brief:		This function configures pin IRQ on MCU side and IRQ generation on reader IC.
 * 				In result dedicated interrupt requests from reader IC are escalated to the host MCU.
 *				The function is used by NFC Target.
 *
 * params:		pHal	[in]	Pointer to RdLib HAL data parameter component. Its used to handle
 * 								registers of reader IC when configured the interrupts by the Set_Interrupt()
 * 								function.
 * 				pOsal	[in]	Pointer to OSAL parameter component. Necessary to call a correct
 * 								application callback from within timer interrupt handler.
 * 				pData	[in]	Pointer to data from the application. The data are expected to be
 * 								handled within IRQ handlers of this project. *
 * -------------------------------------------------------------------------------------------*/
void appDataInit( void	*pHal,
				  void	*pOsal,
				  void	*pData)
{
	appData.pHal 			  = pHal;
	appData.pOsal 			  = pOsal;
	appData.pData_ready 	  = pData;

	return;
}
/*==============================================================================================
 * Function:	Set_Interrupt
 *
 * brief:		This function is called when interrupt from attached PN512 IC occurs.
 * 				It resets MCU and reader IC to state to be able to detect another IRQ.
 *
 * -------------------------------------------------------------------------------------------*/
void Set_Interrupt(uint8_t bState)
{
//    uint8_t bIrq0EnReg = 0;
//    uint8_t bIrq1EnReg = 0;
//    phStatus_t status = PH_ERR_SUCCESS;
//
//    if (bState == PH_ON)
//    {
//        /* clear all IRQ0 flags */
//        status = phhalHw_WriteRegister(
//        	appData.pHal,
//            PHHAL_HW_RC523_REG_COMMIRQ,
//            (uint8_t)~(uint8_t)PHHAL_HW_RC523_BIT_SET);
////        CHECK_SUCCESS(status);
//
//        /* Route the RxIRQ to the IRQ pin of the PN512 */
//        status = phhalHw_ReadRegister(appData.pHal, PHHAL_HW_RC523_REG_COMMIEN, &bIrq0EnReg);
//        //CHECK_SUCCESS(status);
//
//        bIrq0EnReg &= PHHAL_HW_RC523_BIT_IRQINV;
//        bIrq0EnReg |= (PHHAL_HW_RC523_BIT_RXI | PHHAL_HW_RC523_BIT_IDLEI | PHHAL_HW_RC523_BIT_HIALERTI);
//        status = phhalHw_WriteRegister(appData.pHal, PHHAL_HW_RC523_REG_COMMIEN, bIrq0EnReg);
////        CHECK_SUCCESS(status);
//
//        /* Clear IRQ1 interrupt sources */
//        bIrq1EnReg &= PHHAL_HW_RC523_BIT_IRQPUSHPULL;
//        status = phhalHw_WriteRegister(appData.pHal, PHHAL_HW_RC523_REG_DIVIEN, bIrq1EnReg);
////        CHECK_SUCCESS(status);
//
//        /* Configure the LPC17xx GPIO 2.13 as Interrupt input */
//        GPIO_SetDir(2, 1<<13, 0);
//        /* Enable receiving interrupt on the pin */
//        GPIO_IntCmd(2, 1<<13, 1);
//        /* Enable IRQ Interrupts */
//        __enable_irq();
//
//        GPIO_ClearInt(2, 1<<13);
//        /* Enable External Interrupt */
//        NVIC_EnableIRQ(EINT3_IRQn);
//    }
//    else
//    {
//        NVIC_DisableIRQ(EINT3_IRQn);
//    }
//
    return;
}
/*==============================================================================================
 * Function:	PN512_IRQHandler
 *
 * brief:	Pin of interrupt EINT3 is attached to interrupt output pin of PN512. The purpose of
 * 				this interrupt handler is to detect RF signal from an Iniciator and thus the software
 * 				act like a target.
 *
 * -------------------------------------------------------------------------------------------*/
void PN512_IRQHandler()
{
//    uint32_t    regVal;
//    phStatus_t  status = 0;
//    uint8_t     bRegister1;
//    uint8_t     bRegister2;
//
//    PH_UNUSED_VARIABLE(status);
//
//    /* Read the interrupt status of GPIO 2.13 */
//    regVal = GPIO_GetIntStatus(2, 13, 1);
//    if (regVal == 1)
//    {
//        /* Read the registers commlRqReg and DivlEnReg and print them */
//        status = phhalHw_ReadRegister(appData.pHal, PHHAL_HW_RC523_REG_STATUS1, &bRegister1);
//
//        phhalHw_ReadRegister(appData.pHal, PHHAL_HW_RC523_REG_COMMIRQ, &bRegister2);
//
//        if (bRegister2 & (PHHAL_HW_RC523_BIT_RXI | PHHAL_HW_RC523_BIT_HIALERTI | PHHAL_HW_RC523_BIT_IDLEI))
//        {
//            Set_Interrupt(PH_OFF);
//            *((uint8_t *)appData.pData_ready) = (uint8_t)0x01;
//        }
//        GPIO_ClearInt(2, 1<<13);
//    }
//
    return;
}
#endif /* NXPBUILD__PHHAL_HW_RC523 */
/*----------------------------------------------------------------------------------------------
 * End of file
 ---------------------------------------------------------------------------------------------*/
