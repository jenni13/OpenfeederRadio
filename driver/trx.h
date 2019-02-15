/* 
 * File:   driver.h
 * Author: alex
 *
 * Created on February 12, 2019, 4:02 PM
 */

#ifndef TRX_H
#define	TRX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <xc.h>
#include <time.h>

#include "../mcc_generated_files/system.h"
#include "./trx.h"
#include "./types.h"

// Lecture du SR
#define COM_READ_SR 0x0000

#define PITCH_TRANS 1000

#define SLEEP_AFTER_INIT 850000

#define BUFF_SIZE 7

//structure pour le temps
//extern struct tm time_pic;

void init_trx();

uint16_t ecrire_reg(uint16_t commande);

void rdy();


#endif	/* DRIVER_H */

