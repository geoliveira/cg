#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Vetor.h"
#include "Base.h"


int main() {
    string path_abs = "img/img_"+data_atual()+".ppm";
    string cmd = "eog "+path_abs;

    ofstream arq(path_abs);

    const int largura = 256;
    const int altura = 256;

    arq << "P3\n" << largura << ' ' << altura << "\n255\n";

    for (int j = altura-1; j >= 0; --j) {
        for (int i = 0; i < largura; ++i) {
            auto r = double(i) / (largura-1);
            auto g = double(j) / (altura-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            arq << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    
    arq.close();
    cout << "system(\""<< cmd.c_str() << "\");" << endl;
    system(cmd.c_str());
       
    return 0;
}