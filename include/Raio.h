#ifndef RAIO_H
#define RAIO_H

#include "Vetor.h"

class Raio {
    public:
        Raio() {}
        
        Raio(const Ponto& o, const Vetor& d, int aux) : _origem(o), _direcao(d) {}

        Raio(const Ponto& o, const Ponto& p) : _origem(o) {
            _direcao = vetor_unitario(p-_origem);
        }

        Ponto origem() const  { return _origem; }
        Vetor direcao() const { return _direcao; }

        Ponto para(double t) const {
            return _origem + t*_direcao;
        }

    public:
        Ponto _origem;
        Vetor _direcao;
};

#endif