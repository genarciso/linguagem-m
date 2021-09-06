/*
 * Defina o tipo rational_t para representar números racionais. O tipo rational_t
 * deve ser representado como um registro (ou tipo correspondente) com campos
 * inteiros 'numerador' e 'denominador'. Em seguida, escreva os seguintes subprogramas:
 *   a) Subprograma que, dados dois parâmetros inteiros a e b, onde b é diferente de 0, retorna
 *      um valor rational_t para representar a fração a/b.
 *   b) Subprograma que, dados dois parâmetros do tipo rational_t, retorna true
 *      se eles representam o mesmo número racional ou false, em caso contrário.
 *   C) Subprogramas que retornem um valor rational_t correspondente a soma,
 *      negação, subtração, multiplicação, inverso e divisão entre valores rational_t,
 *      passados como parâmetros (um subprograma por operação).
 * No programa principal, invoque cada um dos subprogramas e imprima os resultados
 * produzidos, indicando numerador e denominador.
 * */

#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <math.h>

struct rational_t {
    int numerador, denominador;
};

struct rational_t itemA (int a, int b) {

    struct rational_t x;

    x.numerador = a;
    x.denominador = b;

    return x;
}

bool itemB (struct rational_t a, struct rational_t b) {

    if(a.numerador == b.numerador && a.denominador == b.denominador) {
        return true;
    }else {
        return false;
    }
}

float itemC_sum(struct rational_t x, struct rational_t y) {

    float sum = (x.numerador/x.denominador) + (y.numerador/y.denominador);
    return sum;
}

void itemC_negacao(struct rational_t x, struct rational_t y) {

    float negx = (-1) * (x.numerador/x.denominador);
    float negy = (-1) * (y.numerador/y.denominador);
    printf("%f %f", negx, negy);
}

float itemC_sub(struct rational_t x, struct rational_t y) {

    float sub = (x.numerador/x.denominador) - (y.numerador/y.denominador);
    return sub;
}

float itemC_mult(struct rational_t x, struct rational_t y) {

    float mult = (x.numerador/x.denominador) * (y.numerador/y.denominador);
    return mult;
}

void itemC_inv(struct rational_t x, struct rational_t y) {

    float inv1 = pow(-1, (x.numerador/x.denominador));
    float inv2 = pow(-1, (y.numerador/y.denominador));
    printf("%f %f \n", inv1, inv2);
}

float itemC_div(struct rational_t x, struct rational_t y) {

    float div = (x.numerador/x.denominador) / (y.numerador/y.denominador);
    return div;
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    struct rational_t x;
    struct rational_t y;

    printf("Digite os valores do numerador 1 e denominador 1, respectivamente, separados por espaço: ");
    scanf("%d%d", &x.numerador, &x.denominador);

    while (x.denominador = 0) {
        printf("Valor de denominador inválido. Digite novamente: ");
        scanf("%d", &x.denominador);
    }

    printf("Digite os valores do numerador 2 e denominador 2, respectivamente, separados por espaço: ");
    scanf("%d%d", &y.numerador, &y.denominador);

    while (y.denominador = 0) {
        printf("Valor de denominador inválido. Digite novamente: ");
        scanf("%d", &y.denominador);
    }

    struct rational_t rta = itemA(3,2);
    bool rtb = itemB(x, y);
    float rtc1 = itemC_sum(x,y);
    float rtc3 = itemC_sub(x,y);
    float rtc4 = itemC_mult(x,y);
    float rtc6 = itemC_div(x,y);


    printf("Resultados: \n");

    printf("A) %d/%d \n", rta.numerador, rta.denominador);
    printf("B) %d \n", rtb);
    printf("C) Sum %f | Sub %f | Mult %f | Div %f \n", rtc1, rtc3, rtc4, rtc6);
    itemC_negacao(x,y);
    itemC_inv(x,y);

    return 0;

}
