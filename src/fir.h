//
// Created by tt on 10/3/20.
//
#include <systemc.h>
#include <vector>
using namespace std;

#ifndef MPI_SC_FIR_H
#define MPI_SC_FIR_H


class fir : public sc_module {
    sc_in<bool> clk;
    sc_in<bool> reset;
    sc_in<sc_int<16>> in;
    sc_out<sc_int<16>> out;
    const sc_uint<8> coef[5] = {
            1,
            2,
            3,
            4,
            5
    };

    void fir_main();

    SC_CTOR(fir) {
        SC_CTHREAD(fir_main, clk.pos());
        reset_signal_is(reset, true);
    }
};


#endif //MPI_SC_FIR_H
