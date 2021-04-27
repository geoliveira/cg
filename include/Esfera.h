#ifndef ESFERA_H
#define ESFERA_H

#include "Objeto.h"
#include "Vetor.h"
#include "Matriz.h"

class Esfera : public Objeto {
    public:
        Esfera() {}
        Esfera(Ponto cen, float r) : _centro(cen), _raio(r), _cor(1, 1, 1) {};
        Esfera(Ponto cen, float r, Cor cor) : _centro(cen), _raio(r), _cor(cor) {};

        virtual bool intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const override;

        virtual void atualizar_pontos(const Matriz &MT) override;

    public:
        Ponto _centro;
        float _raio;
        Cor _cor;
};

#endif