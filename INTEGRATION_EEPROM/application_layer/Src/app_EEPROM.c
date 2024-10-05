/*
 * app_EEPROM.c
 *
 *  Created on: Sep 24, 2024
 *      Author: User
 */


#include "main.h"
#include <string.h>
#include "app_EEPROM.h"
#include "comm_EEPROM.h"
#include "data.h"

static uint16_t eeprom_address = 0x0000;
struct eeprom_data ed;
struct eeprom_data read_back_data;


void convert_data_to_eeprom_data(struct data *d, struct eeprom_data *ed)
{
    ed->scan_time = d->scan_time;
    ed->seconds = d->seconds;
    ed->minutes = d->minutes;
    ed->hour = d->hour;
    ed->dayofmonth = d->dayofmonth;
    ed->month = d->month;
    ed->year = d->year;
    ed->adc1_value = d->adc1_value;
    ed->adc2_value = d->adc2_value;
    ed->adc3_value = d->adc3_value;
    ed->adc4_value = d->adc4_value;
    strncpy(ed->Status1, d->Status1, sizeof(ed->Status1));
    strncpy(ed->Status2, d->Status2, sizeof(ed->Status2));
    strncpy(ed->Status3, d->Status3, sizeof(ed->Status3));
    strncpy(ed->Status4, d->Status4, sizeof(ed->Status4));
}


// Store data in EEPROM
void store_data_in_eeprom(struct eeprom_data *ed)
{
    uint8_t eeprom_buffer[sizeof(struct eeprom_data)];
    memcpy(eeprom_buffer, ed, sizeof(struct eeprom_data));

    // Write data to EEPROM
    if (eeprom_write(eeprom_address, eeprom_buffer, sizeof(eeprom_buffer)) == HAL_OK)
    {
        eeprom_address += sizeof(eeprom_buffer);

        // Wrap around if EEPROM address exceeds max size
        if (eeprom_address + sizeof(eeprom_buffer) > EEPROM_MAX_ADDRESS)
        {
            eeprom_address = 0x0000;
        }
    }
        else
        {
        	 Error_Handler();
        }
    }


// Read data from EEPROM
void read_data_from_eeprom(struct eeprom_data *ed, uint16_t address)
{
    uint8_t eeprom_buffer[sizeof(struct eeprom_data)];
   // eeprom_read(address, eeprom_buffer, sizeof(eeprom_buffer)); // Read from EEPROM
   // memcpy(ed, eeprom_buffer, sizeof(struct eeprom_data));      // Copy to struct
    if (eeprom_read(address, eeprom_buffer, sizeof(eeprom_buffer)) == HAL_OK)
    {
        memcpy(ed, eeprom_buffer, sizeof(struct eeprom_data));  // Copy to struct
    }
    else
    {
            Error_Handler();  // Handle read failure
    }
}


void CheckAndStoreData(struct data *d)
{
    static uint8_t prev_minutes = 0;
//   if ((d->minutes % d->scan_time == 0 && d->seconds == 0) && d->minutes != prev_minutes)
//    {
//    if (d->scan_time > 0 && (d->minutes % d->scan_time == 0) && d->seconds < 2 && d->minutes != prev_minutes)
//    {
        struct eeprom_data ed;
        convert_data_to_eeprom_data(d, &ed);
        store_data_in_eeprom(&ed);
        prev_minutes = d->minutes;
  //  }
}

void EEPROM(void)
{
//    struct data d;
//    struct eeprom_data ed;


        ed.scan_time = d.scan_time; // Set scan time

        // Get current RTC time
        //get_time(&d);

        // Collect ADC data
        //ADC_handler(&d);

        // Check GPIO pin status
        //read_pinstatus(&d);

        // Check and store data based on scan time
        CheckAndStoreData(&d);

        // Read back the last stored data
       // struct eeprom_data read_back_data;

        // Calculate the last written address for reading
//        uint16_t read_address = (eeprom_address >= sizeof(struct eeprom_data))
//                                    ? eeprom_address - sizeof(struct eeprom_data)
//                                    : EEPROM_MAX_ADDRESS - sizeof(struct eeprom_data);

        // Read the last data from EEPROM
       // read_data_from_eeprom(&ed, read_address);

        // Optional: Additional logic (e.g., GSM communication, etc.)

        // Delay to avoid rapid polling
        //HAL_Delay(100);
}


