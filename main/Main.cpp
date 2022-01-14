#include "Spi.h"
#include "homunculi/Calypso.h"
#include "homunculi/Gemini.h"
#include "homunculi/Geminus.h"

void entrypoint() {
    using namespace homunculus;
    initializeSpi();
    HOMUNCULUS::live();
}

extern "C" {

void app_main(void) {
    entrypoint();
}

}
