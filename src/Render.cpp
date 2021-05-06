#include "Render.h"

void Render::tirar_fotografia(Cenario world, Cor background, string projecao) {
    auto largura = _cam.largura_imagem();
    auto altura = _cam.altura_imagem();
    auto janela_pts = _cam.janela_pontos();
    auto origem_cam = _cam.origem();
    auto ki_cam = _cam.eixo_k()*(-1);

    ofstream arq(_path_abs);

    conf_arquivo(arq, largura, altura);

    float Px, Py, Pz = janela_pts.z();
    
    auto x_min = -janela_pts.x();
    auto x_max = janela_pts.x();
    auto delta_x = (x_max-x_min)/largura;
    
    auto y_min = -janela_pts.y();
    auto y_max = janela_pts.y();
    auto delta_y = (y_max-y_min)/altura;

    auto MC = alocar(altura, largura);

    for (int h = altura-1; h >= 0; --h)
    {
        Py = y_min + delta_y/2 + h*delta_y;
        for (int w = 0; w < largura; ++w)
        {
            Px = x_min + delta_x/2 + w*delta_x;
            MC[h][w] = Ponto(Px, Py, Pz, 1);
        }
    }

    for (int j = altura-1; j >= 0; --j)
    {
        for (int i = 0; i < largura; ++i)
        {
            PontoColisao ptcol;
            Raio raio;

            if (strcmp(projecao.c_str(), "perspectiva") == 0)
                raio = criar_raio(_cam.origem(), MC[j][i]);
            else 
                raio = criar_raio_2(MC[j][i], _cam.eixo_k()*(-1), 1);
            
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

void Render::escrever_arquivo(ofstream& arq, Cor p) {
    arq << p.x() << ' ' << p.y() << ' ' << p.z() << '\n';
    /* arq << static_cast<int>ceil( (p.x()/c_max)*255 ) << ' ' << static_cast<int>ceil( (p.y()/c_max)*255 ) << ' ' << static_cast<int>ceil( (p.z()/c_max)*255 ) << '\n'; */
}

void Render::conf_arquivo(ofstream& arq, int largura, int altura) {
    arq << "P3\n" << largura << ' ' << altura << "\n255\n";
}

void Render::executar_arquivo(string cmd) {
    cout << "system(\""<< cmd.c_str() << "\");" << endl;
    system(cmd.c_str());
}

Raio Render::criar_raio(const Ponto& o, const Ponto& p) {
    return Raio(o, p);
}

Raio Render::criar_raio_2(const Ponto& o, const Vetor& d, int i) {
    return Raio(o, d, i);
}