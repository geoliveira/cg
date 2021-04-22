#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Base.h"
#include "Camera.h"
#include "Render.h"

int main() {
    string path_abs = "img/img_"+data_atual()+".ppm";
    string cmd = "eog "+path_abs;
    
    Camera cam(Ponto(0, 0, 0), Ponto(0, 0, -1), Vetor(0, 1, 0));

    Render render(path_abs, cmd, cam);
       
    return 0;
}