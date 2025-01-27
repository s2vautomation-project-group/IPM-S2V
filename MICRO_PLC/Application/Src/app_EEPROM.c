/*
 * app_EEPROM.c
 *
 *  Created on: Dec 4, 2024
 *      Author: KAVYA
 */
#include "main.h"
#include "string.h"
#include "app_GSM.h"
#include "com_GSM.h"
#include "EEPROM.h"
#include "stdio.h"
#include "app_EEPROM.h"
#include "com_EEPROM.h"
#include "data.h"

#define NUM_PAGES 5       // Total number of pages (500 in your case)
#define PAGES_PER_ERASE 2   // Number of pages to erase at a time (pair of pages)
#define MAX_PAGES 5       // Maximum pages in your EEPROM (adjust as necessary)
#define PAGE_SIZE 64


uint8_t DataRead[640];
char eeprom_data[200];



char edata[200];
char* etoken;
extern char CH1[10];
extern char CH2[10];
extern char CH3[10];
extern char CH4[10];
extern char MDS[10];

char etime[9], edate[9], ech1[10], ech2[10], ech3[10], ech4[10], emds[10];
char estatus1[10], estatus2[10], estatus3[10], estatus4[10];



void EEPROM_transmit(struct data *d)
{

	sprintf((char *)eeprom_data,"Time:%02d:%02d:%02d,Date:%02d/%02d/%02d,CH1:%.2f,CH2:%.2f,CH3:%.2f,CH4:%.2f,MDS:%.2f,Status1:%s,Status2:%s,Status3:%s,Status4:%s",
			d->hour, d->minutes, d->seconds,d->dayofmonth, d->month, d->year,
			d->adc1_value, d->adc2_value, d->adc3_value, d->adc4_value,
			d->MDS_value, d->Status1, d->Status2, d->Status3, d->Status4);

		Data_To_EEPROM(eeprom_data);  // Write data to the EEPROM

}


void EEPROM_DataGS()
{
	EEPROM_Read(0, 0, DataRead, 640);
	int page = 0;  // Start from the first page
	for (int gspage = 0; gspage < NUM_PAGES; gspage += 2)
	{
		EEPROM_Read(gspage, 0, DataRead, PAGE_SIZE);       // Read from page 'page'
		EEPROM_Read(gspage + 1, 0, DataRead + PAGE_SIZE, PAGE_SIZE); // Read from page 'page+1'

		etoken = strtok((char*)DataRead, ",");

		while (etoken != NULL) {
			if (strncmp(etoken, "Time:", 5) == 0) {
				strncpy(etime, etoken + 5, 8);  // Copy time value after "Time:"
				etime[8] = '\0';  // Null-terminate the string
			} else if (strncmp(etoken, "Date:", 5) == 0) {
				strncpy(edate, etoken + 5, 8);  // Copy date value after "Date:"
				edate[8] = '\0';  // Null-terminate the string
			} else if (strncmp(etoken, "CH1:", 4) == 0) {
				strncpy(ech1, etoken + 4, 9);  // Copy CH1 value after "CH1:"
				ech1[9] = '\0';  // Null-terminate the string
			} else if (strncmp(etoken, "CH2:", 4) == 0) {
				strncpy(ech2, etoken + 4, 9);  // Copy CH2 value after "CH2:"
				ech2[9] = '\0';  // Null-terminate the string
			} else if (strncmp(etoken, "CH3:", 4) == 0) {
				strncpy(ech3, etoken + 4, 9);  // Copy CH3 value after "CH3:"
				ech3[9] = '\0';  // Null-terminate the string
			} else if (strncmp(etoken, "CH4:", 4) == 0) {
				strncpy(ech4, etoken + 4, 9);  // Copy CH4 value after "CH4:"
				ech4[9] = '\0';  // Null-terminate the string
			} else if (strncmp(etoken, "MDS:", 4) == 0) {
				strncpy(emds, etoken + 4, 9);  // Copy MDS value after "MDS:"
				emds[9] = '\0';  // Null-terminate the string
			} else if (strncmp(etoken, "Status1:", 8) == 0) {
				strncpy(estatus1, etoken + 8, 9);  // Copy Status1 value after "Status1:"
				estatus1[9] = '\0';  // Null-terminate the string
			} else if (strncmp(etoken, "Status2:", 8) == 0) {
				strncpy(estatus2, etoken + 8, 9);  // Copy Status2 value after "Status2:"
				estatus2[9] = '\0';  // Null-terminate the string
			} else if (strncmp(etoken, "Status3:", 8) == 0) {
				strncpy(estatus3, etoken + 8, 9);  // Copy Status3 value after "Status3:"
				estatus3[9] = '\0';  // Null-terminate the string
			} else if (strncmp(etoken, "Status4:", 8) == 0) {
				strncpy(estatus4, etoken + 8, 9);  // Copy Status4 value after "Status4:"
				estatus4[9] = '\0';  // Null-terminate the string
			}
			// Get the next token
			etoken = strtok(NULL, ",");
		}


		//			sprintf((char *)edata,"etime=%s,edate:%s,ech1:%s,ech2:%s,ech3:%s,ech4:%s,emds:%s,eStatus1:%s,eStatus2:%s,eStatus3:%s,eStatus4:%s",etime,edate,ech1,ech2,ech3,ech4,emds,estatus1,estatus2,estatus3,estatus4);
		DataToCloud(etime,edate,ech1,ech2,ech3,ech4,emds,estatus1,estatus2,estatus3,estatus4);

		// Erase the two pages (page and page + 1)
				EEPROM_PageErase(page);       // Erase page 'page'
				EEPROM_PageErase(page + 1);   // Erase page 'page + 1'

				page += PAGES_PER_ERASE;
		//			HAL_UART_Transmit_IT(&huart4, edata, sizeof(edata));
		//			HAL_Delay(1000);
	}

	page = 0;	// Increment page index for next iteration


}

