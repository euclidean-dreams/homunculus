#ifndef HOMUNCULUS_SPI_H
#define HOMUNCULUS_SPI_H

#include <esp_log.h>
#include <driver/spi_slave.h>
#include "Constants.h"
#include "HomunculusConfig.h"

namespace homunculus {

void initializeSpi();

void blockingTransmit();

char *getTransmitBuffer();

}

#endif //HOMUNCULUS_SPI_H
