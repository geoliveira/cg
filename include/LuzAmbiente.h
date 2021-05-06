#ifndef LUZAMBIENTE_H
#define LUZAMBIENTE_H

#include "Base.h"
#include "Luz.h"

class LuzAmbiente : public Luz {
    public:
        LuzAmbiente() : _intensidade{0.5, 0.5, 0.5} {};
        
        LuzAmbiente(const Cor& c) : _intensidade(c) {}

        virtual void luminancia(PontoColisao& ptcol) const override;
    
    public:
        Cor _intensidade;
};

#endif