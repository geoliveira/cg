#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Base.h"
#include "Camera.h"
#include "Render.h"

int main() {
    string path_abs = "img/img_"+data_atual()+".ppm";
    string cmd = "eog "+path_abs;
    
    int Wpix = 400;
    int Hpix = 711;

    Ponto janela_pts(3.5, 2.0, -1.0, 1);
    Ponto origem(0, 0, 0, 1);
    Ponto lookat(0, 0, -1, 1);
    Ponto viewup(0, 1, 0, 1);

    // ULTIMO COMPONENTE DE PONTO VALIDO?
    Camera cam(origem, lookat, viewup, janela_pts, Wpix, Hpix);

    Render render(path_abs, cmd, cam);

    render.tirar_fotografia();
       
    return 0;
}