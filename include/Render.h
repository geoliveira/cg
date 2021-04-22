#ifndef RENDER_H
#define RENDER_H

#include <iostream>
#include <fstream>
#include "Base.h"
#include "Camera.h"

class Render {
    public:
        Render(string path_abs, string cmd, Camera& cam) : _path_abs(path_abs), _cmd(cmd) { 
            ofstream arq(path_abs);

            conf_arquivo(arq);

            ray_casting(arq, cam);

            arq.close();
            
            executar_arquivo(cmd);
        }

        void escrever_arquivo(ofstream& arq, int ir, int ig, int ib) {
            arq << ir << ' ' << ig << ' ' << ib << '\n';
        }

        // Image RayCast(Camera camera, Scene scene, int width, int height)    
        void ray_casting(ofstream& arq, Camera cam) {
            for (int j = ALTURA-1; j >= 0; --j)
            {
                for (int i = 0; i < LARGURA; ++i)
                {
                    // Ray ray = ConstructRayThroughPixel(camera, i, j);
                    // Intersection hit = FindIntersection(ray, scene);
                    // image[i][j] = GetColor(hit);

                    auto r = double(i) / (LARGURA-1);
                    auto g = double(j) / (ALTURA-1);
                    auto b = 0.25;

                    int ir = static_cast<int>(255.999 * r);
                    int ig = static_cast<int>(255.999 * g);
                    int ib = static_cast<int>(255.999 * b);

                    escrever_arquivo(arq, ir, ig, ib);
                }
            }
        }

        void conf_arquivo(ofstream& arq) {
            arq << "P3\n" << LARGURA << ' ' << ALTURA << "\n255\n";
        }

        void executar_arquivo(string cmd) {
            cout << "system(\""<< cmd.c_str() << "\");" << endl;
            system(cmd.c_str());
        }

    private:
        string _path_abs;
        string _cmd;
};

#endif