#include "Cluster.h"

void Cluster::configurar(Vetor d, float y_min) {
    _direcao = vetor_unitario(d);

    float h_max = -100000;
    float x_medio = 0, z_medio = 0;
    float raio = 0;

    for (const Malha& obj : _objetos) {
        for(const Ponto& v : obj._vertices) {
                x_medio += v.x();
                z_medio += v.z();

                if(h_max < v.y()) h_max = v.y();
        }
    }

    x_medio /= _objetos.size();
    z_medio /= _objetos.size();

    _base = Ponto(x_medio, y_min, z_medio, 1);

    float dist_bc;
    for (const Malha& obj : _objetos) {
        for(const Ponto& v : obj._vertices) {
            dist_bc = (_base - v).comprimento();
            if (raio < dist_bc) raio = dist_bc;
        }
    }

    atualizar_topo();
}

bool Cluster::intersectar(const Raio& r, float t_min, float t_max, PontoColisao& ptcol) const {
    PontoColisao temp_ptcol;
    auto temp_t_max = t_max;
    bool colisao = false;

    for (const Malha& obj : _objetos)
    {
        if (obj.intersectar(r, t_min, temp_t_max, temp_ptcol)) 
        {
            colisao = true;
            temp_t_max = temp_ptcol.t_int;
            ptcol = temp_ptcol;
        }
    }

    return colisao;
}

void Cluster::atualizar_pontos(const Matriz &MT) {
    for (Malha& obj : _objetos) obj.atualizar_pontos(MT);
}