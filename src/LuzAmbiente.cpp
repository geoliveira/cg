#include "LuzAmbiente.h"

void LuzAmbiente::luminancia(PontoColisao& ptcol) const {
    ptcol.cor = ptcol.cor * _intensidade;
}