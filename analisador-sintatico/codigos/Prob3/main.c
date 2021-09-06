/*
 * Crie um programa que leia duas matrizes numéricas e, quando possível, imprima
 * a soma e o produto dessas matrizes. Caso uma operação não possa ser realizada
 * para as matrizes lidas, imprima uma mensagem informando da impossibilidade.
 * */

#include <stdio.h>

int main() {

    matriz a = {2, 2, {0, 1}, {3, 4}};
    matriz b = {2, 2, {0, 1}, {3, 4}};
    matriz c = a+b;
    matriz d = b+a;
    matriz mult = b*a;

    if(c == d && d == c) {
        printf("True");
    }else {
        printf("False");
    }

    if(b*a == mult) {
        printf("True");
    }else {
        printf("False");
    }

    return 0;
}
