#ifndef LUZES_H
#define LUZES_H

#include "Base.h"
#include "Luz.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;
using std::vector;

class Luzes : public Luz {
    public:
        Luzes() {}
        Luzes(shared_ptr<Luz> l) { add(l); }

        void clear() { _luzes.clear(); }
        
        void add(shared_ptr<Luz> l) { _luzes.push_back(l); }

        virtual Cor luminancia(PontoColisao& ptcol) const override;

    public:
        vector<shared_ptr<Luz>> _luzes;
};

#endif