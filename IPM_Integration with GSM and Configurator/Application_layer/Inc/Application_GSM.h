/*
 * Application_GSM.h
 *
 *  Created on: Aug 1, 2024
 *      Author: DELL
 */

#ifndef INC_APPLICATION_GSM_H_
#define INC_APPLICATION_GSM_H_


#include "main.h"
#include "Common_Gsm.h"

//void DataTosend(int rtcdatedata,int rtctimedata,float adcdata);
//void DataTosend(int hour,int minutes,int seconds,float adcdata);
void DataTosend(char* time,char* val);




#endif /* INC_APPLICATION_GSM_H_ */
