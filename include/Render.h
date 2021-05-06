#ifndef RENDER_H
#define RENDER_H

#include <iostream>
#include <fstream>
#include "Base.h"
#include "Camera.h"
#include "Matriz.h"
#include "Esfera.h"
#include "Cenario.h"

class Render {
    public:
        Render(string path_abs, string cmd, Camera& cam) : _path_abs(path_abs), _cmd(cmd), _cam(cam) {}

        void tirar_fotografia(Cenario world, Cor background, string projecao);

        void escrever_arquivo(ofstream& arq, Cor p);

        void conf_arquivo(ofstream& arq, int largura, int altura);

        void executar_arquivo(string cmd);

        Raio criar_raio(const Ponto& o, const Ponto& p);

        Raio criar_raio_2(const Ponto& o, const Vetor& d, int i);

    private:
        string _path_abs;
        string _cmd;
        Camera _cam;
};

#endif