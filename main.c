
/**
  Section: Included Files
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <xc.h>

#include "driver/driver.h"
#include "debug/debug.h"

#include "Test/test.h"

int main(void) {
    // initialize the device
    SYSTEM_Initialize();
    init_driver();
    __delay32(50000);
    
    test_state_register();
    
    __delay32(100000000);

    while (1) {

    }

    return 1;
}
