#ifndef HOMUNCULUS_POTENTIOMETER_H
#define HOMUNCULUS_POTENTIOMETER_H

#include <driver/adc_common.h>
#include "Constants.h"

namespace homunculus {

class Potentiometer {
private:
    bool usingAdc1;
    adc1_channel_t adc1Channel;
    adc2_channel_t adc2Channel;

public:
    explicit Potentiometer(adc1_channel_t channel);

    explicit Potentiometer(adc2_channel_t channel);

    char readValue();
};

}

#endif //HOMUNCULUS_POTENTIOMETER_H
