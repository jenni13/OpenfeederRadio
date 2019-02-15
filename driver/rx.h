/* 
 * File:   rx.h
 * Author: alex
 *
 * Created on 15 février 2019, 23:05
 */

#ifndef RX_H
#define	RX_H

#include "../driver/trx.h"


void open_rx();

void configure_rx();

void close_rx();

void receive(uint8_t* buffer, int size);

void wait_clock(int* compteur);

void read_data(uint8_t* buffer, int size);


#endif	/* RX_H */

