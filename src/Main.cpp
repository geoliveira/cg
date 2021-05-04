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
void construir_paredes_chao(Cenario &world, string cubo_obj);
void construir_teto(Cenario &world, string cubo_obj);
void construir_balcao_pratileira(Cenario &world, string cubo_obj);
void construir_freezer(Cenario &world, string obj);

int main() {
    /* configuracao de arquivo */
    string path_abs = "img/img_"+data_atual()+".ppm";
    string cmd = "eog "+path_abs;

    /* configuração de janela (abertura no plano bloqueiador) 
        - quantidade vertical e Cenhorizontal de pixels
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
            - criar objeto
            - aplicar transformacoes
            - adicionar ao cenario
        - atualizar coordenadas de mundo para coordenadas de camera */
    Cenario world;

    construir_paredes_chao(world, "obj/cubo.obj");
    construir_teto(world, "obj/piramide.obj");
    construir_balcao_pratileira(world, "obj/cubo.obj");
    construir_freezer(world, "obj/cubo.obj");

    // world.atualizar_pontos(matriz_rotacao(-90, 'y'));
    // world.atualizar_pontos(matriz_translacao(Ponto(-30,0,-5,1)));

    world.atualizar_pontos(cam.coord_MpC()); // ultimo passo

    /* definir background do cenario e tirar fotografia
        -  modo de projecao: perspectiva ou ortografica*/
    Cor bg(255, 255, 255);
    Render render(path_abs, cmd, cam);
    render.tirar_fotografia(world, bg, "perspectiva");
       
    return 0;
}
void construir_freezer(Cenario &world, string obj) {
    shared_ptr<Malha> base = make_shared<Malha>(obj);
    base->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    base->atualizar_pontos(matriz_escala(Vetor(2.5, 2.5, 2.5)));
    base->atualizar_pontos(matriz_translacao(Ponto(7.5, -7.5, -20.0)));
    world.add(base);

    shared_ptr<Malha> borracha = make_shared<Malha>(obj, Cor(0,0,0));
    borracha->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    borracha->atualizar_pontos(matriz_escala(Vetor(2.5, 0.1, 2.5)));
    borracha->atualizar_pontos(matriz_translacao(Ponto(7.5, -5.0, -20.0)));
    world.add(borracha);

    // shared_ptr<Malha> pe = make_shared<Malha>(obj, Cor(80, 253, 192));
    // pe->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    // pe->atualizar_pontos(matriz_escala(Vetor(2.5, 0.1, 2.5)));
    // pe->atualizar_pontos(matriz_translacao(Ponto(7.5, -5.0, -20.0)));
    // world.add(pe);

}

void construir_balcao_pratileira(Cenario &world, string obj) {
    shared_ptr<Malha> balcao = make_shared<Malha>(obj);
    balcao->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    balcao->atualizar_pontos(matriz_escala(Vetor(2.25, 0.1, 1)));
    balcao->atualizar_pontos(matriz_translacao(Ponto(2.25, -3.5, -12.5)));
    world.add(balcao);

    shared_ptr<Malha> pratileira = make_shared<Malha>(obj);
    pratileira->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pratileira->atualizar_pontos(matriz_escala(Vetor(2.5, 0.1, 1.5)));
    pratileira->atualizar_pontos(matriz_translacao(Ponto(2.75, -1.5, -27.25)));
    world.add(pratileira);
}

void construir_teto(Cenario &world, string obj) {
    shared_ptr<Malha> teto = make_shared<Malha>(obj);
    teto->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5)));
    teto->atualizar_pontos(matriz_escala(Vetor(7.5, 2.5, 7.5)));
    teto->atualizar_pontos(matriz_translacao(Ponto(5, 2.5, 7.5)));
    world.add(teto);
}

void construir_paredes_chao(Cenario &world, string cubo_obj) {
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