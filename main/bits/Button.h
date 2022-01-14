#ifndef HOMUNCULUS_BUTTON_H
#define HOMUNCULUS_BUTTON_H

#include <hal/gpio_types.h>
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>

namespace homunculus {

void buttonCallback(void *button);

class Button {
private:
    gpio_num_t pin;
    bool pressed;

public:
    explicit Button(gpio_num_t pin);

    void registerCallback();

    bool getPressed() const;

    void press();

    void unpress();
};

}

#endif //HOMUNCULUS_BUTTON_H
