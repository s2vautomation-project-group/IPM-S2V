/*
 * app_config.h
 *
 *  Created on: Aug 28, 2024
 *      Author: KAVYA
 */

#ifndef INC_APP_CONFIG_H_
#define INC_APP_CONFIG_H_

//void DataTOgsm();
//void gpiostatus(struct status d);
//void setTime(struct time t);
void set_output();
void reset_output();
uint8_t* read_pinstatus();
void Configurator();
void extract_data();
void pin_config();
void clear_buffer();



#endif /* INC_APP_CONFIG_H_ */
