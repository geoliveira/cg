#ifndef LUZ_H
#define LUZ_H

#include "Base.h"
#include "Objeto.h"

/*
    n: normal a superficie
    l: ponto iluminado a fonte
    r: reflexao de l
    v: ponto iluminado ao observador

    Prop. Intensidade da fonte
        - I = Ia + Id + Is
    Prop. Refletividade do material
        - R = Ra + Rd + Rs

    |-- ambiente--|
    |-- difusa  --|
    |--especular--|

    l = vetor_unitario(Pf - Pt);
    
    Iod = Id * Kd * fd
    - fd = (produto_escalar(n, l) > 0) ? produto_escalar(n, l) : 0; 
    Ios = Is * Ks * pow((produto_escalar(r, v) > 0), m)
    - r = -l
    - v = reflexo(l, n)
    - m = coeficiente de polimento do material
*/
class Luz {
    public:
        virtual Cor luminancia(PontoColisao& ptcol) const = 0;

        virtual void atualizar_posicao(const Matriz &MT) = 0;

        float fd(Vetor& n, Vetor& l) const { 
            auto res = produto_escalar(n, l);
            if (res < 0) return 0;
            return res;
        }

        float fs(Vetor& r, Vetor& v, int m) const { 
            auto res = pow(produto_escalar(r, v), m);
            if (res < 0) return 0;
            return res;
        }
};

#endif