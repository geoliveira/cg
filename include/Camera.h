#ifndef CAMERA_H
#define CAMERA_H

#include "Base.h"
#include "Matriz.h"

/**
 * @param lookfrom ponto de origem da camera
 * @param lookat ponto no qual a camera aponta
 * @param viewup vetor unitario de sentido eixo j
 * @param fov campo de visao (field of view) da camera
*/
class Camera {
    public:
        Camera() {}

        Camera(Ponto lookfrom, Ponto lookat, Vetor viewup) {
            
            /* coordenadas de camera (i, k, k) */
            _k = vetor_unitario(lookfrom - lookat);
            _i = vetor_unitario(cruz(viewup, _k));
            _j = cruz(_k, _i);
            _Q0 = lookfrom;

            _CpM.coord_cpm(_i, _j, _k, _Q0);
            _CpM.coord_mpc(_i, _j, _k, _Q0);

            // _MpC.inversa(_CpM);
        }

        Raio obter_raio(double i, double j) const {
            return Raio();
        }


    private:
        Ponto _Q0;
        Vetor _i;
        Vetor _j;
        Vetor _k;
        Matriz _CpM;
        Matriz _MpC;
};
#endif