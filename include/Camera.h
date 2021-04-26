#ifndef CAMERA_H
#define CAMERA_H

#include "Base.h"
#include "Matriz.h"

/**
 * @param lookfrom ponto de origem da camera
 * @param lookat ponto no qual a camera aponta
 * @param viewup vetor unitario de sentido eixo j
*/
class Camera {
    public:
        Camera() {}

        Camera(Ponto lookfrom, Ponto lookat, Ponto viewup, Ponto janela_pts, int Wpix, int Hpix) {
            
            /* coordenadas de camera (i, k, k) */
            _k = vetor_unitario(lookfrom - lookat);
            _i = vetor_unitario(cruz((viewup - lookfrom), _k));
            _j = cruz(_k, _i);
            _Q0 = lookfrom;

            _CpM = coordenadas_cpm(_i, _j, _k, _Q0);
            _MpC = coordenadas_mpc(_i, _j, _k, _Q0);

            float Px, Py, Pz = janela_pts.z();
            
            auto x_min = -janela_pts.x();
            auto x_max = janela_pts.x();
            auto delta_x = (x_max-x_min)/Wpix;
            
            auto y_min = -janela_pts.y();
            auto y_max = janela_pts.y();
            auto delta_y = (y_max-y_min)/Hpix;

            _MP = alocar(Hpix, Wpix);

            _Hpix = Hpix;
            _Wpix = Wpix;

            for (int h = Hpix-1; h >= 0; --h)
            {
                Py = y_min + delta_y/2 + h*delta_y;

                for (int w = 0; w < Wpix; ++w)
                {
                    Px = x_min + delta_x/2 + w*delta_x;
                    _MP[h][w] = Ponto(Px, Py, Pz, 1);
                }
            }
        }

        Ponto **alocar(int coluna, int linha){
            Ponto **M;
            int i;
            
            M = (Ponto **) malloc(sizeof(Ponto *) * coluna);

            if(M == NULL){
                printf("Memoria insuficiente.\n");
                return nullptr;
            }
            for(i = 0; i < coluna; i++)
            {
                M[i] = (Ponto *) malloc(sizeof(Ponto) * linha);
                if(M[i] == NULL){
                    printf("Memoria insuficiente.\n");
                    return nullptr;
                }
            }
            // cout << "-1" << endl;
            return M;
        }

        Ponto origem() {
            return _Q0;
        }

        Ponto obter_ponto(int i, int j) {
            return _MP[i][j];
        }

        int largura_imagem() {
            return _Wpix;
        }

        int altura_imagem() {
            return _Hpix;
        }

        Matriz coord_CpM() {
            return _CpM;
        }

        Matriz coord_MpC() {
            return _MpC;
        }

    private:
        Ponto _Q0;
        Vetor _i;
        Vetor _j;
        Vetor _k;
        Matriz _CpM;
        Matriz _MpC;
        Ponto** _MP;
        int _Hpix, _Wpix;
};

#endif