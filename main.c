
/**
  Section: Included Files
 */



#include "driver/driver.h"
#include "debug/debug.h"

#include "test/test.h"

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
