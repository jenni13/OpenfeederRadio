
#include "./debug.h"

void getPinsOutput(struct outputs_vals* o_v) {

    o_v->val_cs = CS_GetValue();
    o_v->val_sck = SCK_GetValue();
    o_v->val_mosi = MOSI_GetValue();
    o_v->val_nres = nRES_GetValue();

}

void getPinsInput(struct inputs_vals* o_v) {
    o_v->val_nirq = nIRQ_GetValue();
    o_v->val_miso = MISO_GetValue();

}

void debugOutput(struct outputs_vals* o_v) {

    printf("Valeur de cs : %u\n", o_v->val_cs);
    printf("Valeur de sck : %u\n", o_v->val_sck);
    printf("Valeur de mosi : %u\n", o_v->val_mosi);
    printf("Valeur de nres : %u\n", o_v->val_nres);
}

void debugInput(struct inputs_vals* o_v) {

    printf("Valeur de nriq : %u\n", o_v->val_nirq);
    printf("Valeur de miso : %u\n", o_v->val_miso);

}

void debug_buffer(uint8_t* buffer, int size) {

    int i;
    printf("Buffer : ");

    for (i = 0; i < size; i++) {
        printf("%u ", buffer[i]);

    }
    printf("\n");
}

/*
FFIT*
RGIT**
POR
FFOV*
RGUR**
WKUP
status bits out
EXT
LBD
FFEM
RSSI*
ATS**
DQD
CRL
ATGL
OFFS<6> OFFS<3> OFFS<2> OFFS<1> OFFS<0>
(Latched) (Latched) (Latched) (Latched) (Latched)
FIFO out
FO
FO+1
FO+2
 */

/*
Default
Entree
Valeur de nirq : 0
Valeur de miso : 0
Sorties
Valeur de cs : 1
Valeur de sck : 0
Valeur de mosi : 0
Valeur de nres : 0
 */
