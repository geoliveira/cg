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
#include "Luzes.h"
#include "Luz.h"
#include "LuzAmbiente.h"
#include "LuzDirecional.h"
#include "LuzPontual.h"
#include "LuzSpot.h"
#include "Cluster.h"

void construir_chao(Cenario &world, string obj) {
    shared_ptr<Malha> chao = make_shared<Malha>(obj, Cor(107,107,107));
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
    shared_ptr<Malha> pe = make_shared<Malha>(cubo_obj, Cor(255,222,173));
    pe->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pe->atualizar_pontos(matriz_escala(Vetor(0.25, 5, 5)));
    pe->atualizar_pontos(matriz_translacao(Ponto(0.0, -5.0, -5.0)));
    world.add(pe);

    shared_ptr<Malha> pd = make_shared<Malha>(cubo_obj, Cor(255,222,173));
    pd->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pd->atualizar_pontos(matriz_escala(Vetor(0.25, 5, 5)));
    pd->atualizar_pontos(matriz_translacao(Ponto(10.0, -5.0, -5.0)));
    world.add(pd);

    shared_ptr<Malha> pt = make_shared<Malha>(cubo_obj, Cor(222,184,135));
    pt->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pt->atualizar_pontos(matriz_escala(Vetor(0.25, 5, 5)));
    pt->atualizar_pontos(matriz_translacao(Ponto(5.0, -5.0, -10.0)));
    pt->atualizar_pontos(matriz_rotacao(90, 'y'));
    pt->atualizar_pontos(matriz_translacao(Ponto(40, 0, -30.0)));
    world.add(pt);

    shared_ptr<Malha> pf = make_shared<Malha>(cubo_obj, Cor(34,139,34));
    pf->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pf->atualizar_pontos(matriz_escala(Vetor(0.25, 2.25, 3)));
    pf->atualizar_pontos(matriz_translacao(Ponto(5.0, -5.0, -10.0)));
    pf->atualizar_pontos(matriz_rotacao(90, 'y'));
    pf->atualizar_pontos(matriz_translacao(Ponto(28.2, -2.65, -20.0)));
    world.add(pf);
}

void construir_balcao_pratileira_luz(Cenario &world, string obj) {
    shared_ptr<Malha> balcao = make_shared<Malha>(obj, Cor(173,216,230));
    balcao->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    balcao->atualizar_pontos(matriz_escala(Vetor(3.25, 0.1, 1.5)));
    balcao->atualizar_pontos(matriz_translacao(Ponto(3.45, -5.3, -16.5)));
    world.add(balcao);

    shared_ptr<Malha> pratileira = make_shared<Malha>(obj, Cor(173,216,230));
    pratileira->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pratileira->atualizar_pontos(matriz_escala(Vetor(2.5, 0.1, 1.5)));
    pratileira->atualizar_pontos(matriz_translacao(Ponto(2.75, -1.5, -26.25)));
    world.add(pratileira);

    shared_ptr<Cilindro> cabo = make_shared<Cilindro>(Ponto(5.0, -0.5, -30.0, 1), 0.15, Vetor(0, 1, 0), 0.5, Cor(47,79,79));
    world.add(cabo);

    shared_ptr<Esfera> lampada = make_shared<Esfera>(Ponto(5.025, -0.5, -30.025, 1), 0.25, Cor(255, 255, 255));
    world.add(lampada);
}

void construir_teto(Cenario &world, string obj) {
    shared_ptr<Malha> teto = make_shared<Malha>(obj, Cor(178,34,34));
    teto->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5)));
    teto->atualizar_pontos(matriz_escala(Vetor(7.5, 2.5, 7.5)));
    teto->atualizar_pontos(matriz_translacao(Ponto(5, 2.5, 7.5)));
    world.add(teto);
}

void construir_freezer(Cenario &world, string obj) {
    shared_ptr<Malha> base = make_shared<Malha>(obj, Cor(188,143,143));
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
    shared_ptr<Cilindro> tronco = make_shared<Cilindro>(Ponto(-12.5, -10.0, -20.0, 1), 1.0, Vetor(0, 1, 0), 10.0, Cor(139,69,19));
    shared_ptr<Esfera> folhas = make_shared<Esfera>(Ponto(-12.5, 0.75, -20.0, 1), 4.5, Cor(34,139,34));
    world.add(tronco);
    world.add(folhas);

    shared_ptr<Cilindro> troncop = make_shared<Cilindro>(Ponto(-10.0, -10.0, -30.0, 1), 0.35, Vetor(0, 1, 0), 3.5, Cor(139,69,19));
    world.add(troncop);

    shared_ptr<Cone> folhasp = make_shared<Cone>(Ponto(-10.0, -6.5, -30.0, 1), 1.5, Vetor(0, 1, 0), 3, Cor(34,139,34));
    world.add(folhasp);
}

void construir_mesa(Cenario &world, string cubo_obj) {
    shared_ptr<Malha> p1 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    p1->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p1->atualizar_pontos(matriz_escala(Vetor(0.25, 1.25, 0.25)));
    p1->atualizar_pontos(matriz_translacao(Ponto(-5.0, -8.75, -14.5)));
    world.add(p1);

    shared_ptr<Malha> p2 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    p2->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p2->atualizar_pontos(matriz_escala(Vetor(0.25, 1.25, 0.25)));
    p2->atualizar_pontos(matriz_translacao(Ponto(-2.5, -8.75, -14.5)));
    world.add(p2);

    shared_ptr<Malha> p3 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    p3->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p3->atualizar_pontos(matriz_escala(Vetor(0.25, 1.25, 0.25)));
    p3->atualizar_pontos(matriz_translacao(Ponto(-5.0, -8.75, -17.0)));
    world.add(p3);

    shared_ptr<Malha> p4 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    p4->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p4->atualizar_pontos(matriz_escala(Vetor(0.25, 1.25, 0.25)));
    p4->atualizar_pontos(matriz_translacao(Ponto(-2.5, -8.75, -17.0)));
    world.add(p4);

    shared_ptr<Malha> tampa = make_shared<Malha>(cubo_obj, Cor(173-15,216-15,230-15)); // Cor(165,42,42)
    tampa->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    tampa->atualizar_pontos(matriz_escala(Vetor(2.25, 0.1, 2.25)));
    tampa->atualizar_pontos(matriz_translacao(Ponto(-3.80, -7.5, -6.0)));
    world.add(tampa);
}

void construir_cadeira(Cenario &world, string cubo_obj) {
    shared_ptr<Malha> p1 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    p1->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p1->atualizar_pontos(matriz_escala(Vetor(0.15, 0.75, 0.15)));
    p1->atualizar_pontos(matriz_translacao(Ponto(-6.65, -9.25, -15.15)));
    world.add(p1);

    shared_ptr<Malha> p2 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    p2->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p2->atualizar_pontos(matriz_escala(Vetor(0.15, 0.75, 0.15)));
    p2->atualizar_pontos(matriz_translacao(Ponto(-8.5, -9.25, -15.15)));
    world.add(p2);

    shared_ptr<Malha> p3 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    p3->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p3->atualizar_pontos(matriz_escala(Vetor(0.15, 0.75, 0.15)));
    p3->atualizar_pontos(matriz_translacao(Ponto(-6.65, -9.25, -16.5)));
    world.add(p3);

    shared_ptr<Malha> p4 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    p4->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    p4->atualizar_pontos(matriz_escala(Vetor(0.15, 0.75, 0.15)));
    p4->atualizar_pontos(matriz_translacao(Ponto(-8.5, -9.25, -16.5)));
    world.add(p4);

    shared_ptr<Malha> costas = make_shared<Malha>(cubo_obj);
    costas->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    costas->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 1.0)));
    costas->atualizar_pontos(matriz_translacao(Ponto(-8.5, -7.0, -11.75)));
    world.add(costas);

    shared_ptr<Malha> tampa = make_shared<Malha>(cubo_obj);
    tampa->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    tampa->atualizar_pontos(matriz_escala(Vetor(1.0, 0.1, 1.0)));
    tampa->atualizar_pontos(matriz_translacao(Ponto(-7.5, -8.5, -11.75)));
    world.add(tampa);
}

void construir_cadeira2(Cenario &world, string cubo_obj) {
    shared_ptr<Malha> pp1 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    pp1->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pp1->atualizar_pontos(matriz_escala(Vetor(0.15, 0.75, 0.15)));
    pp1->atualizar_pontos(matriz_translacao(Ponto(1.45, -9.25, -15.15)));
    world.add(pp1);

    shared_ptr<Malha> pp2 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    pp2->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pp2->atualizar_pontos(matriz_escala(Vetor(0.15, 0.75, 0.15)));
    pp2->atualizar_pontos(matriz_translacao(Ponto(-0.5, -9.25, -15.15)));
    world.add(pp2);

    shared_ptr<Malha> pp3 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    pp3->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pp3->atualizar_pontos(matriz_escala(Vetor(0.15, 0.75, 0.15)));
    pp3->atualizar_pontos(matriz_translacao(Ponto(1.45, -9.25, -16.75)));
    world.add(pp3);

    shared_ptr<Malha> pp4 = make_shared<Malha>(cubo_obj, Cor(90,0,0));
    pp4->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pp4->atualizar_pontos(matriz_escala(Vetor(0.15, 0.75, 0.15)));
    pp4->atualizar_pontos(matriz_translacao(Ponto(-0.5, -9.25, -16.75)));
    world.add(pp4);

    shared_ptr<Malha> pcostas = make_shared<Malha>(cubo_obj);
    pcostas->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    pcostas->atualizar_pontos(matriz_escala(Vetor(0.15, 1.5, 1.0)));
    pcostas->atualizar_pontos(matriz_translacao(Ponto(1.45, -7.0, -11.75)));
    world.add(pcostas);

    shared_ptr<Malha> ptampa = make_shared<Malha>(cubo_obj);
    ptampa->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    ptampa->atualizar_pontos(matriz_escala(Vetor(1.0, 0.1, 1.0)));
    ptampa->atualizar_pontos(matriz_translacao(Ponto(0.35, -8.5, -11.75)));
    world.add(ptampa);
}

void construir_poste(Cenario &world, string cubo_obj) {
    shared_ptr<Cilindro> tronco = make_shared<Cilindro>(Ponto(12.0, -10.0, -15.0, 1), 0.15, Vetor(0, 1, 0), 15.0, Cor(47,79,79));
    world.add(tronco);

    shared_ptr<Malha> cabo = make_shared<Malha>(cubo_obj, Cor(47,79,79));
    cabo->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    cabo->atualizar_pontos(matriz_escala(Vetor(1.5, 0.15, 0.15)));
    cabo->atualizar_pontos(matriz_cisalhamento('x','y','y', -25));
    cabo->atualizar_pontos(matriz_translacao(Ponto(10.5, 3.5, -14.25)));
    world.add(cabo);

    shared_ptr<Malha> caixa = make_shared<Malha>(cubo_obj, Cor(47,79,79));
    caixa->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    caixa->atualizar_pontos(matriz_escala(Vetor(0.5, 0.25, 0.35)));
    caixa->atualizar_pontos(matriz_translacao(Ponto(8.6, 4.25, -13.25)));
    world.add(caixa);
    
    shared_ptr<Esfera> lampada = make_shared<Esfera>(Ponto(8.6, 4.10, -15.0, 1), 0.25, Cor(255, 255, 255));
    world.add(lampada);
}

void construir_copo_garrafa (Cenario &world, string copo_obj, string garrafa_obj) {
    shared_ptr<Cluster> env = make_shared<Cluster>();

    Malha copo = Malha(copo_obj, Cor(145,145,45));
    copo.atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    copo.atualizar_pontos(matriz_escala(Vetor(0.5, 0.5, 0.5)));
    copo.atualizar_pontos(matriz_translacao(Ponto(-5.0, -7.5, -14.35)));
    env->add(copo);

    Malha copod = Malha(copo_obj, Cor(145,145,45));
    copod.atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    copod.atualizar_pontos(matriz_escala(Vetor(0.5, 0.5, 0.5)));
    copod.atualizar_pontos(matriz_translacao(Ponto(-2.5, -7.5, -14.35)));
    env->add(copod);

    Malha garrafa = Malha(garrafa_obj, Cor(102,50,102));
    garrafa.atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    garrafa.atualizar_pontos(matriz_escala(Vetor(0.5, 0.5, 0.5)));
    garrafa.atualizar_pontos(matriz_translacao(Ponto(-3.85, -7.25, -15.5)));
    env->add(garrafa);
    
    env->configurar();

    world.add(env);
}

void construir_escola(Cenario &world, string cubo_obj) {
    shared_ptr<Malha> base = make_shared<Malha>(cubo_obj, Cor(255,127,80));
    base->atualizar_pontos(matriz_translacao(Ponto(0.0, 0.0, -5.0)));
    base->atualizar_pontos(matriz_escala(Vetor(30, 10, 10)));
    base->atualizar_pontos(matriz_translacao(Ponto(10.0, 0.0, 1.0)));
    world.add(base);

    shared_ptr<Esfera> lua = make_shared<Esfera>(Ponto(-20, 50, -100.0, 1), 5, Cor(255,140,0));
    world.add(lua);
}

int tipo = 1;
int girar = 0;

int main() {
    /* configuracao de arquivo */
    string path_abs = "img/img_"+data_atual()+".ppm";
    string cmd = "eog "+path_abs;

    /* configura????o de janela (abertura no plano bloqueiador) 
        - quantidade vertical e Cenhorizontal de pixels
        - vertices de altura, largura e distancia focal da janela */
    int Wpix = 400, Hpix = 400;

    Ponto janela_pts;

    if (tipo == 1) janela_pts = Ponto(0.75, 0.75, -0.75, 1);
    else  janela_pts = Ponto(15.0, 15.0, -1.0, 1);

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
    construir_balcao_pratileira_luz(world, "obj/cubo.obj");
    construir_teto(world, "obj/piramide.obj");
    construir_freezer(world, "obj/cubo.obj");
    construir_arvore(world);
    construir_mesa(world, "obj/cubo.obj");
    construir_cadeira(world, "obj/cubo.obj");
    construir_cadeira2(world, "obj/cubo.obj");
    construir_poste(world, "obj/cubo.obj");
    construir_copo_garrafa(world, "obj/copo.obj", "obj/garrafa.obj");
    construir_escola(world, "obj/cubo.obj");

    /* adicionando as luzes */
    Luzes luzes;
    luzes.add(make_shared<LuzAmbiente>(Cor(1, 1, 1)));
    luzes.add(make_shared<LuzDirecional>(Vetor(0, -1, 0), Cor(1, 1, 1)));
    luzes.add(make_shared<LuzPontual>(Ponto(-20, 50, -100.0+15, 1), Cor(0.10, 0.10, 0.10)));
    luzes.add(make_shared<LuzPontual>(Ponto(5.025, -0.95, -30.025, 1), Cor(0.15, 0.15, 0.15)));
    luzes.add(make_shared<LuzSpot>(Ponto(8.5, 3.25, -15.0, 1), Vetor(0, -1, 0), 0.05, 50, Cor(0.25, 0.25, 0.25)));
    
    if (girar == 1) {
        world.atualizar_pontos(matriz_rotacao(-45, 'y'));
        world.atualizar_pontos(matriz_translacao(Ponto(-15, 0, -5, 1)));
        luzes.atualizar_posicao(matriz_rotacao(-45, 'y'));
        luzes.atualizar_posicao(matriz_translacao(Ponto(-15, 0, -5, 1)));
    }     

    /* atualizando de coord de mundo para coor de camera */
    luzes.atualizar_posicao(cam.coord_MpC());
    world.atualizar_pontos(cam.coord_MpC());

    /* definir background do cenario e tirar fotografia
        -  modo de projecao: perspectiva ou ortografica*/
    Cor bg(255, 255, 255);
    Render render(path_abs, cmd, cam);
    if (tipo == 1) render.tirar_fotografia(world, luzes, bg, "perspectiva");
    else render.tirar_fotografia(world, luzes, bg, "ortografica");
       
    return 0;
}