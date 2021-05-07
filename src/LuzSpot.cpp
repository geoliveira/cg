#include "LuzSpot.h"

Cor LuzSpot::luminancia(PontoColisao& ptcol) const {
    auto s = ptcol.pt-_p0;
    auto cosp = produto_escalar(_d,s);

    /* passou do 'raio' de iluminacao da luz */
    if (cosp < cos(_theta)) return Cor(0, 0, 0);

    auto l = vetor_unitario(_p0 - ptcol.pt);
    auto n = ptcol.normal;
    auto v = -ptcol.dr;
    auto r = reflexo(l, n);
    auto m = ptcol.m;
    auto Ko = ptcol.cor;
    
    auto If = _intensidade * pow(cosp, _e);

    auto ftd = fd(n, l);
    auto fts = fs(r, v, m);

    return If*Ko*ftd + If*Ko*fts;
}