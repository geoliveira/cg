#include "LuzPontual.h"

void LuzPontual::luminancia(PontoColisao& ptcol) const {
    auto l = vetor_unitario(_p0 - ptcol.pt);

    ptcol.cor = ptcol.cor * _intensidade * ( 1 / (ptcol.pt-_p0).comprimento() );
}