#ifndef CAMERA_H
#define CAMERA_H

#include "Base.h"

class Camera {
    public:
        Camera() {}

        Camera(Ponto lookfrom, Ponto lookat, Vetor viewup) {
            auto k = vetor_unitario(lookfrom - lookat);
            auto i = vetor_unitario(cruz(viewup, k));
            auto j = cruz(k, i);

            origem = lookfrom;
        }

        Raio obter_raio(double u, double v) const {
            return Raio();
        }

    private:
        Ponto origem;
};
#endif