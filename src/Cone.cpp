#include "Cone.h"
#include <iostream>

bool Cone::intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const {
    /* V - P0 */
    auto v = _vertice-r.origem();

    /* valores auxiliares */
    auto dr_dr = produto_escalar(r.direcao(), r.direcao());
    auto dr_dc = produto_escalar(r.direcao(), _direcao);
    auto v_v = produto_escalar(v, v);
    auto v_dr = produto_escalar(v, r.direcao());
    auto v_dc = produto_escalar(v, _direcao);

    /* beta eh o inverso de 1/(CA)² com CA igual a cos²(a) = h²/(r²+h²) */
    // auto beta = (pow(_raio,2) + pow(_altura,2)) / pow(_altura,2);
    
    // auto a = dr_dr - beta * pow(dr_dc, 2);
    // auto b = - 2 * ( w_dr - beta* w_dc * dr_dc );
    // auto c = w_w - beta * w_dr;

    // auto delta = pow(b,2) - 4*a*c;
    
    /* cos²(alfa) */
    auto ca = pow(_altura,2)/(pow(_raio,2) + pow(_altura,2));

    auto a = pow(dr_dc,2) - ca * dr_dr;
    auto b = v_dr * ca - v_dc * dr_dc;
    auto c = pow(v_dc,2) - v_v * ca;

    float delta;
    float t_int_mp;
    float s;
    if (a == 0) {
        /* caso especial: dr paralela a geratriz. somente uma raiz */
        // delta = -2*b + c;

        t_int_mp = -c/b;
        // valido p/ superficie
        // se 2 pontos 
        
        /* interseccao com a superficie do cone */
        auto s = produto_escalar(r.para(t_int_mp) - _centro, _direcao);

        /* ponto de colisao dentro do cone 0 < S < H */
        if (!(s > 0 && s < _altura)) return false;

        
    } else {
        delta = pow(b,2) - a*c;
    
        if (delta < 0) return false;
        
        t_int_mp = -b/a + sqrt(delta); // -

        /* ponto nao valido */
        /* escalar(Pint-C, dc) = S*/
        // if (S > 0 && S < _altura) return false;
        /* 
        pegar mais proximo t

        t1 e t2 ok
            t1 n e t2 ok = testar com a base
            testar com a base 
            t1 ok e t2 n 

        Pb = (produto_escalar(C-P0,dc))/dr_dc

        valido se Pb-C < _raio
        */
    }


    // if (delta > 0) {
        // t_int_mp = -b - sqrt(delta)/a;
        // 
        // if(!(t_int_mp > t_min && t_int_mp < t_max)) return false;
    // }

    // ptcol.t_int = t_int_mp;
    // ptcol.pt = r.para(t_int_mp);
    // ptcol.normal = (ptcol.pt - _centro) / _raio;
    // ptcol.cor = _cor;

    return true;
}

void Cone::atualizar_pontos(const Matriz &MT) {
    // Ponto auxiliar = _vertice;
    // _vertice = MT*auxiliar;
}