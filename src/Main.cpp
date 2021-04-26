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
    
    int Wpix = 600;
    int Hpix = 400;

    Esfera esfera(Ponto(0,0,-1,1), 0.9);
    
    /* altura, largura e distancia focal da janela */
    Ponto janela_pts(1.5, 2.0, -1.0, 1);
    Ponto origem(0, 0, 0, 1);
    Ponto lookat(0, 0, -1, 1);
    Ponto viewup(0, 1, -1, 1);

    // ULTIMO COMPONENTE DE PONTO VALIDO?
    Camera cam(origem, lookat, viewup, janela_pts, Wpix, Hpix);

    Render render(path_abs, cmd, cam);

    render.tirar_fotografia(esfera);
       
    return 0;
}