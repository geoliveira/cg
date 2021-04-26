#include "Esfera.h"
#include <iostream>

bool Esfera::intersectar(const Raio& r, PontoIntersec& rec) const {
    Ponto raiz_1, raiz_2;
    double t_int_1, t_int_2;
    Vetor oc = r.origem() - _centro;

    // auto a = produto_escalar(r.direcao(), r.direcao()); sempre igual a 1
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

    rec.t = t_int_1;
    rec.p = raiz_1;
    rec.normal = (rec.p - _centro) / _raio;

    return true;
}

void Esfera::atualizar_pontos(const Matriz &MT) {
    Ponto auxiliar = Esfera::_centro;
    cout << Esfera::_centro << endl;
    Esfera::_centro = MT*auxiliar;
    cout << Esfera::_centro << endl;
}