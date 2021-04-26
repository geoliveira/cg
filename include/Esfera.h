#ifndef ESFERA_H
#define ESFERA_H

#include "Objeto.h"
#include "Vetor.h"
#include "Matriz.h"

class Esfera : public Objeto {
    public:
        Esfera() {}
        Esfera(Ponto cen, float r) : _centro(cen), _raio(r) {};

        virtual bool intersectar(const Raio& r, PontoIntersec& rec) const override;

        virtual void atualizar_pontos(const Matriz &MT) override;

    public:
        Ponto _centro;
        float _raio;
};

#endif