/*
 * adc.h
 *
 *  Created on: Jul 23, 2024
 *      Author: Somanath
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_
void SystemClock_Config(void);
void USER_ADC1_Init(void);
void USER_GPIO_Init(void);
int adc_value(void);
#endif /* INC_ADC_H_ */
