#ifndef LUZPONTUAL_H
#define LUZPONTUAL_H

#include "Base.h"
#include "Luz.h"

class LuzPontual : public Luz {
    public:
        LuzPontual(const Ponto& p, const Cor& c) : _p0(p), _intensidade(c) {}

        virtual Cor luminancia(PontoColisao& ptcol) const override;
    
    public:
        Ponto _p0;
        Cor _intensidade;
};

#endif