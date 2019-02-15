
/**
  Section: Included Files
 */

#include "driver/tx.h"
#include "driver/rx.h"

#include "debug/debug.h"

#include "test/test.h"

//1 : debug
#define DEBUG_CLOCK 1

//0 : tx
//1 : rx
#define MODE 1

#define SIZE_DATE 7

uint8_t tx_date[SIZE_DATE];

uint8_t rx_date[SIZE_DATE];

void run_tx() {
    struct heure_format datetime;

    configure_tx();

    if (!DEBUG_CLOCK) send(tx_date, SIZE_DATE);
    else {
        read_clock_uart(&datetime);
        serial_buffer(tx_date, datetime);
        send(tx_date, SIZE_DATE);
    }
}

void run_rx() {
    configure_rx();

    if (!DEBUG_CLOCK) receive(rx_date, SIZE_DATE);
    else receive_datetime(rx_date);
}

int main(void) {

    // initialize the device
    SYSTEM_Initialize();

    init_trx();
    printf("Init ok\n");
    if (!MODE) run_tx();
    else run_rx();
    
    printf("END\n");
    return 1;
}
