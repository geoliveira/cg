#include <stdio.h>
#include <iostream>
#include <fstream>

#include "Base.h"
#include "Camera.h"
#include "Render.h"
#include "Objeto.h"
#include "Esfera.h"
#include "Cone.h"
#include "Cilindro.h"
#include "Triangulo.h"
#include "Malha.h"

void teste_cilindro(Cenario &world);
void teste_cone(Cenario &world);

int main() {
    /* configuracao de arquivo */
    string path_abs = "img/img_"+data_atual()+".ppm";
    string cmd = "eog "+path_abs;
    string arquivo_obj ="obj/cubo.obj";

    /* configuração de janela (abertura no plano bloqueiador) 
        - quantidade vertical e horizontal de pixels
        - vertices de altura, largura e distancia focal da janela */
    int Wpix = 400, Hpix = 400;
    Ponto janela_pts(0.75, 0.75, -0.5, 1);

    /* configuracao sagital da camera */
    Ponto origem(0, 0, 0, 1);
    Ponto lookat(0, 0, -1, 1);
    Ponto viewup(0, 1, 3, 1);
    Camera cam(origem, lookat, viewup, janela_pts, Wpix, Hpix);

    /* criando cenario (passos)
        - para cada objeto (em coordenadas de mundo)
            - criar objeto e adicionar ao cenario
            - aplicar transformacoes
        - atualizar coordenadas de mundo para coordenadas de camera */
    Cenario world;
    world.add(make_shared<Malha>(arquivo_obj));
    world.atualizar_pontos(matriz_translacao(Vetor(0.0, 0.0, -2.0)));
    world.atualizar_pontos(matriz_escala(Vetor(2.0, 2.0, 2.0)));
    world.atualizar_pontos(matriz_rotacao(-45, 'x'));
    world.atualizar_pontos(matriz_rotacao(-45, 'y'));
    world.atualizar_pontos(matriz_translacao(Vetor(-1.5, 1.0, -5.0)));
    teste_cilindro(world);
    teste_cone(world);
    
    world.atualizar_pontos(cam.coord_MpC()); // ultimo passo

    /* definir background do cenario e tirar fotografia
        -  modo de projecao: perspectiva ou ortografica*/
    Cor bg(256, 256, 256);
    Render render(path_abs, cmd, cam);
    render.tirar_fotografia(world, bg, "perspectiva");
       
    return 0;
}

void teste_cilindro(Cenario &world) {
    world.add(make_shared<Triangulo>(Ponto(-0.5,  0.0, -3.0, 1),
                                     Ponto( 0.5,  0.0, -3.0, 1),
                                     Ponto( 0.0,  0.5, -3.0, 1), Cor(256, 2, 2)));
    world.add(make_shared<Cilindro>(Ponto(-1.0,  1.5, -3.0, 1), 0.5, Vetor(-1, 0, 0), 1.0, Cor(256, 2, 2)));
    world.add(make_shared<Cilindro>(Ponto( 1.0,  1.5, -3.0, 1), 0.5, Vetor( 1, 0, 0), 1.0, Cor(256, 2, 2)));
    world.add(make_shared<Cilindro>(Ponto( 0.0,  1.5, -3.0, 1), 0.5, Vetor( 0,-1, 0), 1.0, Cor(2, 256, 2)));
    world.add(make_shared<Cilindro>(Ponto( 0.0, -1.5, -3.0, 1), 0.5, Vetor( 0, 1, 0), 1.0, Cor(2, 256, 2)));
    world.add(make_shared<Cilindro>(Ponto(-1.5, -1.5, -3.0, 1), 0.5, Vetor( 0, 0,-1), 1.0, Cor(2, 2, 256)));
    world.add(make_shared<Cilindro>(Ponto( 1.5, -1.5, -3.5, 1), 0.5, Vetor( 0, 0, 1), 1.0, Cor(2, 2, 256)));
    world.add(make_shared<Cilindro>(Ponto(-0.6, -0.0, -3.0, 1),0.25, Vetor( 0, 0, 1), 1.0, Cor(100, 100, 256)));
    world.add(make_shared<Cilindro>(Ponto( 0.6, -0.0, -3.0, 1),0.25, Vetor( 0, 0,-1), 1.0, Cor(100, 100, 256)));
    world.add(make_shared<Esfera>(Ponto(-0.2,  0.0, -3.4, 1), 0.50, Cor(100, 200, 0)));
    world.add(make_shared<Esfera>(Ponto( 0.2,  0.0, -3.3, 1), 0.40, Cor( 85, 100, 150)));
    world.add(make_shared<Esfera>(Ponto( 0.0,  1.3, -3.4, 1), 0.35, Cor( 50, 10,  15)));
    world.add(make_shared<Esfera>(Ponto( 0.0,  1.0, -3.3, 1), 0.25, Cor(200, 250, 150)));
    world.add(make_shared<Cone>(Ponto(-2.5,  2.5, -3.0, 1), 0.5, Vetor(-1, 0, 0), 1.0, Cor(256, 2, 2)));
    world.add(make_shared<Cone>(Ponto( 2.5,  2.5, -3.0, 1), 0.5, Vetor( 1, 0, 0), 1.0, Cor(256, 2, 2)));
    world.add(make_shared<Cone>(Ponto( 0.0,  1.0, -3.0, 1), 0.5, Vetor( 0,-1, 0), 1.0, Cor(2, 256, 2)));
    world.add(make_shared<Cone>(Ponto( 0.0, -1.0, -3.0, 1), 0.5, Vetor( 0, 1, 0), 1.0, Cor(2, 256, 2)));
    world.add(make_shared<Cone>(Ponto(-2.5, -2.5, -3.0, 1), 0.5, Vetor( 0, 0,-1), 1.0, Cor(2, 2, 256)));
    world.add(make_shared<Cone>(Ponto( 2.5, -2.5, -3.0, 1), 0.5, Vetor( 0, 0, 1), 1.0, Cor(2, 2, 256)));
}

void teste_cone(Cenario &world) {
    world.add(make_shared<Esfera>(Ponto(-0.2,  0.0, -3.4, 1), 0.50, Cor(100, 200, 0)));
    world.add(make_shared<Esfera>(Ponto( 0.2,  0.0, -3.3, 1), 0.40, Cor( 85, 100, 150)));
    world.add(make_shared<Esfera>(Ponto( 0.0,  1.3, -3.2, 1), 0.35, Cor( 85, 100, 150)));
    world.add(make_shared<Esfera>(Ponto( 0.0,  1.0, -3.3, 1), 0.25, Cor( 85, 100, 150)));
    world.add(make_shared<Cone>(Ponto(-1.5,  2.75, -3.0, 1), 0.5, Vetor(-1, 0, 0), 1.0, Cor(256, 2, 2)));
    world.add(make_shared<Cone>(Ponto( 1.5,  2.75, -3.0, 1), 0.5, Vetor( 1, 0, 0), 1.0, Cor(256, 2, 2)));
    world.add(make_shared<Cone>(Ponto( 0.0,  1.5, -3.0, 1), 0.5, Vetor( 0,-1, 0), 1.0, Cor(2, 256, 2)));
    world.add(make_shared<Cone>(Ponto( 0.0, -1.5, -3.0, 1), 0.5, Vetor( 0, 1, 0), 1.0, Cor(2, 256, 2)));
    world.add(make_shared<Cone>(Ponto(-2.0, -2.75, -3.0, 1), 0.5, Vetor( 0, 0,-1), 1.0, Cor(2, 2, 256)));
    world.add(make_shared<Cone>(Ponto( 2.0, -2.75, -3.0, 1), 0.5, Vetor( 0, 0, 1), 1.0, Cor(2, 2, 256)));
}