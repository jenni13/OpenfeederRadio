
#include "./trx.h"

void init_trx() {
    nRES_SetHigh();

    ecrire_reg(0x0000);

    ecrire_reg(0xA640);
    ecrire_reg(0x9098);
    ecrire_reg(0xC2AC);
    ecrire_reg(0xCA81);

    ecrire_reg(0xE000);

    ecrire_reg(0xC800);
    
    __delay32(SLEEP_AFTER_INIT);
}

uint16_t ecrire_reg(uint16_t commande) {
    registre reg_in, res;
    reg_in.reg = commande;
    CS_SetLow();
    while (CS_GetValue()) {

    }
    res.octets.g = SPI1_Exchange8bit(reg_in.octets.g);
    res.octets.d = SPI1_Exchange8bit(reg_in.octets.d);
    CS_SetHigh();
    while (!CS_GetValue()) {

    }
    // __delay32(PITCH_TRANS);
    return res.reg;
}



void rdy() {
    while (nIRQ_GetValue()) {

    }
}

