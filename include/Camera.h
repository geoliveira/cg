#ifndef CAMERA_H
#define CAMERA_H

#include "Base.h"

/**
 * @param lookfrom ponto de origem da camera
 * @param lookat ponto no qual a camera aponta
 * @param viewup vetor unitario de sentido eixo j
 * @param fov campo de visao (field of view) da camera
*/
class Camera {
    public:
        Camera() {}

        Camera(Ponto lookfrom, Ponto lookat, Vetor viewup, float fov) {
            auto k = vetor_unitario(lookfrom - lookat);
            auto i = vetor_unitario(cruz(viewup, k));
            auto j = cruz(k, i);

            origem = lookfrom;
        }

        Raio obter_raio(double i, double j) const {
            return Raio();
        }

    private:
        Ponto origem;
};
#endif