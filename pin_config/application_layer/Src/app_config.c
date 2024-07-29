/*
 * app.c
 *
 *  Created on: Jun 28, 2024
 *      Author: user
 */
#include <stdio.h>
#include "com_config.h"
#include "app_config.h"
#include <string.h>
#include "main.h"


int switch_val=0;
char buffer[11];
UART_HandleTypeDef huart1;
 char arr1[20];
 char arr2[10];
 int A[4];
 char *token;
 int flag;
 int* pin_status;


 void Configurator()
 {

 while (1)
 {
  if (flag)
  {
	  extract_data();
	  pin_config();
	  break;
  }
   pin_status = readpin_status();
 }
 }
	//data_receive();
   // clear_buffer();



//void clear_buffer()
//{
//	memset(buffer,0,sizeof (buffer));
//}

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
// {
//
//   HAL_UART_Receive_IT(&huart1, (uint8_t *)buffer, 20);
// }

 int* readpin_status()
 {
	 A[0]=read_gpio( GPIOA,GPIO_PIN_5);
	 A[1]=read_gpio( GPIOA,GPIO_PIN_6);
	 A[2]=read_gpio( GPIOB,GPIO_PIN_0);
	 A[3]=read_gpio( GPIOB,GPIO_PIN_1);
	 return A;
 }

//int isBufferNullTerminated(char *buffer, int bufferSize)
// {
//   for (int i = 8; i < bufferSize; i++)
//   {
//      if (buffer[i] == '\0')
//      {
//        return 1;  // Return 1 if null terminator is found
//      }
//   }
//        return 0;  // Return 0 if no null terminator is found
// }
void extract_data()
{
	token = strtok(buffer, ",");


		     if (token != NULL)
		     {
		         strncpy(arr1, token, sizeof(arr1) - 1);

		         arr1[sizeof(arr1) - 1] = '\0'; // Ensure null-termination
		         token = strtok(NULL, ",");
		     }

		     // Get the second token and store it in arr2
		     if (token != NULL)
		     {
		         strncpy(arr2, token, sizeof(arr2) - 1);
		         arr2[sizeof(arr2) - 1] = '\0'; // Ensure null-termination
		         //token = strtok(NULL, ",");
		     }

		     // Get the third token and store it in arr3
//		     if (token != NULL)
//		     {
//		         strncpy(arr3, token, sizeof(arr3) - 1);
//		         arr3[sizeof(arr3) - 1] = '\0'; // Ensure null-termination
//		     }
}


void pin_config()
{

	            if(strcmp(arr1,"A5")==0)
			     {
			       switch_val=1;
			     }
	            else if(strcmp(arr1,"A6")==0)
				 {
				   switch_val=2;
				 }
	            else if(strcmp(arr1,"B0")==0)
	           	 {
	           		switch_val=3;
	           	 }
	            else if(strcmp(arr1,"B1")==0)
	             {
	            	switch_val=4;
	             }


			     switch(switch_val)
			     {

			     case 1: if(strcmp(arr2,"OUTPUT")==0)
						{
			              user_GPIO_Init(GPIOA,GPIO_PIN_5,OUTPUT);
						  write_gpio(GPIOA,GPIO_PIN_5, PIN_SET);
						}

			              else if(strcmp(arr2,"INPUT")==0)
					    {
						   user_GPIO_Init(GPIOA,GPIO_PIN_5,INPUT);
						   A[0]=read_gpio( GPIOA,GPIO_PIN_5);
							{
							   if(A[0] == 1)
								{
								   user_output_GPIO_Init();
								   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_SET);//
								}

									else
								{
									HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_RESET);
								}
							}
					    }

			     }
}

//			     case 2: if(strcmp(arr2,"OUTPUT")==0)
//			    		{
//			    	      user_GPIO_Init(GPIOA,GPIO_PIN_6,OUTPUT);
//			    		  write_gpio(GPIOA,GPIO_PIN_6, PIN_SET);
//			    		}
//
//			    	     else if(strcmp(arr2,"INPUT")==0)
//			    		{
//			    		  user_GPIO_Init(GPIOA,GPIO_PIN_6,INPUT);
//			    		  A=read_gpio( GPIOA,GPIO_PIN_6);
//			    		{
//
//			    		 if(A == 1)
//			    		{
//			    		  user_output_GPIO_Init();
//			    		  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_SET);
//			    		}
//
//			    		 else
//			    	   {
//			    		  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_RESET);
//			    	   }
//			    	   }
//			    	   }
//
//
//			     case 3: if(strcmp(arr2,"OUTPUT")==0)
//			     		{
//			     		  user_GPIO_Init(GPIOB,GPIO_PIN_0,OUTPUT);
//			     		  write_gpio(GPIOB,GPIO_PIN_0, PIN_SET);
//			     	    }
//
//			     		 else if(strcmp(arr2,"INPUT")==0)
//			     		{
//			     		  user_GPIO_Init(GPIOB,GPIO_PIN_0,INPUT);
//			     		  A=read_gpio( GPIOB,GPIO_PIN_0);
//			     		{
//			     		 if(A == 1)
//			     		{
//			     		  user_output_GPIO_Init();
//			     		  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_SET);
//			     		}
//
//			     		  else
//			     	    {
//			     		  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_RESET);
//			     		}
//			     		}
//			     		}
//
//
//			     case 4: if(strcmp(arr2,"OUTPUT")==0)
//			    		{
//			    	      user_GPIO_Init(GPIOB,GPIO_PIN_1,OUTPUT);
//			    		  write_gpio(GPIOB,GPIO_PIN_1, PIN_SET);
//			    	    }
//
//			    		  else if(strcmp(arr2,"INPUT")==0)
//			    	    {
//			              user_GPIO_Init(GPIOB,GPIO_PIN_1,INPUT);
//			    		  A=read_gpio( GPIOB,GPIO_PIN_1);
//			    		{
//							 if(A == 1)
//							{
//							  user_output_GPIO_Init();
//							  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_SET);
//							}
//
//							 else
//							{
//							  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_RESET);
//							}
//			    		}
//			    	    }
//
//			    	}
//}











