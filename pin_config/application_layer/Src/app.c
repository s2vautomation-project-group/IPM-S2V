/*
 * app.c
 *
 *  Created on: Jun 28, 2024
 *      Author: user
 */

#include "app.h"
#include "com.h"
#include<string.h>
#include "main.h"

int A;
int switch_val=0;
char buffer[20];

 char arr1[20];
 char arr2[20];
extern char arr3[20];
 char *token;
uint8_t button_state;



void APPLICATION()
{
    clear_buffer();
	data_receive();
	extract_data();
	pin_config();

}

void clear_buffer()
{
	memset(buffer,0,sizeof (buffer));
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
		         token = strtok(NULL, ",");
		     }

		     // Get the third token and store it in arr3
		     if (token != NULL)
		     {
		         strncpy(arr3, token, sizeof(arr3) - 1);
		         arr3[sizeof(arr3) - 1] = '\0'; // Ensure null-termination
		     }
}


void pin_config()
{

	            if(strcmp(arr1,"GPIO1")==0)
			     {
			       switch_val=1;
			     }
	            else if(strcmp(arr1,"GPIO2")==0)
				 {
				   switch_val=2;
				 }
	            else if(strcmp(arr1,"GPIO3")==0)
	           	 {
	           		switch_val=3;
	           	 }
	            else if(strcmp(arr1,"GPIO4")==0)
	             {
	            	switch_val=4;
	             }


			     switch(switch_val)
			     {
			      case 1:if(strcmp(arr2,"A3")==0)
			            {
			             if(strcmp(arr3,"OUTPUT")==0)
						{
			              user_GPIO_Init(GPIOA,GPIO_PIN_3,OUTPUT);
						  write_gpio(GPIOA,GPIO_PIN_3, PIN_SET);
						}

			              else if(strcmp(arr3,"INPUT")==0)
					    {
						   user_GPIO_Init(GPIOA,GPIO_PIN_3,INPUT);
						   A=read_gpio( GPIOA,GPIO_PIN_3);

						   if(A == 1)
						{
						   user_output_GPIO_Init();
						   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,PIN_SET);
						}

							else
					    {
						    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,PIN_RESET);
					    }

					    }
			            }
			     }
}


//			      case 2:if(strcmp(arr2,"A4")==0)
//			      		{
//			      		  if(strcmp(arr3,"OUTPUT")==0)
//			            {
//			               user_GPIO_Init();
//			               write_gpio(GPIOA,GPIO_PIN_4, GPIO_PIN_SET);
//			      		}
//
//			      		   else if(strcmp(arr3,"INPUT")==0)
//			      		{
//			      		   user_GPIO_Init();
//			      		   A=read_gpio( GPIOA,GPIO_PIN_4);
//			      	    }
//			      		}
//
//			      case 3:if(strcmp(arr2,"A5")==0)
//			      		{
//			      		  if(strcmp(arr3,"OUTPUT")==0)
//			      	    {
//			      		  user_GPIO_Init();
//			      		  write_gpio(GPIOA,GPIO_PIN_5, GPIO_PIN_SET);
//			      		}
//
//			      		   else if(strcmp(arr3,"INPUT")==0)
//			      	    {
//			      		   user_GPIO_Init();
//			      		   A=read_gpio( GPIOA,GPIO_PIN_5);
//			        		 if(A == 1)
//			      		 {
//			      		   user_output_GPIO_Init();
//			      		   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
//			      		 }
//			      		  else
//			      		 {
//			      		    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);
//			      		 }
//			      	    }
//			      		}
//
//			      case 4:if(strcmp(arr2,"A6")==0)
//			      		{
//			      	     if(strcmp(arr3,"OUTPUT")==0)
//			      	    {
//			      		  user_GPIO_Init();
//			      		  write_gpio(GPIOA,GPIO_PIN_6, GPIO_PIN_SET);
//			      		}
//
//			      		  else if(strcmp(arr3,"INPUT")==0)
//			      	    {
//			      		  user_GPIO_Init();
//			      		  A=read_gpio( GPIOA,GPIO_PIN_6);
//
//			      	    }
//
//
//			      		}
//			      	    }
//}











