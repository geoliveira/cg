#ifndef CONE_H
#define CONE_H

#include "Objeto.h"
#include "Vetor.h"
#include "Matriz.h"

class Cone : public Objeto {
    public:
        /*dc = (V-C) / ||V-C||
          h  = ||V-C||
        */
        Cone() {}
        Cone(Ponto cen, float r, Vetor dir, int alt) : _centro(cen), _raio(r), _direcao(vetor_unitario(dir)), _altura(alt), _cor(1, 1, 1) {
            _vertice = _centro + _altura*_direcao;
        };

        Cone(Ponto cen, float r, Vetor dir, int alt, Cor cor) : _centro(cen), _raio(r), _direcao(vetor_unitario(dir)), _altura(alt), _cor(cor) {
            _vertice = _centro + _altura*_direcao;
        };

        virtual bool intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const override;

        virtual void atualizar_pontos(const Matriz &MT) override;   

    public:
        Ponto _centro;
        float _raio;
        Vetor _direcao;
        int   _altura;
        Cor   _cor;
        Ponto _vertice;
};

#endif