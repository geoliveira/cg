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

            if((arq = fopen(arquivo_obj.c_str(), "r")) == NULL) return;

            while (!feof(arq))
            {
                fscanf(arq, "%s", linha);

                if(strcmp(linha, "v") == 0) 
                {
                    float x, y, z;
                    fscanf(arq, "%f %f %f\n", &x, &y, &z);
                    adicionar_vertice(Ponto(x, y, z, 1));
                }
                else if(strcmp(linha, "f") == 0) {
                    int iv1, iv2, iv3;
                    fscanf(arq, "%d %d %d\n", &iv1, &iv2, &iv3);
                    adicionar_face(Triangulo(_vertices[iv1-1], _vertices[iv2-1], _vertices[iv3-1], Cor(16*iv1, 20*iv2, 24*iv3)));
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