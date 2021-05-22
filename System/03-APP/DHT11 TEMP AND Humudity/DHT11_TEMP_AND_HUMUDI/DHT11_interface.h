/*
 * DHT11_interface.h
 *
 *  Created on: May 2, 2021
 *      Author: Khaled
 */

#ifndef DHT11_INTERFACE_H_
#define DHT11_INTERFACE_H_

#define 		PORTD		3
#define 		PIN6		6



void DHT11_VoidInit(void);
void DHT11_VoidResponse(void);
u8 DHT11_U8Receive(void);

#endif /* DHT11_INTERFACE_H_ */
