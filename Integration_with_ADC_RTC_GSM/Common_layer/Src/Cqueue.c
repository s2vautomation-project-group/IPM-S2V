


/*-----------------------------------------------------------------------------------------------------------
 * Cqueue.c
 *
 *  Created on: 29-Apr-2021
 *      Author: Adarsh J K
 *---------------------------------------------------------------------------------------------------------*/

/* Header Files *------------------------------------------------------------------------------------------*/
#include "Cqueue.h"



 //cleanup and naming convention need to be changed and rearranged.
//QUEUE2_GEN(SPIQueue, uint8);

QUEUE2_GEN(UartQueue, uint8);

QUEUE2_GEN(UsartQueue, uint8);

//QUEUE2_GEN(I2CQueue, uint8);


///*----------------------------------------------* SPI *-------------------------------------------------*/
//QUEUE2_NEWVAR_GEN(SPIQueue, SPI1Queue, uint8, SPI_SPI1QUEUE_ELEMENTCOUNT);
//QUEUE2_NEWVAR_GEN(SPIQueue, SPI2Queue, uint8, SPI_SPI2QUEUE_ELEMENTCOUNT);
//QUEUE2_NEWVAR_GEN(SPIQueue, SPI3Queue, uint8, SPI_SPI3QUEUE_ELEMENTCOUNT);

/*----------------------------------------------* UART *-------------------------------------------------*/
QUEUE2_NEWVAR_GEN(UartQueue, Lpuart1Queue, uint8, UART_LPUART1QUEUE_ELEMENTCOUNT);
QUEUE2_NEWVAR_GEN(UsartQueue, Usart1Queue, uint8, USART_USART1QUEUE_ELEMENTCOUNT);
QUEUE2_NEWVAR_GEN(UsartQueue, Usart2Queue, uint8, USART_USART2QUEUE_ELEMENTCOUNT);
QUEUE2_NEWVAR_GEN(UsartQueue, Usart3Queue, uint8, USART_USART3QUEUE_ELEMENTCOUNT);
QUEUE2_NEWVAR_GEN(UartQueue, Uart4Queue, uint8, UART_UART4QUEUE_ELEMENTCOUNT);
QUEUE2_NEWVAR_GEN(UartQueue, Uart5Queue, uint8, UART_UART5QUEUE_ELEMENTCOUNT);

///*----------------------------------------------* I2C *-------------------------------------------------*/
//QUEUE2_NEWVAR_GEN(I2CQueue, I2C1Queue, uint8, I2C_I2C1QUEUE_ELEMENTCOUNT);
//QUEUE2_NEWVAR_GEN(I2CQueue, I2C2Queue, uint8, I2C_I2C2QUEUE_ELEMENTCOUNT);
//QUEUE2_NEWVAR_GEN(I2CQueue, I2C3Queue, uint8, I2C_I2C3QUEUE_ELEMENTCOUNT);
//QUEUE2_NEWVAR_GEN(I2CQueue, I2C4Queue, uint8, I2C_I2C4QUEUE_ELEMENTCOUNT);
////



