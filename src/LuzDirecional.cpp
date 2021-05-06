#include "LuzDirecional.h"

Cor LuzDirecional::luminancia(PontoColisao& ptcol) const {
    return _intensidade * _d;
}