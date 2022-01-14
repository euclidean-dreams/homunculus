#include "Potentiometer.h"

namespace homunculus {

Potentiometer::Potentiometer(adc1_channel_t channel) {
    usingAdc1 = true;
    adc1Channel = channel;
    adc2Channel = ADC2_CHANNEL_MAX;
    adc1_config_channel_atten(channel, ADC_ATTENUATION);
}

Potentiometer::Potentiometer(adc2_channel_t channel) {
    usingAdc1 = false;
    adc1Channel = ADC1_CHANNEL_MAX;
    adc2Channel = channel;
    adc2_config_channel_atten(channel, ADC_ATTENUATION);
}

char Potentiometer::readValue() {
    int rawValue = 0;
    if (usingAdc1) {
        rawValue = adc1_get_raw(adc1Channel);
    } else {
        adc2_get_raw(adc2Channel, ADC_WIDTH_BIT_12, &rawValue);
    }
    float valueAsRatio = static_cast<float>(rawValue) / ADC_MAX_VALUE;
    float byteSizeResult = 255 * valueAsRatio;
    return static_cast<char>(byteSizeResult);
}

}
