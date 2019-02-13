/* 
 * File:   debug.h
 * Author: alex
 *
 * Created on February 12, 2019, 3:48 PM
 */


#include "../driver/driver.h"

#ifndef DEBUG_H
#define	DEBUG_H

void getPinsOutput(struct outputs_vals* o_v);
void getPinsInput(struct inputs_vals* o_v);
void debugOutput(struct outputs_vals* o_v);
void debugInput(struct inputs_vals* o_v);

#endif	/* DEBUG_H */

