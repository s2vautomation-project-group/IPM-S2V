/*
 * app.h
 *
 *  Created on: Jun 28, 2024
 *      Author: user
 */

#ifndef APPLICATION_INC_APP_H_
#define APPLICATION_INC_APP_H_

int* readpin_status();
void Configurator();
void extract_data();
void pin_config();
void clear_buffer();
int isBufferNullTerminated(char *buffer, int bufferSize);

#endif /* APPLICATION_INC_APP_H_ */
