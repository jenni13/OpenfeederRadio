
/**
  Section: Included Files
 */



#include "driver/driver.h"
#include "debug/debug.h"

#include "test/test.h"

//0 : tx
//1 : rx
#define MODE 1
//0: tx or rx
//1 : debug
#define DEBUG 0

uint8_t tx_buff[] = "abcbabbbba";

uint8_t rx_buff[] = "xxxxxxxxxx";

uint8_t rxbuf[7];

void run_tx() {
    uint8_t data1 = 0x94;
    uint8_t data2 = 0xC9;
    init_driver_tx();

    open_tx();

    datetime_buf(tx_buff);
    send_data(tx_buff, 7);
    close_tx();
}

void run_rx() {

    init_driver_rx();
    while (1) {
        open_rx();
        printf("Attente ...\n");
        read_data(rx_buff, 7);
        close_rx();
        __delay32(100000);
        //rdy();
        debug_buffer(rx_buff, 7);
        //printf("Bbuffer : %s\n", rx_buff);
    }
    //printf("J'attend un evenement !\n");
    // Attendre le front descendant
    /* while (!nIRQ_GetValue()) {

     }*/
    //  printf("C'est gagné !\n");
    // __delay32(50000000);
    // C'est gagné !
}

void run_debug() {

    __delay32(50000);

    test_state_register();

    __delay32(100000000);

    while (1) {

    }
}

int main(void) {

    // initialize the device
    SYSTEM_Initialize();
    nRES_SetHigh();

    if (DEBUG) run_debug();
    else if (!MODE) run_tx();
    else run_rx();

    return 1;
}
