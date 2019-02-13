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
#define COM_READ_SR 0x0000;


//structure pour le temps
extern struct tm time_pic;

void read_sr();

void init_driver();

 
#endif	/* DRIVER_H */

