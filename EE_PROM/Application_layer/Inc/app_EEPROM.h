/*
 * app_EEPROM.h
 *
 *  Created on: Sep 24, 2024
 *      Author: User
 */

#ifndef INC_APP_EEPROM_H_
#define INC_APP_EEPROM_H_

#include "main.h"
#include "data.h"


// EEPROM data structure
struct eeprom_data
{
    uint8_t scan_time;
    char seconds;
    char minutes;
    char hour;
    char dayofmonth;
    char month;
    char year;
    float adc1_value;
    float adc2_value;
    float adc3_value;
    float adc4_value;
    char Status1[10];
    char Status2[10];
    char Status3[10];
    char Status4[10];
};

struct eeprom_data ed;


void store_data_in_eeprom(struct eeprom_data *ed);
void read_data_from_eeprom(struct eeprom_data *ed, uint16_t address);
void convert_data_to_eeprom_data(struct data *d, struct eeprom_data *ed);
void CheckAndStoreData(struct data *d);
void Application(void);



#endif /* INC_APP_EEPROM_H_ */
