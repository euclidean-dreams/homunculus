#include "Button.h"

namespace homunculus {

void buttonCallback(void *button) {
    static_cast<Button *>(button)->press();
}

Button::Button(gpio_num_t pin)
        : pin{pin},
          pressed{false} {
    gpio_config_t btn_config;
    btn_config.pin_bit_mask = (1 << pin);
    btn_config.mode = GPIO_MODE_INPUT;
    btn_config.pull_up_en = GPIO_PULLUP_DISABLE;
    btn_config.pull_down_en = GPIO_PULLDOWN_ENABLE;
    btn_config.intr_type = GPIO_INTR_NEGEDGE;
    gpio_config(&btn_config);
}

void Button::registerCallback() {
    // this should be called only after the button has reached its final resting place in memory
    gpio_isr_handler_add(pin, buttonCallback, this);
}

bool Button::getPressed() const {
    return pressed;
}

void Button::press() {
    pressed = true;
}

void Button::unpress() {
    pressed = false;
}

}
