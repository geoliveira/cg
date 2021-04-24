#include "Vetor.h"

ostream& operator<<(ostream &out, const Vetor &v) {
    if (v.w() == 0) 
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2] << ' ' << v.e[3];
}

Vetor operator+(const Vetor &u, const Vetor &v) {
    return Vetor(u.e[0] + v.e[0],
                 u.e[1] + v.e[1],
                 u.e[2] + v.e[2],
                 u.e[3] + v.e[3]);
}

Vetor operator-(const Vetor &u, const Vetor &v) {
    return Vetor(u.e[0] - v.e[0],
                 u.e[1] - v.e[1],
                 u.e[2] - v.e[2],
                 u.e[3] - v.e[3]);
}

Vetor operator*(const Vetor &u, const Vetor &v) {
    return Vetor(u.e[0] * v.e[0],
                 u.e[1] * v.e[1],
                 u.e[2] * v.e[2],
                 u.e[3] * v.e[3]);
}

Vetor operator*(float t, const Vetor &v) {
    return Vetor(t * v.e[0],
                 t * v.e[1],
                 t * v.e[2],
                 t * v.e[3]);
}

Vetor operator*(const Vetor &v, float t) {
    return t * v;
}

Vetor operator/(Vetor v, float t) {
    return (1/t) * v;
}

float produto_escalar(const Vetor &u, const Vetor &v) {
    return   u.e[0] * v.e[0]
           + u.e[1] * v.e[1]
           + u.e[2] * v.e[2];
}

Vetor cruz(const Vetor &u, const Vetor &v) {
    return Vetor(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                 u.e[2] * v.e[0] - u.e[0] * v.e[2],
                 u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

Vetor vetor_unitario(Vetor v) {
    return v / v.comprimento();
}

Vetor reflexo(const Vetor& v, const Vetor& n) {
    return v - 2*n*escalar(v, n);
}

/*
Vetor random_p_in_unit_sphere() {
    while (true) {
        auto p = Vetor::random(-1,1);
        if (p.pts_ao_quadrado() >= 1) continue;
        return p;
    }
}

Vetor random_p_unit_vector() {
    return unit_Vetor(random_p_in_unit_sphere());
}

Vetor random_in_hemisphere(const Vetor& normal) {
    Vetor in_unit_sphere = random_p_in_unit_sphere();
    if (dot(in_unit_sphere, normal) > 0.0) return in_unit_sphere;
    return -in_unit_sphere;
}
*/

