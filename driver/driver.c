
#include "./driver.h"

void read_sr() {
/*
    CS_SetLow();
    uint16_t readsr = COM_READ_SR;
    *reg = SPI1_Exchange16bit(readsr);
    CS_SetHigh();
 */
    
   
     CS_SetLow();
    uint8_t read;
    read = SPI1_Exchange8bit(0x00);
    //__delay32(15);
    read = SPI1_Exchange8bit(0x00);
    CS_SetHigh();
    
  
     
}

void init_driver() {
    
    nRES_SetHigh();
}

void ecrire(uint16_t* octet) {
    
    uint16_t recep;
    SPI1_Exchange(octet, &recep);
}
