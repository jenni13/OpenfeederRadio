
#include "./driver.h"

void read_sr(uint16_t* reg) {
    
   CS_SetLow();
   uint16_t readsr=COM_READ_SR;
   *reg=SPI1_Exchange16bit(readsr);
   CS_SetHigh();
}

void init_driver() {
    nRES_SetHigh();
}
