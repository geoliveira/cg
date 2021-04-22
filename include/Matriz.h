#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include "Base.h"

class Matriz {
    public:
        Matriz() {}

        void coord_cpm(Vetor l1, Vetor l2, Vetor l3, Ponto l4) {
            
        }

        void coord_mpc(Vetor l1, Vetor l2, Vetor l3, Ponto l4) {
            
        }

    private:
        Ponto _origem;
        Vetor _x;
        Vetor _y;
        Vetor _z;
        float m[4][4];
};

#endif