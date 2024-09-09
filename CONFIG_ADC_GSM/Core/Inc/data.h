/*
 * data.h
 *
 *  Created on: Sep 6, 2024
 *      Author: KAVYA
 */

#ifndef INC_DATA_H_
#define INC_DATA_H_

struct data
 {
	uint8_t hr;
	uint8_t min;
	uint8_t sec;
	uint8_t day;
	uint8_t date;
	uint8_t month;
	uint8_t year;
	float adc1_value;
	float adc2_value;
	float adc3_value;
	float adc4_value;
	uint8_t GPIO[4];
	uint8_t scan_time;
	char Status1[10];
	char Status2[10];
	char Status3[10];
	char Status4[10];
 };

//extern struct data d;

#endif /* INC_DATA_H_ */
