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
#include <stdlib.h>
#include"com_adc.h"
#include"app_adc.h"

//#define ADC_CHANNEL_5 CHANNEL_5

int switch_val=0;
char tx_data[15];
UART_HandleTypeDef huart1;
char arr1[10];
char arr2[10];
char *token;
int flag;
uint8_t* pin_status;
char config[4];
uint8_t s[4];
extern struct status d;

 void Configurator()
 {
	 data_receive();

		  if (tx_data[0] != '\0')
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
	        //clear_buffer();
           }
            reset_output();
           	set_output();
            pin_status = read_pinstatus();
//            status_transmit();
            //DataTOgsm(d);


 }

 void clear_buffer()
{
	memset(tx_data,0,sizeof (tx_data));
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
		 d.gpio[0] = write_gpio(GPIOB,GPIO_PIN_0, PIN_SET);
	}

	if(config[1] == 0)
	{
		d.gpio[1] = write_gpio(GPIOB,GPIO_PIN_1, PIN_SET);
	}

	if(config[2] == 0)
	{
		d.gpio[2] = write_gpio(GPIOB,GPIO_PIN_4, PIN_SET);
	}

	if(config[3] == 0)
	{
		d.gpio[3] = write_gpio(GPIOB,GPIO_PIN_5, PIN_SET);
	}
 }

 void reset_output()
  {
 	 if(config[0] == 0)
 	{
 		d.gpio[0] = write_gpio(GPIOB,GPIO_PIN_0, PIN_RESET);
 	}

 	if(config[1] == 0)
 	{
 		d.gpio[1]=write_gpio(GPIOB,GPIO_PIN_1, PIN_RESET);
 	}

 	if(config[2] == 0)
 	{
 		d.gpio[2] = write_gpio(GPIOB,GPIO_PIN_4, PIN_RESET);
 	}

 	if(config[3] == 0)
 	{
 		d.gpio[3] = write_gpio(GPIOB,GPIO_PIN_5, PIN_RESET);
 	}
  }

 uint8_t* read_pinstatus()
 {
	 if(config[0]==1)
	 {
	     d.gpio[0]=read_gpio( GPIOB,GPIO_PIN_0);
	 }
	 if(config[1]==1)
	 {
		 d.gpio[1]=read_gpio( GPIOB,GPIO_PIN_1);
	 }
	 if(config[2]==1)
	 {
	    d.gpio[2]=read_gpio( GPIOB,GPIO_PIN_4);
	 }
	if(config[3]==1)
	{
	   d.gpio[3]=read_gpio( GPIOB,GPIO_PIN_5);
    }
	 return d.gpio;
 }


void extract_data()
{
	token = strtok(tx_data, ",");


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

//void DataTOgsm(struct status d)
//{
//	//gpiostatus(d);
//}
//
//void gpiostatus(struct status d)
//{
//	 s[0]=d.gpio[0];
//	 s[1]=d.gpio[1];
//	 s[2]=d.gpio[2];
//	 s[3]=d.gpio[3];
//	 s[4]=d.SCANTIME;
//}

void pin_config()
{

	            if(strcmp(arr1,"B0")==0)
			     {
			       switch_val=1;
			     }

	            else if(strcmp(arr1,"B1")==0)
				 {
				   switch_val=2;
				 }

	            else if(strcmp(arr1,"B4")==0)
	           	 {
	           		switch_val=3;
	           	 }

	            else if(strcmp(arr1,"B5")==0)
                 {
				    switch_val=4;
				 }

	            else if(strcmp(arr1,"ADC1")==0)
				 {
					switch_val=5;
				 }

	            else if(strcmp(arr1,"RTC")==0)
	             {
	            	switch_val=6;
	             }

	            else if(strcmp(arr1,"SCANTIME")==0)
				 {
					switch_val=7;
				 }


			     switch(switch_val)
			     {

			     case 1:
			    	 	if(strcmp(arr2,"OUTPUT")==0)
						{
			              user_GPIO_Init(GPIOB,GPIO_PIN_0,OUTPUT);
					      config[0] = 0;
						}

			              else if(strcmp(arr2,"INPUT")==0)
					    {
						   user_GPIO_Init(GPIOB,GPIO_PIN_0,INPUT);
						   config[0] = 1;
					    }
			     break;

			   case 2:
				    	if(strcmp(arr2,"OUTPUT")==0)
			    		{
			    	      user_GPIO_Init(GPIOB,GPIO_PIN_1,OUTPUT);
			    	      config[1]=0;
			    		}

			    	     else if(strcmp(arr2,"INPUT")==0)
			    		{
			    		  user_GPIO_Init(GPIOB,GPIO_PIN_1,INPUT);
			    		  config[1]=1;
			    		}
	    	    break;

			     case 3:
			    	 	if(strcmp(arr2,"OUTPUT")==0)
			     		{
			     		  user_GPIO_Init(GPIOB,GPIO_PIN_4,OUTPUT);
			     		  config[2]=0;
			     	    }

			     		 else if(strcmp(arr2,"INPUT")==0)
			     		{
			     		  user_GPIO_Init(GPIOB,GPIO_PIN_4,INPUT);
			     		  config[2]=1;
			     		}

			     break;

			     case 4:
			    	 	 if(strcmp(arr2,"OUTPUT")==0)
			    		{
			    	      user_GPIO_Init(GPIOB,GPIO_PIN_5,OUTPUT);
			    		  config[3]=0;
			    	    }

			    		  else if(strcmp(arr2,"INPUT")==0)
			    	    {
			              user_GPIO_Init(GPIOB,GPIO_PIN_5,INPUT);
			              config[3]=1;
			    	    }
			     break;

			     case 5:
						 if(strcmp(arr2,"CH1")==0)
						{
							 ADC_channel_set(CHANNEL_5);
						}

						  if(strcmp(arr2,"CH2")==0)
						{
							  ADC_channel_set(CHANNEL_6);
						}
				 break;

//			     case 6:

//				  token = strtok(arr2, ":");
//
//				 // Get the first token and convert to integer
//				 if (token != NULL)
//				 {
//					 time.hour = atoi(token);
//					 token = strtok(NULL, ":");
//				 }
//
//				 // Get the second token and convert to integer
//				 if (token != NULL)
//				 {
//					 time.minutes = atoi(token);
//					 token = strtok(NULL, ":");
//				 }
//
//				 // Get the third token and convert to integer
//				 if (token != NULL)
//				 {
//
//					 time.seconds = atoi(token);
//				 }
//				 Set_Time(time);
//
//			 break;
//			     case 7:
//			    	 d.SCANTIME = (uint8_t)atoi(arr2);
//			    	 DataTOgsm(d);
			     }
}













