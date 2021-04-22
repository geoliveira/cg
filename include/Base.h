#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <string.h>

using namespace std;

/**
 * @brief obtem data e hora atual
*/
string data_atual();

/**
 * @brief funcao para conveter graus em radianos
*/
float graus_em_radianos(float grau);

/* valores iguais em janela de projecao e viewport */
#define LARGURA 400
#define ALTURA 400
#define PI 3.1415926535897932385

#include "Vetor.h"
#include "Raio.h"

#endif