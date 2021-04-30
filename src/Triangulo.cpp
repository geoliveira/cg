#include "Cilindro.h"
#include <iostream>

bool Cilindro::intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const {

    /*
    if(!(t_int > t_min && t_int < t_max)) return false;

    ptcol.t_int = t_int;
    ptcol.pt = r.para(t_int);
    // ptcol.normal = (ptcol.pt - _base) / _raio;
    ptcol.cor = _cor;
    */
    return true;
}

void Cilindro::atualizar_pontos(const Matriz &MT) {
    // Ponto auxiliar = _base;
    // _base = MT*auxiliar;
}

void Cilindro::rotacionar(const Matriz &MT) {
    // Ponto auxiliar = _direcao;
    // _direcao = MT*auxiliar;
}