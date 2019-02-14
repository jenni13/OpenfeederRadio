/* 
 * File:   driver.h
 * Author: alex
 *
 * Created on February 12, 2019, 4:02 PM
 */

#ifndef DRIVER_H
#define	DRIVER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <xc.h>

#include "../mcc_generated_files/system.h"
#include "types.h"
#include <time.h>




// Lecture du SR
#define COM_READ_SR 0x0000

#define PITCH_TRANS 1000

#define SLEEP_AFTER_INIT 850000

#define BUFF_SIZE 7

//structure pour le temps
extern struct tm time_pic;

void init_driver();

uint16_t ecrire_reg(uint16_t commande);

void init_driver_tx();

void init_driver_rx();

void open_tx();

void open_rx();

void rdy();

void send_data(uint8_t* byte, int size);

void read_data(uint8_t* rec, int size);

void close_tx();

void close_rx();

void get_time(uint8_t* s, uint8_t* m, uint8_t* h, uint8_t* j, uint8_t* ms, uint16_t* a, uint8_t* wd);

void set_time(uint8_t s, uint8_t m, uint8_t h, uint8_t j, uint8_t ms, uint16_t a, uint8_t wd);

void datetime_buf(uint8_t* buff);


#endif	/* DRIVER_H */

