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
    string cubo_obj = "obj/cubo.obj";

    /* configuração de janela (abertura no plano bloqueiador) 
        - quantidade vertical e horizontal de pixels
        - vertices de altura, largura e distancia focal da janela */
    int Wpix = 400, Hpix = 400;
    Ponto janela_pts(0.75, 0.75, -1.5, 1);

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
    
    shared_ptr<Malha> chao = make_shared<Malha>(cubo_obj);
    chao->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -1.5)));
    chao->atualizar_pontos(matriz_escala(Vetor(30, 0.1, 15)));
    chao->atualizar_pontos(matriz_translacao(Ponto(0.0, -10.0, -1.5)));
    world.add(chao);

    shared_ptr<Malha> pe = make_shared<Malha>(cubo_obj);
    pe->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pe->atualizar_pontos(matriz_escala(Vetor(0.25, 5, 5)));
    pe->atualizar_pontos(matriz_translacao(Ponto(0.0, -5.0, -5.0)));
    world.add(pe);

    shared_ptr<Malha> pd = make_shared<Malha>(cubo_obj);
    pd->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pd->atualizar_pontos(matriz_escala(Vetor(0.25, 5, 5)));
    pd->atualizar_pontos(matriz_translacao(Ponto(10.0, -5.0, -5.0)));
    world.add(pd);

    shared_ptr<Malha> pt = make_shared<Malha>(cubo_obj);
    pt->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pt->atualizar_pontos(matriz_escala(Vetor(0.25, 5, 5)));
    pt->atualizar_pontos(matriz_translacao(Ponto(5.0, -5.0, -10.0)));
    pt->atualizar_pontos(matriz_rotacao(90, 'y'));
    pt->atualizar_pontos(matriz_translacao(Ponto(40, 0, -30.0)));
    world.add(pt);

    shared_ptr<Malha> pf = make_shared<Malha>(cubo_obj);
    pf->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pf->atualizar_pontos(matriz_escala(Vetor(0.25, 2.25, 3)));
    pf->atualizar_pontos(matriz_translacao(Ponto(5.0, -5.0, -10.0)));
    pf->atualizar_pontos(matriz_rotacao(90, 'y'));
    pf->atualizar_pontos(matriz_translacao(Ponto(28, -2.5, -20.0)));
    world.add(pf);

    shared_ptr<Malha> balcao = make_shared<Malha>(cubo_obj);
    balcao->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    balcao->atualizar_pontos(matriz_escala(Vetor(2.25, 0.1, 1)));
    balcao->atualizar_pontos(matriz_translacao(Ponto(2.25, -3.5, -12.5)));
    world.add(balcao);

    // world.atualizar_pontos(matriz_rotacao(-15, 'y'));
    // world.atualizar_pontos(matriz_rotacao(-45, 'y'));
    // world.atualizar_pontos(matriz_translacao(Vetor(0.0, 0.0, -1.5)));
    // teste_cilindro(world);
    // teste_cone(world);
    
    world.atualizar_pontos(cam.coord_MpC()); // ultimo passo

    /* definir background do cenario e tirar fotografia
        -  modo de projecao: perspectiva ou ortografica*/
    Cor bg(255, 255, 255);
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