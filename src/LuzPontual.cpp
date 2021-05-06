#include "LuzPontual.h"

Cor LuzPontual::luminancia(PontoColisao& ptcol) const {
    return _intensidade * ( 1 / (ptcol.pt-_p0).comprimento() );
}