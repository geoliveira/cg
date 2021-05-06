#include "LuzSpot.h"

void LuzSpot::luminancia(PontoColisao& ptcol) const {
    auto l = vetor_unitario(_p0 - ptcol.pt);
    auto cosa = produto_escalar(ptcol.pt, _p0);

    /* passou do 'raio' de iluminacao da luz */
    if (cosa < cos(_theta)) return;

    ptcol.cor = ptcol.cor * _intensidade * pow(cosa, _e);
}