
/*-----------------------------------------------------------------------------------------------------------
 * Cqueue.h
 *
 *  Created on: 29-Apr-2021
 *      Author: Adarsh J K
 *---------------------------------------------------------------------------------------------------------*/

#ifndef INC_MD_QUEUE_INIT_H_
#define INC_MD_QUEUE_INIT_H_

#include "main.h"


typedef unsigned long uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef unsigned long long uint64;

typedef signed long sint32;
typedef signed short sint16;
typedef signed char sint8;


typedef uint8 boolean;
//typedef uint8 bool;
#define FALSE 0
#define TRUE (!FALSE)

#define NULL_PTR ((void*)0)
#define ASSERT while(1){\
};

/*--------------------------------------------* QUEUE *---------------------------------------------*/

#define MODULENAME_QUEUENAME_INTDISABLE()
#define MODULENAME_QUEUENAME_INTENABLE()




/*-------------------------------* queue generator with array pointer *-----------------------------------*/
#define QUEUE2_PROTOTYPEGEN(queue_type,var_type)\
		typedef struct\
		{\
			uint16 Top,Bottom;\
			uint16 DataSize;\
			var_type* Arr;\
		}queue_type;\
		void Init_##queue_type(queue_type* qp);\
		uint8 Insert_##queue_type(queue_type* qp,var_type el);\
		uint8 Peek_##queue_type(queue_type* qp,var_type* el,uint32 Count);\
		uint8 Remove_##queue_type(queue_type* qp,var_type* el);\
		uint8 Is_##queue_type##Full(queue_type* qp);\
		uint8 Is_##queue_type##Empty(queue_type* qp);\
		uint16 queue_type##_SpaceAvailable(queue_type* qp);\
		uint32 queue_type##_FormQueueVar(uint8* inbuffer, uint32 Bufflen, uint32 Elementcount, queue_type** queue_type##_ppst);\

#define QUEUE2_VARPROTOTYPE_GEN(queue_type,var_name,var_type,datasize)\
		extern queue_type var_name;

#define QUEUE2_NEWVAR_GEN(queue_type,var_name,var_type,datasize)\
		static var_type var_name##_a[datasize];\
		queue_type var_name=\
		{\
			0,\
			0,\
			datasize,\
			var_name##_a,\
		};\

#ifndef ALLIGNSIZE
#define ALLIGNSIZE(x)(((x)%4==0)?(x):(x) + (4-((x)%4)))
#endif



#define QUEUE2_GEN(queue_type,var_type)\
		\
		\
		\
		void Init_##queue_type(queue_type* qp)\
		{\
			qp->Top=0;\
			qp->Bottom=0;\
		}\
		\
		uint8 Insert_##queue_type(queue_type* qp,var_type el)\
		{\
			if((qp->Top+1)%(qp->DataSize)==qp->Bottom)/*overflow*/\
		{\
				return(0);\
		}\
		qp->Arr[qp->Top]=el;\
		qp->Top=(qp->Top+1)%(qp->DataSize);\
		return(1);\
		}\
		\
		\
		uint8 Remove_##queue_type(queue_type* qp,var_type* el)\
		{\
			if(qp->Top==qp->Bottom)/*underflow*/\
		{\
				return(0);\
		}\
		*el=qp->Arr[qp->Bottom];\
		qp->Bottom=(qp->Bottom+1)%(qp->DataSize);\
		return(1);\
		}\
		uint8 Peek_##queue_type(queue_type* qp,var_type* el,uint32 Count)\
		{\
			int i = 0;\
			for(i = 0; i < Count; i++)\
			{\
				if(qp->Top != (qp->Bottom + i)%(qp->DataSize))\
				{\
					el[i] = qp->Arr[(qp->Bottom + i)%(qp->DataSize)];\
				}\
				else\
				{\
					break;\
				}\
			}\
			return(i);\
		}\
		\
		\
		uint8 Is_##queue_type##Full(queue_type* qp)\
		{\
			if((qp->Top+1)%(qp->DataSize)==qp->Bottom)\
			{\
				return(1);\
			}\
			else\
			return(0);\
		}\
		uint8 Is_##queue_type##Empty(queue_type* qp)\
		{\
			if(qp->Top==qp->Bottom)\
			{\
				return(1);\
			}\
			else\
			return(0);\
		}\
		uint16 queue_type##_SpaceAvailable(queue_type* qp)\
		{\
			if(qp->Top >= qp->Bottom)\
			{\
				return(qp->DataSize - (qp->Top - qp->Bottom) - 1);\
			}\
			else\
			{\
				return(qp->Bottom - qp->Top - 1);\
			}\
		}\
		uint32 queue_type##_FormQueueVar(uint8* inbuffer, uint32 Bufflen, uint32 Elementcount, queue_type** queue_type##_ppst)\
		{\
			uint8* buffer = inbuffer;\
			uint32 UsedLength = 0;\
			*queue_type##_ppst = NULL_PTR;\
		\
			if(Bufflen > ALLIGNSIZE(sizeof(queue_type)) + ALLIGNSIZE(sizeof(var_type)*Elementcount) + (buffer - (uint8*)ALLIGNSIZE((uint32)buffer)))\
			{\
				buffer = (uint8*)ALLIGNSIZE((uint32)buffer);\
				*queue_type##_ppst = (queue_type*)buffer;\
				buffer += ALLIGNSIZE(sizeof(queue_type));\
				(*queue_type##_ppst)->Bottom = 0;\
				(*queue_type##_ppst)->Top = 0;\
				if(Elementcount == 0)\
				{\
					Elementcount = (Bufflen - (inbuffer - buffer))/sizeof(var_type);\
				}\
				(*queue_type##_ppst)->DataSize = Elementcount;\
				(*queue_type##_ppst)->Arr = (var_type*)buffer;\
				buffer += ALLIGNSIZE(sizeof(var_type)*Elementcount);\
				ASSERT((inbuffer - buffer) != (ALLIGNSIZE(sizeof(queue_type)) + ALLIGNSIZE(sizeof(var_type)*Elementcount) + (buffer - (uint8*)ALLIGNSIZE((uint32)buffer))));\
				UsedLength = inbuffer - buffer;\
				ASSERT(UsedLength > Bufflen);\
			}\
			return(UsedLength);\
		}\





//QUEUE2_PROTOTYPEGEN(SPIQueue, uint8);

QUEUE2_PROTOTYPEGEN(UartQueue, uint8);

QUEUE2_PROTOTYPEGEN(UsartQueue, uint8);

//QUEUE2_PROTOTYPEGEN(I2CQueue, uint8);


//#define SPI_SPI1QUEUE_ELEMENTCOUNT 100
//	QUEUE2_VARPROTOTYPE_GEN(SPIQueue, SPI1Queue, uint8, SPI_SPI1QUEUE_ELEMENTCOUNT);
//
//#define SPI_SPI2QUEUE_ELEMENTCOUNT 100
//	QUEUE2_VARPROTOTYPE_GEN(SPIQueue, SPI2Queue, uint8, SPI_SPI2QUEUE_ELEMENTCOUNT);
//
//#define SPI_SPI3QUEUE_ELEMENTCOUNT 100
//	QUEUE2_VARPROTOTYPE_GEN(SPIQueue, SPI3Queue, uint8, SPI_SPI3QUEUE_ELEMENTCOUNT);



#define UART_LPUART1QUEUE_ELEMENTCOUNT 100
QUEUE2_VARPROTOTYPE_GEN(UartQueue, Lpuart1Queue, uint8, UART_LPUART1QUEUE_ELEMENTCOUNT);


#define USART_USART1QUEUE_ELEMENTCOUNT 100
QUEUE2_VARPROTOTYPE_GEN(UsartQueue, Usart1Queue, uint8, USART_USART1QUEUE_ELEMENTCOUNT);

#define USART_USART2QUEUE_ELEMENTCOUNT 100
QUEUE2_VARPROTOTYPE_GEN(UsartQueue, Usart2Queue, uint8, USART_USART2QUEUE_ELEMENTCOUNT);


#define USART_USART3QUEUE_ELEMENTCOUNT 100
QUEUE2_VARPROTOTYPE_GEN(UsartQueue, Usart3Queue, uint8, USART_USART3QUEUE_ELEMENTCOUNT);\

#define UART_UART4QUEUE_ELEMENTCOUNT 100
QUEUE2_VARPROTOTYPE_GEN(UartQueue, Uart4Queue, uint8, UART_UART4QUEUE_ELEMENTCOUNT);


#define UART_UART5QUEUE_ELEMENTCOUNT 100
QUEUE2_VARPROTOTYPE_GEN(UartQueue, Uart5Queue, uint8, UART_UART5QUEUE_ELEMENTCOUNT);


//#define I2C_I2C1QUEUE_ELEMENTCOUNT 100
//	QUEUE2_VARPROTOTYPE_GEN(I2CQueue, I2C1Queue, uint8, I2C_I2C1QUEUE_ELEMENTCOUNT);
//
//#define I2C_I2C2QUEUE_ELEMENTCOUNT 100
//	QUEUE2_VARPROTOTYPE_GEN(I2CQueue, I2C2Queue, uint8, I2C_I2C2QUEUE_ELEMENTCOUNT);
//
//#define I2C_I2C3QUEUE_ELEMENTCOUNT 100
//	QUEUE2_VARPROTOTYPE_GEN(I2CQueue, I2C3Queue, uint8, I2C_I2C3QUEUE_ELEMENTCOUNT);
//
//#define I2C_I2C4QUEUE_ELEMENTCOUNT 100
//	QUEUE2_VARPROTOTYPE_GEN(I2CQueue, I2C4Queue, uint8, I2C_I2C4QUEUE_ELEMENTCOUNT);

#endif /* INC_MD_QUEUE_INIT_H_ */



