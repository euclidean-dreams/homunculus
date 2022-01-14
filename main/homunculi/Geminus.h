#ifndef HOMUNCULUS_GEMINUS_H
#define HOMUNCULUS_GEMINUS_H

#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <vector>
#include "Spi.h"
#include "bits/Button.h"

namespace homunculus {

class Geminus {
public:
    static void live();
};

}

#endif //HOMUNCULUS_GEMINUS_H
