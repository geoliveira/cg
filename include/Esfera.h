#ifndef ESFERA_H
#define ESFERA_H

#include "Objeto.h"
#include "Vetor.h"

class Esfera : public Objeto {
    public:
        Esfera() {}
        Esfera(Ponto cen, float r) : _centro(cen), _raio(r) {};

        virtual bool intersectar(const Raio& r, PontoIntersec& rec) const override;

    public:
        Ponto _centro;
        float _raio;
};

#endif