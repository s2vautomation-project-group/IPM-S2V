/*
 * data.h
 *
 *  Created on: Dec 4, 2024
 *      Author: KAVYA
 */

#ifndef INC_DATA_H_
#define INC_DATA_H_


struct data
{
	char seconds;
	char minutes;
	char hour;
	char dayofweek;
	char dayofmonth;
	char month;
	char year;
	char arr1[10];
	char arr2[10];
		float adc1_value;
		float adc2_value;
		float adc3_value;
		float adc4_value;
		float MDS_value;
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
};

extern struct data d;


#endif /* INC_DATA_H_ */
