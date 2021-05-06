#ifndef LUZDIRECIONAL_H
#define LUZDIRECIONAL_H

#include "Base.h"
#include "Luz.h"

class LuzDirecional : public Luz {
    public:
        LuzDirecional(const Vetor& d, const Cor& c) : _d(d), _intensidade(c) {}

        virtual Cor luminancia(PontoColisao& ptcol) const override;
    
    public:
        Vetor _d;
        Cor _intensidade;
};

#endif