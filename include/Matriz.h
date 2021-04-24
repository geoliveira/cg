#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include "Base.h"

class Matriz {
    public:
        Matriz() {
            int i, j;
            for(i = 0; i < 4; i++)
                for(j = 0; j < 4; j++)
                    val[i][j] = 0;
        }

        Matriz(float x00, float x01, float x02, float x03,
               float x10, float x11, float x12, float x13,
               float x20, float x21, float x22, float x23,
               float x30, float x31, float x32, float x33) {
            val[0][0] = x00;
            val[0][1] = x01;
            val[0][2] = x02;
            val[0][3] = x03;

            val[1][0] = x10;
            val[1][1] = x11;
            val[1][2] = x12;
            val[1][3] = x13;

            val[2][0] = x20;
            val[2][1] = x21;
            val[2][2] = x22;
            val[2][3] = x23;

            val[3][0] = x30;
            val[3][1] = x31;
            val[3][2] = x32;
            val[3][3] = x33;
        }

    private:
        float val[4][4];
};

/**
 * @brief dado a base (i,j,k) e ponto origem da camera, retorna matriz transformacao das coordenadas de camera para mundo/cenario
*/
Matriz coordenadas_cpm(Vetor i, Vetor j, Vetor k, Ponto o);

/**
 * @brief dado a base (i,j,k) e ponto origem da camera, retorna matriz transformacao das coordenadas de mundo/cenario para camera 
*/
Matriz coordenadas_mpc(Vetor i, Vetor j, Vetor w, Ponto o);

/**
 * Rot x graus em torno do eixo z
 * | cos(x)  -sen(x)   0    0 |
 * | sen(x)   cos(x)   0    0 |
 * |   0        0      1    0 |
 * |   0        0      0    1 |
 * 
 * Rot x graus em torno do eixo x
 * | 1    0         0     0 |
 * | 0  cos(x)  -sen(x)   0 |
 * | 0  sen(x)   cos(x)   0 |
 * | 0    0         0     1 |
 * 
 * Rot x graus em torno do eixo y
 * |  cos(x)   0   sen(x)  0 |
 * |    0      1     0     0 |
 * | -sen(x)   0   cos(x)  0 |
 * |   0       0     0     1 |
 * 
 * TODO: parametro de tipo objeto, fazendo com que todos os seus vertices sejam rotacionados
*/
Vetor rotacionar(Vetor v, float graus, char eixo);

 /**
 * Matriz (diagonal) E de escala com fator S = Tfinal/Tincial
 * | Sx          0 |
 * |     Sy      0 |
 * |         Sz  0 |
 * | 0   0    0  1 |
 *
*/  
Vetor escalar(Vetor v, Vetor fator_s);

 /**
 * Translação com vetor t = P'-P. Logo: P' = P + t
 * | 1         tx |
 * |    1      ty |
 * |        1  tz |
 * |            1 |
*/
Vetor transladar(Vetor v, Vetor t);

#endif