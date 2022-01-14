#ifndef HOMUNCULUS_CALYPSO_H
#define HOMUNCULUS_CALYPSO_H

#include <driver/adc_common.h>
#include <vector>
#include "bits/Potentiometer.h"
#include "Spi.h"
#include "Adc.h"

namespace homunculus {

class Calypso {
public:
    static void live();
};

}

#endif //HOMUNCULUS_CALYPSO_H
