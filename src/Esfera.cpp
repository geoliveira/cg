#include "Esfera.h"
#include "Vetor.h"

bool Esfera::intersectar(const Raio& r, PontoIntersec& rec) const {
    Ponto raiz_1, raiz_2;
    double t_int_1, t_int_2;
    Vetor oc = r.origem() - _centro;

    auto a = produto_escalar(r.direcao(), r.direcao());
    auto b = produto_escalar(oc, r.direcao());
    auto c = produto_escalar(oc, oc-(_raio*_raio)); 
    
    auto delta = b*b - 4*a*c;
    
    if (delta < 0) return false;
    
    // t_int_1 = -b + sqrt(delta)/a;
    // raiz_1 = r.para(t_int_1);
    
    // if (delta > 0) {
    //     t_int_2 = -b - sqrt(delta)/a;
    //     raiz_2 = r.para(t_int_2);
        
    //     if((r.origem()-raiz_1).comprimento() > (r.origem()-raiz_2).comprimento())
    //     {
    //         raiz_1 = raiz_2;
    //     }
    // }

    // // rec.t = raiz_1;
    // rec.p = raiz_1;
    // rec.normal = (rec.p - _centro) / _raio;

    return true;
}