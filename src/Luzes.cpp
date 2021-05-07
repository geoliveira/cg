#include "Luzes.h"

Cor Luzes::luminancia(PontoColisao& ptcol) const {
    for (const auto& l : _luzes) ptcol.cor += l->luminancia(ptcol);

    return Cor(0, 0, 0);
}