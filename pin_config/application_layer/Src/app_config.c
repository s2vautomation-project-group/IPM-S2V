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
 char arr1[10];
 char arr2[10];
 char A[4];
 char *token;
 int flag;
 char* pin_status;
 uint8_t config[4];

 void Configurator()
 {
	 data_receive();

		  if (buffer[0] != '\0')
		   {
		     flag = 1; // Set flag to indicate data has been received
		   }
		   else
		   {
			   flag=0;
		   }

           if (flag)
           {
	        extract_data();
	        pin_config();
	        clear_buffer();
           }

           	set_output();
            pin_status = readpin_status();
            status_transmit();
//            if(read_gpio(GPIOA, GPIO_PIN_5))
//            {
//            	write_gpio(GPIOB, GPIO_PIN_0, PIN_SET);
//            }
//            else
//            	write_gpio(GPIOB, GPIO_PIN_0, PIN_RESET);



  }

 void clear_buffer()
{
	memset(buffer,0,sizeof (buffer));
}

//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
// {
//
//   HAL_UART_Receive_IT(&huart1, (uint8_t *)buffer, 20);
// }

 void set_output()
 {
 if(config[0] == 0)
            {
				write_gpio(GPIOA,GPIO_PIN_5, PIN_SET);
            }

            if(config[1] == 0)
			{
				write_gpio(GPIOA,GPIO_PIN_6, PIN_SET);
			}

            if(config[2] == 0)
			{
				write_gpio(GPIOB,GPIO_PIN_0, PIN_SET);
			}
            if(config[3] == 0)
			{
				write_gpio(GPIOB,GPIO_PIN_1, PIN_SET);
			}
 }

 char* readpin_status()
 {
	 if(config[0]==1)
	 {
	     A[0]=read_gpio( GPIOA,GPIO_PIN_5);
	 }
	 if(config[1]==1)
	 {
		 A[1]=read_gpio( GPIOA,GPIO_PIN_6);
	 }
	 if(config[2]==1)
	 {
	    A[2]=read_gpio( GPIOB,GPIO_PIN_0);
	 }
	if(config[3]==1)
	{
	   A[3]=read_gpio( GPIOB,GPIO_PIN_1);
    }
	 return A;
 }


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

			     case 1: //{
			    	 	if(strcmp(arr2,"OUTPUT")==0)
						{
			              user_GPIO_Init(GPIOA,GPIO_PIN_5,OUTPUT);
//						  write_gpio(GPIOA,GPIO_PIN_5, PIN_SET);
					      config[0] = 0;
						}

			              else if(strcmp(arr2,"INPUT")==0)
					    {
						   user_GPIO_Init(GPIOA,GPIO_PIN_5,INPUT);
						   //A[0]=read_gpio( GPIOA,GPIO_PIN_5);
						   config[0] = 1;
//							{
//							   if(A[0] == 1)
//								{
//								   user_output_GPIO_Init();
//								   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_SET);//
//								}
//
//									else
//								{
//									HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_RESET);
//								}
//							}
					    }
			     //}
			     break;

			   case 2: //{
				    	if(strcmp(arr2,"OUTPUT")==0)
			    		{
			    	      user_GPIO_Init(GPIOA,GPIO_PIN_6,OUTPUT);
//			    		 write_gpio(GPIOA,GPIO_PIN_6, PIN_SET);
			    	      config[1]=0;
			    		}

			    	     else if(strcmp(arr2,"INPUT")==0)
			    		{
			    		  user_GPIO_Init(GPIOA,GPIO_PIN_6,INPUT);
			    		  //A[1]=read_gpio( GPIOA,GPIO_PIN_6);
			    		  config[1]=1;
//			    		{

//			    		 if(A[1] == 1)
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
			    		}
			   //}
				    	break;

			     case 3: //{
			    	 	if(strcmp(arr2,"OUTPUT")==0)
			     		{
			     		  user_GPIO_Init(GPIOB,GPIO_PIN_0,OUTPUT);
//			     		  write_gpio(GPIOB,GPIO_PIN_0, PIN_SET);
			     		  config[2]=0;
			     	    }

			     		 else if(strcmp(arr2,"INPUT")==0)
			     		{
			     		  user_GPIO_Init(GPIOB,GPIO_PIN_0,INPUT);
			     		// A[2]=read_gpio( GPIOB,GPIO_PIN_0);
			     		 config[2]=1;

//			     		{
//			     		 if(A[2] == 1)
//			     		{
//			     		  user_output_GPIO_Init();
//			     		  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_SET);
//			     		}
//
//			     		  else
//			     	    {
//			     		  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,PIN_RESET);
//			     		}
			     		}
//			     		}
//			     }
			     break;

			     case 4: //{
			    	 	 if(strcmp(arr2,"OUTPUT")==0)
			    		{
			    	      user_GPIO_Init(GPIOB,GPIO_PIN_1,OUTPUT);
//			    		  write_gpio(GPIOB,GPIO_PIN_1, PIN_SET);
			    		  config[3]=0;
			    	    }

			    		  else if(strcmp(arr2,"INPUT")==0)
			    	    {
			              user_GPIO_Init(GPIOB,GPIO_PIN_1,INPUT);
//			              A[3]=read_gpio( GPIOB,GPIO_PIN_1);
			              config[3]=1;
//			    		{
//							 if(A[3] == 1)
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
			    	    }

//			    	}
			     break;
			     }

}











