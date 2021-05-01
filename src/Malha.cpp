#include <iostream>
#include <vector>

#include "Malha.h"

using namespace std;

bool Malha::intersectar(const Raio& r, float t_min, float t_max, PontoColisao& ptcol) const {
    // PontoColisao temp_ptcol;
    // auto temp_t_max = t_max;
    bool colisao = false;

    for (auto& face : _faces)
    {
        if (face.intersectar(r, t_min, t_max, ptcol)) 
        {
            // return true;
            return true;
            // temp_t_max = temp_ptcol.t_int;
            // ptcol = temp_ptcol;
        }
    }

    return colisao;
}

void Malha::atualizar_pontos(const Matriz &CpM) {
    for (auto& face : _faces) face.atualizar_pontos(CpM);
}