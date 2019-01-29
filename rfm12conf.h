#ifndef _RFM12CONF_H
#define _RFM12CONF_H

/*---------------------------------------------------------------------------*/
/* Configuration for Microchip C18 Compiler                                  */
/*---------------------------------------------------------------------------*/

//#include <p24fxxxx.h>
#include <stdio.h>
#include <stdlib.h>
#include <libpic30.h>
#include <xc.h>
/* set I/O direction for pins used for controlling RFM12 */

//#define FCY 8000000UL
//#define _XTAL_FREQ 8000000UL

#define RFM12_PinInit()     LATC &= 0x1F; TRISC &= 0x1F;

/* I/O pin controll functions */
#define RFM12_ClrSCK()      LATCbits.LATC7 = 0
#define RFM12_SetSCK()      LATCbits.LATC7 = 1
#define RFM12_ClrSDI()      LATCbits.LATC6 = 0
#define RFM12_SetSDI()      LATCbits.LATC6 = 1
#define RFM12_ClrNSEL()     LATCbits.LATC5 = 0
#define RFM12_SetNSEL()     LATCbits.LATC5 = 1
#define RFM12_GetSDO()      PORTCbits.RC4
#define RFM12_GetIRQ()      PORTCbits.RC3




#endif /* #define _RFM12CONF_H */
