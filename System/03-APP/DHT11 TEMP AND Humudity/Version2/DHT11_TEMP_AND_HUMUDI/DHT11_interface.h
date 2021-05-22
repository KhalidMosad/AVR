/*
 * DHT11_interface.h
 *
 *  Created on: May 2, 2021
 *      Author: Khaled
 */

#ifndef DHT11_INTERFACE_H_
#define DHT11_INTERFACE_H_

void DHT11_VoidInit(u8 Cope_u8Port,u8 Cope_u8Pin );
void DHT11_VoidResponse(u8 Cope_u8Port,u8 Cope_u8Pin );
u8 DHT11_U8Receive(u8 Cope_u8Port,u8 Cope_u8Pin);

#endif /* DHT11_INTERFACE_H_ */
