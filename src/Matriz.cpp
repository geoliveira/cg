#include "Matriz.h"

Matriz coordenadas_cpm(Vetor i, Vetor j, Vetor k, Ponto o) {
    return Matriz(i.x(), j.x(), k.x(), o.x(),
                  i.y(), j.y(), k.y(), o.y(),
                  i.z(), j.z(), k.z(), o.z(),
                  0,     0,     0,     1);

}

Matriz coordenadas_mpc(Vetor i, Vetor j, Vetor k, Ponto o) {
    return Matriz(i.x(), i.y(), i.z(), -escalar(o, i),
                  j.x(), j.y(), j.z(), -escalar(o, j),
                  k.x(), k.y(), k.z(), -escalar(o, k),
                  0,     0,     0,      1);
}