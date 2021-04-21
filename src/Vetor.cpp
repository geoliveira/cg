#include "Vetor.h"

inline ostream& operator<<(ostream &out, const Vetor &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vetor operator+(const Vetor &u, const Vetor &v) {
    return Vetor(u.e[0] + v.e[0],
                 u.e[1] + v.e[1],
                 u.e[2] + v.e[2]);
}

inline Vetor operator-(const Vetor &u, const Vetor &v) {
    return Vetor(u.e[0] - v.e[0],
                 u.e[1] - v.e[1],
                 u.e[2] - v.e[2]);
}

inline Vetor operator*(const Vetor &u, const Vetor &v) {
    return Vetor(u.e[0] * v.e[0],
                 u.e[1] * v.e[1],
                 u.e[2] * v.e[2]);
}

inline Vetor operator*(float t, const Vetor &v) {
    return Vetor(t * v.e[0],
                 t * v.e[1],
                 t * v.e[2]);
}

inline Vetor operator*(const Vetor &v, float t) {
    return t * v;
}

inline Vetor operator/(Vetor v, float t) {
    return (1/t) * v;
}

/**
 * @brief também conhecido por produto escalar (dot), é soma dos produtos resultantes da multiplicação dos componentes dos vetores
 * @return escalar de tipo float
*/
inline float escalar(const Vetor &u, const Vetor &v) {
    return   u.e[0] * v.e[0]
           + u.e[1] * v.e[1]
           + u.e[2] * v.e[2];
}

inline Vetor cruz(const Vetor &u, const Vetor &v) {
    return Vetor(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                 u.e[2] * v.e[0] - u.e[0] * v.e[2],
                 u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline Vetor vetor_unitario(Vetor v) {
    return v / v.comprimento();
}

inline Vetor reflexo(const Vetor& v, const Vetor& n) {
    return v - 2*n*escalar(v, n);
}

/*
inline Vetor random_p_in_unit_sphere() {
    while (true) {
        auto p = Vetor::random(-1,1);
        if (p.pts_ao_quadrado() >= 1) continue;
        return p;
    }
}

inline Vetor random_p_unit_vector() {
    return unit_Vetor(random_p_in_unit_sphere());
}

inline Vetor random_in_hemisphere(const Vetor& normal) {
    Vetor in_unit_sphere = random_p_in_unit_sphere();
    if (dot(in_unit_sphere, normal) > 0.0) return in_unit_sphere;
    return -in_unit_sphere;
}
*/

