#ifndef VETOR_H
#define VETOR_H

#include <cmath>
#include <iostream>

using namespace std;

class Vetor {
    public:
        Vetor() : e{0, 0, 0} {}
        Vetor(float e0, float e1, float e2) : e{e0, e1, e2} {}

        float x() const { return e[0]; }
        float y() const { return e[1]; }
        float z() const { return e[2]; }

        Vetor operator-() const { return Vetor(-e[0], -e[1], -e[2]); }
        float operator[](int i) const { return e[i]; }
        float& operator[](int i) { return e[i]; }

        Vetor& operator+=(const Vetor &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        Vetor& operator*=(const float t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        Vetor& operator/=(const float t) {
            return *this *= 1/t;
        }

        float comprimento() const {
            return sqrt(pts_ao_quadrado());
        }

        float pts_ao_quadrado() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        /*
        inline static Vetor random() {
            return Vetor(random_double(), random_double(), random_double());
        }

        inline static Vetor random(double min, double max) {
            return Vetor(random_double(min, max), random_double(min, max), random_double(min,max));
        }
        */
        bool proximo_de_zero() const {
            return (fabs(e[0]) < 1e-8) && (fabs(e[1]) < 1e-8) && (fabs(e[2]) < 1e-8);
        }
        
    public:
        float e[3];
};

using Ponto = Vetor;
using Cor = Vetor;

#endif