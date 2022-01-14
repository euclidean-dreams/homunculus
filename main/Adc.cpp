#include "Adc.h"

namespace homunculus {

void initializeAdc() {
    adc_power_acquire();
    adc1_config_width(ADC_WIDTH);
}

}
