#include "Matriz.h"

Matriz coordenadas_cpm(Vetor i, Vetor j, Vetor k, Ponto o) {
    return Matriz(i.x(), j.x(), k.x(), o.x(),
                  i.y(), j.y(), k.y(), o.y(),
                  i.z(), j.z(), k.z(), o.z(),
                  0,     0,     0,     1);
}

Matriz coordenadas_mpc(Vetor i, Vetor j, Vetor k, Ponto o) {
    return Matriz(i.x(), i.y(), i.z(), -produto_escalar(o, i),
                  j.x(), j.y(), j.z(), -produto_escalar(o, j),
                  k.x(), k.y(), k.z(), -produto_escalar(o, k),
                  0,     0,     0,      1);
}

Matriz matriz_rotacao(float graus, char eixo) {
    if (eixo == 'z')
    {
        return Matriz( cos(graus), -sin(graus), 0, 0,
                       sin(graus),  cos(graus), 0, 0,
                       0,           0,          1, 0,
                       0,           0,          0, 1);
    } 
    else if (eixo == 'x')
    {
        return Matriz( 1, 0,           0,          0,
                       0, cos(graus), -sin(graus), 0,
                       0, sin(graus),  cos(graus), 0,
                       0, 0,           0,          1);
    } 
    else if (eixo == 'y')
    {
        return Matriz( cos(graus),  0, sin(graus), 0,
                       0,           1, 0,          0,
                      -sin(graus),  0, cos(graus), 0,
                       0,           0, 0,          1);
    } else {
        return Matriz();
    }
}

Matriz matriz_escala(Vetor S) {
    return Matriz(S.x(), 0,     0,     0,
                  0,     S.y(), 0,     0,
                  0,     0,     S.z(), 0,
                  0,     0,     0,     1);
}

Matriz matriz_translacao(Vetor t) {
    return Matriz(1, 0, 0, t.x(),
                  0, 1, 0, t.y(),
                  0, 0, 1, t.z(),
                  0, 0, 0, 1);
}