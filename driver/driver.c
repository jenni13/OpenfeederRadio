
#include "./driver.h"

uint16_t ecrire_reg(uint16_t commande) {

    registre reg_in, res;
    reg_in.reg = commande;
    CS_SetLow();
    while (CS_GetValue()) {

    }
    res.octets.g = SPI1_Exchange8bit(reg_in.octets.g);
    //__delay32(15);
    res.octets.d = SPI1_Exchange8bit(reg_in.octets.d);
    CS_SetHigh();
    while (!CS_GetValue()) {

    }
    // __delay32(PITCH_TRANS);
    return res.reg;
}

void init_driver_tx() {

    ecrire_reg(0x0000);


    //pour tx : 12pF 
    ecrire_reg(0x80A7);
    //pour tx

    ecrire_reg(0xA640);
    ecrire_reg(0x9098);
    ecrire_reg(0xC2AC);
    ecrire_reg(0xCA81);

    ecrire_reg(0xE000);

    ecrire_reg(0xC800);

    __delay32(SLEEP_AFTER_INIT);
}

void init_driver_rx() {
    ecrire_reg(0x0000);

    //pour rx
    ecrire_reg(0x8067);
    //pour rx


    ecrire_reg(0xA640);
    ecrire_reg(0x9098);
    ecrire_reg(0xC2AC);
    ecrire_reg(0xCA81);

    ecrire_reg(0xE000);

    ecrire_reg(0xC800);

    __delay32(SLEEP_AFTER_INIT);
}

void rdy() {
    while (nIRQ_GetValue()) {

    }
}

void open_tx() {
    //registre d'activation d'ecriture
    ecrire_reg(0x8239);
    rdy();
}

void open_rx() {
    //registre d'activation d'ecriture
    ecrire_reg(0x82C9);

    ecrire_reg(0xCA83);
}

void send_data(uint8_t* bytes, int size) {
    int i;
    send_byte(0xAA);
    send_byte(0xAA);
    send_byte(0xAA);

    send_byte(0x2D);
    send_byte(0xD4);

    for (i = 0; i < size; i++) {
        send_byte(bytes[i]);
    }

    send_byte(0x00);
    send_byte(0x00);
    // ecrire_reg(byte);

    //ecrire_reg(0x00);
    //ecrire_reg(0x00);
    __delay32(100000000000);
}

void read_data(uint8_t* buffer, int size) {
    // ecrire_reg(0x0000);
    //  uint16_t rec;
    registre reg_in;
    uint8_t oct_rec;
    int i;
    for (i = 0; i < size; i++) {
        rdy();
        reg_in.reg = ecrire_reg(0xB000);
        buffer[i] = reg_in.octets.d;
        // NE PAS DEBUGGER ICI !
        //  printf("c : val %u %u\n",reg_in.octets.g,reg_in.octets.d);

    }

    // uint16_t rec=ecrire_reg(0xB000);

    /*reg_in.reg=rec;
    printf("Octer recu : %u\n",rec);
    printf("Octer recu g : %u\n",reg_in.octets.g);
    printf("Octer recu d : %u\n",reg_in.octets.d);
     */
}

void send_byte(uint8_t byte) {
    registre reg;
    reg.octets.g = 0xB8;
    reg.octets.d = byte;
    ecrire_reg(reg.reg);
    rdy();
}

void close_tx() {
    //registre d'activation d'ecriture
    ecrire_reg(0x8209);
}

void close_rx() {
    //registre d'activation d'ecriture
    ecrire_reg(0x8209);

}

void get_time(uint8_t* s, uint8_t* m, uint8_t* h, uint8_t* j, uint8_t* ms, uint16_t* a, uint8_t* wd) {

    struct tm time_pic;
    RTCC_TimeGet(&time_pic);
    *s = time_pic.tm_sec;
    *m = time_pic.tm_min;
    *h = time_pic.tm_hour;
    *j = time_pic.tm_mday;
    *ms = time_pic.tm_mon;
    *a = time_pic.tm_year;
    *wd = time_pic.tm_wday;
}

void datetime_buf(uint8_t* buff) {

    uint8_t s, m, h, j, ms, wd;
    uint16_t a;

    registre ann;
    ann.reg = a;
    get_time(&s, &m, &h, &j, &ms, &a, &wd);
    buff[0] = j;
    buff[1] = ms;
    buff[2] = ann.octets.g;
    buff[3] = ann.octets.d;
    buff[4] = h;
    buff[5] = m;
    buff[6] = s;
    /*
    buff[2]=m;
    memset(buff, (uint8_t)j, 1);
    memset(buff+1, (uint8_t)ms, 1);
    memset(buff+2, (uint16_t)a, 2);
    memset(buff+4, (uint8_t)h, 1);
    memset(buff+5, (uint8_t)m, 1);
    memset(buff+6, (uint8_t)s, 1);
     */
}

void set_time(uint8_t s, uint8_t m, uint8_t h, uint8_t j, uint8_t ms, uint16_t a, uint8_t wd) {

    struct tm time_set;
    time_set.tm_sec = (uint8_t) s;
    time_set.tm_min = (uint8_t) m;
    time_set.tm_hour = (uint8_t) h;
    time_set.tm_mday = (uint8_t) j;
    time_set.tm_mon = (uint8_t) ms;
    time_set.tm_year = (uint16_t) a;
    time_set.tm_wday = (uint8_t) wd;
    RTCC_TimeSet(&time_set);

}