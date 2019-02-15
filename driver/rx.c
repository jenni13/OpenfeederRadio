#include "./trx.h"

void open_rx() {
    //registre d'activation d'ecriture
    ecrire_reg(0x82C9);

    ecrire_reg(0xCA83);
}

void configure_rx() {
    //pour rx
    ecrire_reg(0x8067);
}

void close_rx() {
    //registre d'activation d'ecriture
    ecrire_reg(0x8209);
}

void receive(uint8_t* buffer, int size) {
    printf("Attente ...\n");
    open_rx();
    read_data(buffer, size);
    close_rx();
}

void wait_clock(int* compteur) {
    do {
        debug_datetime(compteur);
    } while (nIRQ_GetValue());
}

void read_data(uint8_t* buffer, int size) {
    registre reg_in;
    int i;

    for (i = 0; i < size; i++) {
        rdy();
        reg_in.reg = ecrire_reg(0xB000);
        buffer[i] = reg_in.octets.d;
    }
}

void receive_datetime(uint8_t* buffer) {
    
    struct heure_format heure_master;
    printf("Attente ...\n");
    open_rx();
    registre reg_in;
    int i;
    int compteur = 0;
    //buffer
    for (i = 0; i < 7; i++) {
        wait_clock(&compteur);
        reg_in.reg = ecrire_reg(0xB000);
        buffer[i] = reg_in.octets.d;
    }
    close_rx();
    deserial_buffer(buffer, &heure_master);
    set_time(heure_master);
    while (1) {
        debug_datetime(&compteur);
    }

}


