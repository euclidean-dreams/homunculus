#include "Geminus.h"

namespace homunculus {

void Geminus::live() {
    gpio_install_isr_service(0);

    std::vector<gpio_num_t> buttonPins{
            // extra
            GPIO_NUM_25,

            // first rack
            GPIO_NUM_26,
            GPIO_NUM_27,
            GPIO_NUM_14,
            GPIO_NUM_12,
            GPIO_NUM_13,

            // second rack
            GPIO_NUM_17,
            GPIO_NUM_16,
            GPIO_NUM_4,
            GPIO_NUM_2,
            GPIO_NUM_15
    };
    std::vector<Button> buttons{};

    for (auto &pin: buttonPins) {
        buttons.push_back(Button{pin});
    }
    for (auto &button: buttons) {
        button.registerCallback();
    }

    while (true) {
        auto transmitBufferPointer = getTransmitBuffer();
        for (auto &button: buttons) {
            char value = 0;
            if (button.getPressed()) {
                button.unpress();
                value = 1;
            }
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
