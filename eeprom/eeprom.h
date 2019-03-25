/*
 * eeprom.h
 *
 *  Created on: May 19, 2018
 *      Author: AbuElkasem
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#include"PLATFORM_TYPES.h"

void eeprom_byte_write(uint16 address,uint8 data);
void eeprom_byte_read(uint16 address,uint8 *data);

#endif /* EEPROM_H_ */
