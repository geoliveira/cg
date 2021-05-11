#include "Luzes.h"

Cor Luzes::luminancia(PontoColisao& ptcol) const {
    for (const auto& l : _luzes) ptcol.cor += l->luminancia(ptcol);

    return Cor(0, 0, 0);
}

void Luzes::atualizar_posicao(const Matriz &MT) {
    for (const auto& l : _luzes) l->atualizar_posicao(MT);
}