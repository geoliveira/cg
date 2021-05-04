#ifndef MALHA_H
#define MALHA_H

#include "Base.h"
#include "Matriz.h"
#include "Triangulo.h"

#include <memory>
#include <vector>

using std::vector;

class Malha : public Objeto {
    public:
        Malha() {}

        Malha(string arquivo_obj) {
            FILE *arq;
            char linha[90];
            int nf = 0;

            if((arq = fopen(arquivo_obj.c_str(), "r")) == NULL) return;

            while (!feof(arq))
            {
                fscanf(arq, "%s", linha);

                if(strcmp(linha, "v") == 0) {
                    float x, y, z;
                    fscanf(arq, "%f %f %f\n", &x, &y, &z);
                    adicionar_vertice(Ponto(x, y, z, 1));
                }
                else if(strcmp(linha, "f") == 0) {
                    int iv1, iv2, iv3;
                    fscanf(arq, "%d %d %d\n", &iv1, &iv2, &iv3);
                    if (nf < 2)
                        adicionar_face(Triangulo(_vertices[iv1-1], _vertices[iv2-1], _vertices[iv3-1], Cor(30*iv1, 0*iv2, 0*iv3)));
                    else if (nf < 4)
                        adicionar_face(Triangulo(_vertices[iv1-1], _vertices[iv2-1], _vertices[iv3-1], Cor(0*iv1, 30*iv2, 0*iv3)));
                    else if (nf < 6)
                        adicionar_face(Triangulo(_vertices[iv1-1], _vertices[iv2-1], _vertices[iv3-1], Cor(0*iv1, 0*iv2, 30*iv3)));
                    else if (nf < 8)
                        adicionar_face(Triangulo(_vertices[iv1-1], _vertices[iv2-1], _vertices[iv3-1], Cor(30*iv1, 10*iv2, 30*iv3)));
                    else if (nf < 10)
                        adicionar_face(Triangulo(_vertices[iv1-1], _vertices[iv2-1], _vertices[iv3-1], Cor(10*iv1, 30*iv2, 10*iv3)));
                    else
                        adicionar_face(Triangulo(_vertices[iv1-1], _vertices[iv2-1], _vertices[iv3-1], Cor(30*iv1, 30*iv2, 30*iv3)));
                    nf++;
                    // auto um = (iv1 > 255) ? 255 : (iv1-1);
                    // auto dois = (iv2 > 255) ? 255 : (iv2-1);
                    // auto tres = (iv3 > 255) ? 255 : (iv3-1);
                    // adicionar_face(Triangulo(_vertices[iv1-1], _vertices[iv2-1], _vertices[iv3-1], Cor(um, dois, tres)));
                    adicionar_face(Triangulo(_vertices[iv1-1], _vertices[iv2-1], _vertices[iv3-1]));
                }
            }

            fclose(arq);
        }

        Malha(string arquivo_obj, Cor c) {
            FILE *arq;
            char linha[90];

            if((arq = fopen(arquivo_obj.c_str(), "r")) == NULL) return;

            while (!feof(arq))
            {
                fscanf(arq, "%s", linha);

                if(strcmp(linha, "v") == 0) {
                    float x, y, z;
                    fscanf(arq, "%f %f %f\n", &x, &y, &z);
                    adicionar_vertice(Ponto(x, y, z, 1));
                }
                else if(strcmp(linha, "f") == 0) {
                    int iv1, iv2, iv3;
                    fscanf(arq, "%d %d %d\n", &iv1, &iv2, &iv3);
                    adicionar_face(Triangulo(_vertices[iv1-1], _vertices[iv2-1], _vertices[iv3-1], c));
                }
            }

            fclose(arq);
        }

        Malha(Ponto v0, Ponto v1, Ponto v2, Ponto v3,
              Ponto v4, Ponto v5, Ponto v6, Ponto v7) {
            adicionar_vertice(v0);
            adicionar_vertice(v1);
            adicionar_vertice(v2);
            adicionar_vertice(v3);
            adicionar_vertice(v4);
            adicionar_vertice(v5);
            adicionar_vertice(v6);
            adicionar_vertice(v7);
            adicionar_face(Triangulo(_vertices[4], _vertices[2], _vertices[0]));
            adicionar_face(Triangulo(_vertices[2], _vertices[7], _vertices[3]));
            adicionar_face(Triangulo(_vertices[6], _vertices[5], _vertices[7]));
            adicionar_face(Triangulo(_vertices[1], _vertices[7], _vertices[5]));
            adicionar_face(Triangulo(_vertices[0], _vertices[3], _vertices[1]));
            adicionar_face(Triangulo(_vertices[4], _vertices[1], _vertices[5]));
            adicionar_face(Triangulo(_vertices[4], _vertices[6], _vertices[2]));
            adicionar_face(Triangulo(_vertices[2], _vertices[6], _vertices[7]));
            adicionar_face(Triangulo(_vertices[6], _vertices[4], _vertices[5]));
            adicionar_face(Triangulo(_vertices[1], _vertices[3], _vertices[7]));
            adicionar_face(Triangulo(_vertices[0], _vertices[2], _vertices[3]));
            adicionar_face(Triangulo(_vertices[4], _vertices[0], _vertices[1]));
        }

        virtual bool intersectar(const Raio& r, float t_min, float t_max, PontoColisao& ptcol) const override;

        virtual void atualizar_pontos(const Matriz &CpM) override;

        void adicionar_vertice(Ponto v) { _vertices.push_back(v); }

        void adicionar_face(Triangulo f) { _faces.push_back(f); }

        void clear() { _vertices.clear(); _faces.clear(); }

    public:
        vector<Ponto> _vertices;
        vector<Triangulo> _faces;
};

#endif