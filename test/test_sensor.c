#include <assert.h>
#include <stdio.h>
#include "firmware.h"

int main() {
    for (int i = 0; i < 100; i++) {
        int t = read_temperature();
        int v = read_voltage();

        assert(t >= 20 && t <= 34);
        assert(v >= 3300 && v <= 3499);
    }
    printf("Sensor tests passed\n");
    return 0;
}

