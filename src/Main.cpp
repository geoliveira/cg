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

void construir_chao(Cenario &world, string obj) {
    shared_ptr<Malha> chao = make_shared<Malha>(obj);
    chao->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -1.5)));
    chao->atualizar_pontos(matriz_escala(Vetor(30, 0.1, 15)));
    chao->atualizar_pontos(matriz_translacao(Ponto(10.0, -10.0, -1.5)));
    world.add(chao);

    shared_ptr<Malha> pista = make_shared<Malha>(obj, Cor(0, 0, 0));
    pista->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -1.5)));
    pista->atualizar_pontos(matriz_escala(Vetor(10, 0.1, 37.5)));
    pista->atualizar_pontos(matriz_translacao(Ponto(-30.0, -10.0, 9.5)));
    world.add(pista);
}

void construir_paredes(Cenario &world, string cubo_obj) {
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
    pf->atualizar_pontos(matriz_translacao(Ponto(28.2, -2.5, -20.0)));
    world.add(pf);
}

void construir_balcao_pratileira(Cenario &world, string obj) {
    shared_ptr<Malha> balcao = make_shared<Malha>(obj);
    balcao->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    balcao->atualizar_pontos(matriz_escala(Vetor(3.25, 0.1, 1.5)));
    balcao->atualizar_pontos(matriz_translacao(Ponto(3.45, -4.75, -16.5)));
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

    shared_ptr<Malha> pe = make_shared<Malha>(obj, Cor(255,255,255));
    pe->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pe->atualizar_pontos(matriz_escala(Vetor(1.24, 0.1, 2.5)));
    pe->atualizar_pontos(matriz_translacao(Ponto(6.25, -4.9, -20.0)));
    world.add(pe);

    shared_ptr<Malha> pd = make_shared<Malha>(obj, Cor(255,255,255));
    pd->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pd->atualizar_pontos(matriz_escala(Vetor(1.24, 0.1, 2.5)));
    pd->atualizar_pontos(matriz_translacao(Ponto(9.0, -4.9, -20.0)));
    world.add(pd);
}

void construir_arvore(Cenario &world) {
    shared_ptr<Cilindro> tronco = make_shared<Cilindro>(Ponto(-12.5, -10.75, -20.0, 1), 1.0, Vetor(0, 1, 0), 10.0, Cor(256, 2, 2));
    shared_ptr<Esfera> folhas = make_shared<Esfera>(Ponto(-13.0, 0.75, -21.0, 1), 4.5, Cor(0, 256, 2));
    world.add(tronco);
    world.add(folhas);
}

void construir_mesa(Cenario &world, string cubo_obj) {
    shared_ptr<Malha> p1 = make_shared<Malha>(cubo_obj);
    p1->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p1->atualizar_pontos(matriz_escala(Vetor(0.25, 2.5, 0.25)));
    p1->atualizar_pontos(matriz_translacao(Ponto(-5.0, -10.0, -14.5)));
    world.add(p1);

    shared_ptr<Malha> p2 = make_shared<Malha>(cubo_obj);
    p2->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p2->atualizar_pontos(matriz_escala(Vetor(0.25, 2.5, 0.25)));
    p2->atualizar_pontos(matriz_translacao(Ponto(-2.5, -10.0, -14.5)));
    world.add(p2);

    shared_ptr<Malha> p3 = make_shared<Malha>(cubo_obj);
    p3->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p3->atualizar_pontos(matriz_escala(Vetor(0.25, 2.5, 0.25)));
    p3->atualizar_pontos(matriz_translacao(Ponto(-5.0, -10.0, -17.0)));
    world.add(p3);

    shared_ptr<Malha> p4 = make_shared<Malha>(cubo_obj);
    p4->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p4->atualizar_pontos(matriz_escala(Vetor(0.25, 2.5, 0.25)));
    p4->atualizar_pontos(matriz_translacao(Ponto(-2.5, -10.0, -17.0)));
    world.add(p4);

    shared_ptr<Malha> tampa = make_shared<Malha>(cubo_obj, Cor(140,128,100));
    tampa->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    tampa->atualizar_pontos(matriz_escala(Vetor(2.25, 0.1, 2.25)));
    tampa->atualizar_pontos(matriz_translacao(Ponto(-3.80, -7.5, -6.0)));
    world.add(tampa);
}

void construir_cadeira(Cenario &world, string cubo_obj) {
    shared_ptr<Malha> p1 = make_shared<Malha>(cubo_obj);
    p1->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p1->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 0.15)));
    p1->atualizar_pontos(matriz_translacao(Ponto(-6.85, -10.0, -15.15)));
    world.add(p1);

    shared_ptr<Malha> p2 = make_shared<Malha>(cubo_obj);
    p2->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p2->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 0.15)));
    p2->atualizar_pontos(matriz_translacao(Ponto(-8.5, -10.0, -15.15)));
    world.add(p2);

    shared_ptr<Malha> p3 = make_shared<Malha>(cubo_obj);
    p3->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p3->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 0.15)));
    p3->atualizar_pontos(matriz_translacao(Ponto(-6.85, -10.0, -16.5)));
    world.add(p3);

    shared_ptr<Malha> p4 = make_shared<Malha>(cubo_obj);
    p4->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p4->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 0.15)));
    p4->atualizar_pontos(matriz_translacao(Ponto(-8.5, -10.0, -16.5)));
    world.add(p4);

    shared_ptr<Malha> costas = make_shared<Malha>(cubo_obj);
    costas->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    costas->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 1.0)));
    costas->atualizar_pontos(matriz_translacao(Ponto(-8.5, -7.0, -11.75)));
    world.add(costas);

    shared_ptr<Malha> tampa = make_shared<Malha>(cubo_obj, Cor(250,109,12));
    tampa->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    tampa->atualizar_pontos(matriz_escala(Vetor(1.0, 0.1, 1.0)));
    tampa->atualizar_pontos(matriz_translacao(Ponto(-7.5, -8.5, -11.75)));
    world.add(tampa);
}

void construir_cadeira2(Cenario &world, string cubo_obj) {
    shared_ptr<Malha> pp1 = make_shared<Malha>(cubo_obj);
    pp1->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pp1->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 0.15)));
    pp1->atualizar_pontos(matriz_translacao(Ponto(1.55, -10.0, -15.15)));
    world.add(pp1);

    shared_ptr<Malha> pp2 = make_shared<Malha>(cubo_obj);
    pp2->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pp2->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 0.15)));
    pp2->atualizar_pontos(matriz_translacao(Ponto(-0.5, -10.0, -15.15)));
    world.add(pp2);

    shared_ptr<Malha> pp3 = make_shared<Malha>(cubo_obj);
    pp3->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pp3->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 0.15)));
    pp3->atualizar_pontos(matriz_translacao(Ponto(1.55, -10.0, -16.5)));
    world.add(pp3);

    shared_ptr<Malha> pp4 = make_shared<Malha>(cubo_obj);
    pp4->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pp4->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 0.15)));
    pp4->atualizar_pontos(matriz_translacao(Ponto(-0.5, -10.0, -16.5)));
    world.add(pp4);

    shared_ptr<Malha> pcostas = make_shared<Malha>(cubo_obj);
    pcostas->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pcostas->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 1.0)));
    pcostas->atualizar_pontos(matriz_translacao(Ponto(1.60, -7.0, -11.75)));
    world.add(pcostas);

    shared_ptr<Malha> ptampa = make_shared<Malha>(cubo_obj, Cor(250,109,12));
    ptampa->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    ptampa->atualizar_pontos(matriz_escala(Vetor(1.0, 0.1, 1.0)));
    ptampa->atualizar_pontos(matriz_translacao(Ponto(0.35, -8.5, -11.75)));
    world.add(ptampa);
}

void construir_poste(Cenario &world, string cubo_obj) {
    shared_ptr<Cilindro> tronco = make_shared<Cilindro>(Ponto(10.0, -12.0, -15.0, 1), 0.15, Vetor(0, 1, 0), 15.0, Cor(256, 2, 2));
    world.add(tronco);

    shared_ptr<Malha> cabo = make_shared<Malha>(cubo_obj);
    cabo->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    cabo->atualizar_pontos(matriz_escala(Vetor(1.5, 0.15, 0.15)));
    cabo->atualizar_pontos(matriz_cisalhamento('x','y','y', -25));
    cabo->atualizar_pontos(matriz_translacao(Ponto(8.5, 3.5, -14.25)));
    world.add(cabo);

    shared_ptr<Malha> caixa = make_shared<Malha>(cubo_obj, Cor(88,88,88));
    caixa->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    caixa->atualizar_pontos(matriz_escala(Vetor(0.5, 0.25, 0.25)));
    caixa->atualizar_pontos(matriz_translacao(Ponto(6.6, 4.25, -14.35)));
    world.add(caixa);

    // shared_ptr<Esfera> luz = make_shared<Esfera>(Ponto(6.0, 4.15, -14.15-0.15*5, 1), 0.15, Cor(0, 256, 2));
    // world.add(luz);
}

void construir_copo_garrafa (Cenario &world, string copo_obj, string garrafa_obj) {
    shared_ptr<Malha> copo = make_shared<Malha>(copo_obj, Cor(10,215,45));
    copo->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    copo->atualizar_pontos(matriz_escala(Vetor(0.5, 0.5, 0.5)));
    // copo->atualizar_pontos(matriz_cisalhamento('x','y','y', -25));
    copo->atualizar_pontos(matriz_translacao(Ponto(-5.0, -8.0, -14.5)));
    world.add(copo);

    shared_ptr<Malha> copod = make_shared<Malha>(copo_obj, Cor(145,145,45));
    copod->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    copod->atualizar_pontos(matriz_escala(Vetor(0.5, 0.5, 0.5)));
    copod->atualizar_pontos(matriz_translacao(Ponto(-2.5, -8.0, -14.5)));
    world.add(copod);

    shared_ptr<Malha> garrafa = make_shared<Malha>(garrafa_obj, Cor(102,50,102));
    garrafa->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    garrafa->atualizar_pontos(matriz_escala(Vetor(0.5, 0.5, 0.5)));
    garrafa->atualizar_pontos(matriz_translacao(Ponto(-4.0, -8.0, -15.5)));
    world.add(garrafa);
}

void construir_escola(Cenario &world, string cubo_obj) {
    shared_ptr<Malha> base = make_shared<Malha>(cubo_obj, Cor(250,109,12));
    base->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    base->atualizar_pontos(matriz_escala(Vetor(30, 10, 10)));
    base->atualizar_pontos(matriz_translacao(Ponto(10.0, 0.0, 1.0)));
    world.add(base);
}

int main() {
    /* configuracao de arquivo */
    string path_abs = "img/img_"+data_atual()+".ppm";
    string cmd = "eog "+path_abs;

    /* configuração de janela (abertura no plano bloqueiador) 
        - quantidade vertical e Cenhorizontal de pixels
        - vertices de altura, largura e distancia focal da janela */
    int Wpix = 400, Hpix = 400;
    Ponto janela_pts(0.75, 0.75, -0.75, 1);
    // Ponto janela_pts(15.0, 15.0, -1.0, 1);

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

    construir_chao(world, "obj/cubo.obj");
    construir_paredes(world, "obj/cubo.obj");
    construir_balcao_pratileira(world, "obj/cubo.obj");
    construir_teto(world, "obj/piramide.obj");
    construir_freezer(world, "obj/cubo.obj");
    construir_arvore(world);
    construir_mesa(world, "obj/cubo.obj");
    construir_cadeira(world, "obj/cubo.obj");
    construir_cadeira2(world, "obj/cubo.obj");
    construir_poste(world, "obj/cubo.obj");
    construir_copo_garrafa(world, "obj/copo.obj", "obj/garrafa.obj");
    construir_escola(world, "obj/cubo.obj");

    // world.atualizar_pontos(matriz_rotacao(-45, 'y'));
    // world.atualizar_pontos(matriz_translacao(Ponto(-15,0,-1,1)));

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