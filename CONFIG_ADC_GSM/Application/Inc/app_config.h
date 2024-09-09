/*
 * app_config.h
 *
 *  Created on: Sep 6, 2024
 *      Author: KAVYA
 */

#ifndef APPLICATION_INC_APP_H_
#define APPLICATION_INC_APP_H_




//struct status
//{
//	uint8_t gpio[4];
//    uint8_t SCANTIME;
//};

//extern struct status d;

void DataTOgsm();
void gpiostatus(struct data d);
//void setTime(struct time t);
void set_output();
void reset_output();
uint8_t* read_pinstatus();
void Configurator();
void extract_data();
void pin_config();
void clear_buffer();


#endif /* APPLICATION_INC_APP_H_ */
