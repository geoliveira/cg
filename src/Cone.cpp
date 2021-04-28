#include "Cone.h"
#include <iostream>

bool Cone::intersectar(const Raio& r,  float t_min, float t_max, PontoColisao& ptcol) const {
    /* V - P0 */
    auto w = _vertice-r.origem();

    /* valores auxiliares */
    auto dr_dr = produto_escalar(r.direcao(), r.direcao());
    auto dr_dc = produto_escalar(r.direcao(), _direcao);
    auto w_w = produto_escalar(w, w);
    auto w_dr = produto_escalar(w, r.direcao());
    auto w_dc = produto_escalar(w, _direcao);
    
    /* cos²(alfa) */
    auto ca = pow(_altura,2)/(pow(_raio,2) + pow(_altura,2));

    auto a = pow(dr_dc,2) - ca * dr_dr;
    auto b = w_dr * ca - w_dc * dr_dc;
    auto c = pow(w_dc,2) - w_w * ca;

    float delta, t_int_mp, s, pb;

    if (a == 0) {
        /* caso especial: dr paralela a geratriz. somente uma raiz: delta = -2*b + c; */
        t_int_mp = -c/b;
        
        /* interseccao com a superficie do cone */
        s = produto_escalar(r.para(t_int_mp) - _centro, _direcao);

        /* ponto de colisao dentro do cone 0 < S < H */
        if (!(s > 0 && s < _altura)) return false;

        /* interseccao com a base do cone */
        pb = -produto_escalar(w, _direcao)/dr_dc;

        /* com pb ja valido, vemos qual t menor */
        t_int_mp = (s < pb) ? s : pb;

    } else {
        float t_1, t_2, s_1, s_2;
        bool t_1_valida = false, t_2_valida = false;

        delta = pow(b,2) - a*c;

        /* sem interseccao */
        if (delta < 0) return false;
        
        /* testando p/ t1 */
        t_1 = -b/a + sqrt(delta);

        /* interseccao com a superficie do cone */
        s_1 = produto_escalar(r.para(t_1) - _centro, _direcao);

        /* ponto de colisao dentro do cone 0 < S < H */
        t_1_valida = (!(s_1 > 0 && s_1 < _altura));

        /* testando p/ t2 se hover */
        if (delta > 0) {
            t_2 = -b/a - sqrt(delta);
            
            /* interseccao com a superficie do cone */
            s_2 = produto_escalar(r.para(t_2) - _centro, _direcao);

            /* ponto de colisao dentro do cone 0 < S < H */
            t_2_valida = (!(s_2 > 0 && s_2 < _altura));
        }

        if (t_1_valida && t_2_valida) { /* nao precisa calcular a com a base */
            t_int_mp = (s_1 < s_2) ? s_1 : s_2;
        } 
        else if (!t_1_valida && t_2_valida) {
            t_int_mp = s_2;
        } 
        else if (t_1_valida && !t_2_valida) { /* interseccao com a base do cone */
            pb = -produto_escalar(w, _direcao)/dr_dc;

            /* verificar se ponto esta dentro do raio da base */
            // ((r.para(pb)-_centro).comprimento() < _raio)

            /* com pb ja valido, vemos qual t menor */
            t_int_mp = (s_1 < pb) ? s_1 : pb;
        } else {
            /* sem interseccao */
            return false;
        }
    }

    if(!(t_int_mp > t_min && t_int_mp < t_max)) return false;

    ptcol.t_int = t_int_mp;
    ptcol.pt = r.para(t_int_mp);
    ptcol.normal = (ptcol.pt - _centro) / _raio;
    ptcol.cor = _cor;

    return true;
}

void Cone::atualizar_pontos(const Matriz &MT) {
    Ponto auxiliar = _vertice;
    _vertice = MT*auxiliar;
}