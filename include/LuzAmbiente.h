#ifndef LUZAMBIENTE_H
#define LUZAMBIENTE_H

#include "Base.h"
#include "Luz.h"

class LuzAmbiente : public Luz {
    public:
        LuzAmbiente() : _intensidade{1, 1, 1} {};
        
        LuzAmbiente(const Cor& c) : _intensidade(c) {}

        virtual Cor luminancia(PontoColisao& ptcol) const override;

        virtual void atualizar_posicao(const Matriz &MT) override {};

        virtual bool tem_posicao(void) const override { return false; }

        virtual Ponto posicao(void) const override {};
    
    public:
        Cor _intensidade;
};

#endif