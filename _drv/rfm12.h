/*** FILEHEADER ****************************************************************
 *
 *    FILENAME:    rfm12.h
 *    DATE:        31.10.2010
 *    AUTHOR:      (c) Christian Stadler
 *
 *    DESCRIPTION: Driver for RFM12 wireless tranceiver module.
 *
 ******************************************************************************/

/*** HISTORY OF CHANGE *********************************************************
 *
 *    $Log: /pic/_drv/rfm12.h $
 * 
 * 2     1.11.10 11:50 Stadler
 * - adaptions for Microchip C18 compiler
 * 
 * 1     31.10.10 14:45 Stadler
 * - RFM12 tranceiver module driver
 * 
 ******************************************************************************/

#ifndef _RFM12_H
#define _RFM12_H

/* common data type definitions */
#include "../_inc/types.h"

/* RFM12 configuration, to be created by the user */
#include "../rfm12conf.h"

/*
#ifndef RFM12_PinInit
#error RFM12_PinInit not defined in rfm12conf.h!
#endif

#ifndef RFM12_ClrSCK
#error RFM12_ClrSCK not defined in rfm12conf.h!
#endif

#ifndef RFM12_SetSCK
#error RFM12_SetSCK not defined in rfm12conf.h!
#endif

#ifndef RFM12_ClrSDI
#error RFM12_ClrSDI not defined in rfm12conf.h!
#endif

#ifndef RFM12_SetSDI
#error RFM12_SetSDI not defined in rfm12conf.h!
#endif

#ifndef RFM12_ClrNSEL
#error RFM12_ClrNSEL not defined in rfm12conf.h!
#endif

#ifndef RFM12_SetNSEL
#error RFM12_SetNSEL not defined in rfm12conf.h!
#endif

#ifndef RFM12_GetSDO
#error RFM12_GetSDO not defined in rfm12conf.h!
#endif
*/

/* macro for calculating frequency value out of frequency in MHz */
#define RFM12FREQ(freq)     ((freq-430.0)/0.0025)




uint16 RFM12_Write(uint16 data);
void RFM12_Init(void);
void RFM12_SetBandwidth(uint8 bandwidth, uint8 gain, uint8 drssi);
void RFM12_SetFreq(uint16 freq);
void RFM12_SetBaud(uint16 baud);
void RFM12_SetPower(uint8 power, uint8 mod);
void RFM12_Ready(void);
void RFM12_TxData(uint8 *data, uint8 length);
void RFM12_RxData(uint8 *data, uint8 length);

#endif /* #ifndef _RFM12_H */