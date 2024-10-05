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
#include "app_RTC.h"
#include "com_RTC.h"
#include "app_ADC.h"
#include "com_ADC.h"
#include "app_GSM.h"
#include "com_GSM.h"
#include "com_terminal.h"
#include "app_terminal.h"
#include "app_config.h"
#include "com_config.h"
#include "comm_EEPROM.h"
#include "app_EEPROM.h"

struct data d;

void application(void)
{
	Configurator();
//	strcpy(d.CH1, "ADC1");
//	strcpy(d.CH2, "ADC2");
//	strcpy(d.CH3, "ADC3");
//	strcpy(d.CH4, "ADC4");
//	strcpy(d.Status1, "GPIO1");
//	strcpy(d.Status2, "GPIO2");
//	strcpy(d.Status3, "GPIO3");
//	strcpy(d.Status4, "GPIO4");
	get_time(&d);
    ADC_handler(&d);
	DataToGsm(&d);
	EEPROM();
	terminal(&d);


}
