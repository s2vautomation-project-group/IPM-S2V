/*
 * IPM.c
 *
 *  Created on: Sep 11, 2024
 *      Author: KAVYA
 */
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ctype.h"
#include "data.h"
#include "app_EEPROM.h"
#include "com_EEPROM.h"
#include "app_RTC.h"
#include "com_RTC.h"
#include "app_config.h"
#include "com_config.h"
#include "com_ADC.h"
#include "app_ADC.h"
#include "app_GSM.h"
#include "com_GSM.h"
#include "com_terminal.h"
#include "app_terminal.h"


struct data d;

void application(void)
{

	Configurator();

//	set_time(57,01,13,6,03,01,25);
	get_time(&d);
    ADC_handler(&d);
	DataToGsm(&d);
//	EEPROM_transmit(&d);
	terminal(&d);


}
