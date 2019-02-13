/* 
 * File:   driver.h
 * Author: alex
 *
 * Created on February 12, 2019, 4:02 PM
 */

#ifndef DRIVER_H
#define	DRIVER_H

#include "../mcc_generated_files/system.h"
#include "types.h"

// Lecture du SR
#define COM_READ_SR 0x0000;


//structure pour le temps
extern struct tm time_pic;

void read_sr(uint16_t* reg);

void init_driver();

 
#endif	/* DRIVER_H */

