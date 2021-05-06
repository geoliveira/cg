#ifndef LUZ_H
#define LUZ_H

#include "Base.h"
#include "Objeto.h"

class Luz {
    public:
        virtual void luminancia(PontoColisao& ptcol) const = 0;
};

#endif