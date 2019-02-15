#include "./tx.h"

void configure_tx() {
    //pour tx : 12pF 
    ecrire_reg(0x80A7);
}

void open_tx() {
    //registre d'activation d'ecriture
    ecrire_reg(0x8239);
    rdy();
}

void close_tx() {
    //registre d'activation d'ecriture
    ecrire_reg(0x8209);
}

void send(uint8_t* buffer, int size) {
    open_tx();
    send_data(buffer, size);
    close_tx();
}

void send_data(uint8_t* bytes, int size) {
    int i;

    //preamble
    send_byte(0xAA);
    send_byte(0xAA);
    send_byte(0xAA);

    //synchro pattern
    send_byte(0x2D);
    send_byte(0xD4);

    for (i = 0; i < size; i++) {
        send_byte(bytes[i]);
    }

    //dummy bytes
    send_byte(0x00);
    send_byte(0x00);
}

void send_byte(uint8_t byte) {
    registre reg;
    reg.octets.g = 0xB8;
    reg.octets.d = byte;
    ecrire_reg(reg.reg);
    rdy();
}



