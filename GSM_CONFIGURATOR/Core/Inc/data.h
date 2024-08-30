/*
 * data.h
 *
 *  Created on: Aug 28, 2024
 *      Author: KAVYA
 */

#ifndef INC_DATA_H_
#define INC_DATA_H_

struct data
 {
	uint8_t hr;
	uint8_t min;
	uint8_t sec;
	char CH1[10];
	char CH2[10];
	char CH3[10];
	char CH4[10];
	uint8_t GPIO[4];
	uint8_t scan_time;
	char Status1[10];
	char Status2[10];
	char Status3[10];
	char Status4[10];
 };


#endif /* INC_DATA_H_ */
