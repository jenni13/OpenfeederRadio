/* 
 * File:   types.h
 * Author: alex
 *
 * Created on February 12, 2019, 4:01 PM
 */

#ifndef TYPES_H
#define	TYPES_H

struct outputs_vals{
    uint8_t val_cs;
    uint8_t val_sck;
    uint8_t val_mosi;
    uint8_t val_nres;

} ;

struct inputs_vals{
    uint8_t val_nirq;
    uint8_t val_miso;

} ;

struct state_register{
    uint8_t reg;
} ;


#endif	/* TYPES_H */

