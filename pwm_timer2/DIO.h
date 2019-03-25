/*
 * DIO.h
 *
 *  Created on: Apr 20, 2018
 *      Author: AbuElkasem
 */

#ifndef DIO_H_
#define DIO_H_
#define SET_BIT(REG,PIN)      (REG|=(1<<PIN))
#define CLEAR_BIT(REG,PIN)      (REG&=~(1<<PIN))
#define TOGGLE_BIT(REG,PIN)      (REG^=(1<<PIN))
#define READ_BIT_TRUE(REG,PIN)      (REG&(1<<PIN))
#define READ_BIT_FALSE(REG,PIN)      (!(REG&(1<<PIN)))



#endif /* DIO_H_ */
