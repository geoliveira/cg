#ifndef OBJETO_H
#define OBJETO_H

#include "Raio.h"

struct PontoIntersec {
    Ponto p;
    Vetor normal;
    float t;
};

class Objeto {
    public:
        virtual bool intersectar(const Raio& r, PontoIntersec& rec) const = 0;
};

#endif