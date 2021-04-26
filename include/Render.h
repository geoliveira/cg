#ifndef RENDER_H
#define RENDER_H

#include <iostream>
#include <fstream>
#include "Base.h"
#include "Camera.h"
#include "Esfera.h"

class Render {
    public:
        Render(string path_abs, string cmd, Camera& cam) : _path_abs(path_abs), _cmd(cmd), _cam(cam) {}

        void tirar_fotografia(Esfera world) {
            int largura = _cam.largura_imagem();
            int altura = _cam.altura_imagem();

            ofstream arq(_path_abs);

            conf_arquivo(arq, largura, altura);

            world.atualizar_pontos(_cam.coord_MpC());

            for (int j = altura-1; j >= 0; --j)
            {
                for (int i = 0; i < largura; ++i)
                {
                    auto r = double(i) / (largura-1);
                    auto g = double(j) / (altura-1);
                    auto b = 0.25;

                    int ir = static_cast<int>(255.999 * r);
                    int ig = static_cast<int>(255.999 * g);
                    int ib = static_cast<int>(255.999 * b);

                    PontoIntersec rec;

                    Raio ray(_cam.origem(), _cam.obter_ponto(j,i));
                    
                    if(world.intersectar(ray, rec))
                    {
                        // cout << "Aaaa" << endl;
                        escrever_arquivo(arq, Cor(1,1,1));
                    } else 
                    {
                        escrever_arquivo(arq, Cor(ir, ig, ib));
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