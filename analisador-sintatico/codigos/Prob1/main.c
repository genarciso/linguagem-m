/*
 * Crie um programa que, dados três valores numéricos x, y e c, onde x e y são
 * números racionais e c é um número inteiro, previamente armazenados no código fonte,
 * avalia a expressão x2 − y + c e imprime seu resultado na tela.
 * */

#include <stdio.h>
#include <locale.h>
#include "math.h"

int main() {

    setlocale(LC_ALL, "Portuguese");

    float x = 3.5 , y = 6.5;
    int c = 10;

    float exp = pow(x, 2) - y + c;

    printf("Resultado da Expressão: %f\n", exp);

    return 0;
}
