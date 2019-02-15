/* 
 * File:   tx.h
 * Author: alex
 *
 * Created on 15 février 2019, 23:05
 */

#ifndef TX_H
#define	TX_H

#include "./trx.h"


void configure_tx();

void open_tx();

void close_tx();

void send(uint8_t* buffer,int size);

void send_data(uint8_t* bytes, int size);

void send_byte(uint8_t byte);


#endif	/* TX_H */

