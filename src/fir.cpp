//
// Created by tt on 10/3/20.
//

#include "fir.h"

void fir::fir_main() {
    vector<sc_int<16>> taps(5);
    out.write(0);
    sc_int<16> sum;
    wait();

    while (true) {
        for(int i = taps.size() - 1; i > 0; i--) {
            taps[i] = taps[i - 1];
        }
        taps[0] = in.read();
        for(int i = taps.size() - 1; i > 0; i--) {
            sum += taps[i] * coef[i];
        }
        out.write(sum);
        wait();
    }
}
