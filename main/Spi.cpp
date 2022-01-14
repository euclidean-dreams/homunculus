#include "Spi.h"

namespace homunculus {

DMA_ATTR char receiveBuffer[SPI_TRANSACTION_SIZE] = {0};
DMA_ATTR char transmitBuffer[SPI_TRANSACTION_SIZE] = {0};

spi_bus_config_t busConfiguration = {
        .mosi_io_num=SPI_MOSI_PIN,
        .miso_io_num=SPI_MISO_PIN,
        .sclk_io_num=SPI_SCLK_PIN,
        .quadwp_io_num=-1,
        .quadhd_io_num=-1,
        .data4_io_num=-1,
        .data5_io_num=-1,
        .data6_io_num=-1,
        .data7_io_num=-1,
        .max_transfer_sz=SPI_TRANSACTION_SIZE,
        .flags=0,
        .intr_flags=0
};

spi_slave_interface_config_t slaveConfiguration = {
        .spics_io_num=SPI_CS_PIN,
        .queue_size=1,
        .mode=0,
};

spi_slave_transaction_t transaction = {
        .length = 8 * SPI_TRANSACTION_SIZE,
        .tx_buffer = transmitBuffer,
        .rx_buffer = receiveBuffer,
};

void initializeSpi() {
    spi_slave_initialize(HSPI_HOST, &busConfiguration, &slaveConfiguration, SPI_DMA_CH_AUTO);
}

void blockingTransmit() {
    spi_slave_transmit(HSPI_HOST, &transaction, portMAX_DELAY);
}

char *getTransmitBuffer() {
    return transmitBuffer;
}

}
