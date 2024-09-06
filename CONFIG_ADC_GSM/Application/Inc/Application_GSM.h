/*
 * Application_GSM.h
 *
 *  Created on: Sep 6, 2024
 *      Author: KAVYA
 */

#ifndef INC_APPLICATION_GSM_H_
#define INC_APPLICATION_GSM_H_

#include "main.h"
#include "Common_GSM.h"
#include "data.h"

//void DataTosend(char* time,char* CH1,char* CH2,char* CH3,char* CH4,char* D1,char* D2,char* D3,char* D4);
void DataToGsm(struct data *d);
//void DataToGsm();


#endif /* INC_APPLICATION_GSM_H_ */
