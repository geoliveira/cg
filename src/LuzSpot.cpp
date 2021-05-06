#include "LuzSpot.h"

Cor LuzSpot::luminancia(PontoColisao& ptcol) const {
    auto s = ptcol.pt-_p0;
    auto cosp = produto_escalar(_d,s);

    /* passou do 'raio' de iluminacao da luz */
    if (cosp < cos(_theta)) return Cor(1, 1, 1);

    return _intensidade * pow(cosp, _e);
}