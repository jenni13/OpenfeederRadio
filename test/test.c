/*

 */

#include "./test.h"

/* vérifier que le state register se remet à 0x4000 après un reset
 * pendant le fonctionnement
 */
void test_state_register() {

    uint16_t state_reg = ecrire_reg(0x0000);
    __delay32(PITCH_TRANS);

    state_reg = ecrire_reg(0x0000);
    __delay32(PITCH_TRANS);
    nRES_SetLow();
    __delay32(PITCH_TRANS);
    nRES_SetHigh();
    __delay32(PITCH_TRANS);

    state_reg = ecrire_reg(0x0000);
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