/*
 * data.h
 *
 *  Created on: Sep 19, 2024
 *      Author: user
 */

#ifndef INC_DATA_H_
#define INC_DATA_H_

struct data
{
	unsigned char seconds;
	unsigned char minutes;
	unsigned char hour;
	char dayofweek;
	char dayofmonth;
	char month;
	char year;
		float adc1_value;
		float adc2_value;
		float adc3_value;
		float adc4_value;
		uint8_t GPIO[4];
		uint8_t scan_time;
//	char CH1[10];
//	char CH2[10];
//	char CH3[10];
//	char CH4[10];
	char Status1[10];
	char Status2[10];
	char Status3[10];
	char Status4[10];
	char arr1[10];
	char arr2[10];
};

extern struct data d;



#endif /* INC_DATA_H_ */
