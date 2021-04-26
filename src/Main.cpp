#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Base.h"
#include "Camera.h"
#include "Render.h"
#include "Objeto.h"
#include "Esfera.h"

int main() {
    string path_abs = "img/img_"+data_atual()+".ppm";
    string cmd = "eog "+path_abs;
    
    int Wpix = 400;
    int Hpix = 400;

    /*
        CRIAR OBJ NO BLENDER
            APENAS OPÇÃO TRIANGULARIZAR
        CRIAR LEITOR DE OBJ
        CRIAR A CLASSE PRO OBJ
            VECTOR<TRIANGULOS> FACES
        CRIAR OBJETO TRIANGO
            3 VERTICES
    */

    Esfera esfera(Ponto(0.5, 0, -3, 1), 0.9);
    
    /* altura, largura e distancia focal da janela */
    Ponto janela_pts(0.5, 0.5, -1.0, 1);
    Ponto origem(0, 0, 0, 1);
    Ponto lookat(0, 0, -1, 1);
    Ponto viewup(0, 1, 3, 1);

    Camera cam(origem, lookat, viewup, janela_pts, Wpix, Hpix);

    Render render(path_abs, cmd, cam);

    render.tirar_fotografia(esfera);
       
    return 0;
}