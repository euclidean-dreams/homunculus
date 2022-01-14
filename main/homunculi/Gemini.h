#ifndef HOMUNCULUS_GEMINI_H
#define HOMUNCULUS_GEMINI_H

#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <vector>
#include "Spi.h"
#include "bits/Button.h"

namespace homunculus {

class Gemini {
public:
    static void live();
};

}

#endif //HOMUNCULUS_GEMINI_H
