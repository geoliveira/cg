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

        void tirar_fotografia(Cenario world, Cor background) {
            int largura = _cam.largura_imagem();
            int altura = _cam.altura_imagem();

            ofstream arq(_path_abs);

            conf_arquivo(arq, largura, altura);

            for (int j = altura-1; j >= 0; --j)
            {
                for (int i = 0; i < largura; ++i)
                {
                    PontoColisao ptcol;

                    Raio raio(_cam.origem(), _cam.obter_ponto(j,i));
                    
                    if(world.intersectar(raio, 0, INFINITO, ptcol)) {
                        escrever_arquivo(arq, ptcol.cor);
                    } 
                    else {
                        escrever_arquivo(arq, background);
                    }
                }
            }

            arq.close();
            
            executar_arquivo(_cmd);
        }

        void escrever_arquivo(ofstream& arq, Cor p) {
            arq << p.x() << ' ' << p.y() << ' ' << p.z() << '\n';
        }

        void conf_arquivo(ofstream& arq, int largura, int altura) {
            arq << "P3\n" << largura << ' ' << altura << "\n255\n";
        }

        void executar_arquivo(string cmd) {
            cout << "system(\""<< cmd.c_str() << "\");" << endl;
            system(cmd.c_str());
        }

    private:
        string _path_abs;
        string _cmd;
        Camera _cam;
};

#endif