/*

 */

#include "./test.h"

/* v�rifier que le state register se remet � 0x4000 apr�s un reset
 * pendant le fonctionnement
 */
void test_state_register() {

    uint16_t state_reg;
   read_sr(&state_reg);
    __delay32(100000);
    
   read_sr(&state_reg);
    __delay32(100000);
    nRES_SetLow();
    __delay32(100000);
    nRES_SetHigh();
    __delay32(100000);
    
   read_sr(&state_reg);
}

//simulation d'une horloge
void test_clock_seal() {

    nRES_SetHigh();
    __delay32(1000);
    nRES_SetLow();
    __delay32(1000);

}

void other() {
    //getPinsValues();
    //nRES_SetHigh();
    //printf("Default\n\n");
    //  debugValues();
}