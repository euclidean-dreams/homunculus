#include "Calypso.h"

namespace homunculus {

void Calypso::live() {
    initializeAdc();

    std::vector<Potentiometer> potentiometers{};
    potentiometers.push_back(Potentiometer{ADC2_CHANNEL_6});
    potentiometers.push_back(Potentiometer{ADC2_CHANNEL_7});
    potentiometers.push_back(Potentiometer{ADC2_CHANNEL_9});
    potentiometers.push_back(Potentiometer{ADC2_CHANNEL_8});
    potentiometers.push_back(Potentiometer{ADC1_CHANNEL_5});
    potentiometers.push_back(Potentiometer{ADC1_CHANNEL_4});
    potentiometers.push_back(Potentiometer{ADC1_CHANNEL_7});
    potentiometers.push_back(Potentiometer{ADC1_CHANNEL_6});
    potentiometers.push_back(Potentiometer{ADC1_CHANNEL_3});
    potentiometers.push_back(Potentiometer{ADC1_CHANNEL_0});

    while (true) {
        auto transmitBufferPointer = getTransmitBuffer();
        for (auto &potentiometer: potentiometers) {
            auto value = potentiometer.readValue();
            *transmitBufferPointer = value;
            for (int iteration = 0; iteration < SPI_REDUNDANCY; iteration++) {
                *(transmitBufferPointer + SPI_BUFFER_SIZE * iteration) = value;
            }
            transmitBufferPointer++;
        }
        blockingTransmit();
    }
}

}
