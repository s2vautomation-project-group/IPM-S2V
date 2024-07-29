

#define DS3107_ADDRESS 0xD0
#include <main.h>


void app(void);
uint8_t decToBcd(int val);
int bcdToDec(uint8_t val);

void Set_Time (uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year);
void Get_Time (void);
void Get_Time (void);
