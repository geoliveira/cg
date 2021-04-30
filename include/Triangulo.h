#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Objeto.h"
#include "Vetor.h"
#include "Matriz.h"

class Triangulo : public Objeto {
    public:
        Triangulo() {};

        Triangulo(Ponto vert1,Ponto vert2, Ponto vert3) : _vertice1(vert1), _vertice2(vert2), _vertice3(vert3), _cor(1, 1, 1) {
            atualizar_vetores();
            atualizar_normal();
        };

        Triangulo(Ponto vert1,Ponto vert2, Ponto vert3, Cor cor) : _vertice1(vert1), _vertice2(vert2), _vertice3(vert3), _cor(cor) {
            atualizar_vetores();
            atualizar_normal();
        };

        virtual bool intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const override;

        virtual void atualizar_pontos(const Matriz &MT) override;

        void rotacionar(const Matriz &MT);

        void atualizar_normal(void) {
            
        };

        void atualizar_vetores(void) {
            
        };

    public:
        Ponto _vertice1, _vertice2, _vertice3;
        Vetor V_1_2, V_1_3, _normal; 
        Cor _cor;
};

#endif