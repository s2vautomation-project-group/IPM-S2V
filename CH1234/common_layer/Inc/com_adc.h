/*
 * com_adc.h
 *
 *  Created on: Aug 8, 2024
 *      Author: Somanath
 */

#ifndef INC_COM_ADC_H_
#define INC_COM_ADC_H_
void USER_SystemClock_Config(void);
void USER_ADC1_Init(void);
void USER_GPIO_Init(void);
void adc_start(void);
void adc_conversion(void);
uint16_t adc_value(void);
void adc_stop(void);
void ADC_select_CH5(void);
void ADC_select_CH6(void);
#endif /* INC_COM_ADC_H_ */
