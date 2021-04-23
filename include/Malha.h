#ifndef MALHA_H
#define MALHA_H

#include "Base.h"
#include "Matriz.h"

struct Face {
    Ponto _v1, _v2, _v3, _v4;

    void definir(Ponto v1, Ponto v2, Ponto v3, Ponto v4) {
        _v1 = v1;
        _v2 = v2;
        _v3 = v3;
        _v4 = v4;
    }
};

class Malha {
    public:
        Malha(Ponto v0, Ponto v1, Ponto v2, Ponto v3,
              Ponto v4, Ponto v5, Ponto v6, Ponto v7) {
            _v[0] = v0;
            _v[1] = v1;
            _v[2] = v2;
            _v[3] = v3;
            _v[4] = v4;
            _v[5] = v5;
            _v[6] = v6;
            _v[7] = v7;

            Xf.definir(v6, v2, v1, v5);
            Xb.definir(v4, v0, v3, v7);

            Yf.definir(v3, v0, v1, v2);
            Yb.definir(v6, v5, v4, v7);
            
            Zf.definir(v5, v1, v0, v4); 
            Zb.definir(v3, v7, v2, v6);

        }

    private:
        Ponto _v[8];
        Face Xf, Yf, Zf, Xb, Yb, Zb;
};
#endif