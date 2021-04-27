#include "Esfera.h"
#include <iostream>

bool Esfera::intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const {
    Ponto raiz_1, raiz_2;
    double t_int_1, t_int_2;
    Vetor oc = r.origem() - _centro;

    auto b = produto_escalar(oc, r.direcao());
    auto c = produto_escalar(oc, oc)-(_raio*_raio); 
    
    auto delta = b*b - c;
    
    if (delta < 0) return false;
    
    t_int_1 = -b + sqrt(delta);
    raiz_1 = r.para(t_int_1);
    
    if (delta > 0) {
        t_int_2 = -b - sqrt(delta);
        raiz_2 = r.para(t_int_2);
        
        if((r.origem()-raiz_1).comprimento() > (r.origem()-raiz_2).comprimento())
        {
            raiz_1 = raiz_2;
            t_int_1 = t_int_2;
        }
    }

    ptcol.t_int = t_int_1;
    ptcol.pt = raiz_1;
    ptcol.normal = (ptcol.pt - _centro) / _raio;
    ptcol.cor = _cor;

    return true;
}

void Esfera::atualizar_pontos(const Matriz &MT) {
    Ponto auxiliar = _centro;
    _centro = MT*auxiliar;
}