#ifndef OBJETO_H
#define OBJETO_H

#include "Raio.h"
#include "Matriz.h"

struct PontoIntersec {
    Ponto p;
    Vetor normal;
    float t;
};

class Objeto {
    public:
        virtual bool intersectar(const Raio& r, PontoIntersec& rec) const = 0;

        virtual void atualizar_pontos(const Matriz &CpM) = 0;
};

#endif