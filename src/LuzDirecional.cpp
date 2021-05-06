#include "LuzDirecional.h"

void LuzDirecional::luminancia(PontoColisao& ptcol) const {
    ptcol.cor = ptcol.cor * _intensidade * _d;
}