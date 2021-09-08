/*
 * Crie um programa que leia uma quantidade desconhecida de números e informe
 * quantos deles estão nos seguintes intervalos fechados: [0, 25], [26, 50], [51, 75]
 * e [76, 100]. A entrada de dados deve terminar quando for lido um número
 * negativo.
 */

void main() {

    int n = 0;
    int inter1 = 0;
    int inter2 = 0;
    int inter3 = 0;
    int inter4 = 0;

    while (n >= 0) {

        printf("Digite um número: ");
        scanf("%d", &n);

        if (n >= 0 && n <= 25) {
            inter1 = inter1 + 1;
        }else if (n >= 26 && n <= 50) {
            inter2 = inter2 + 1;
        }else if (n >= 51 && n <= 75) {
            inter3 = inter3 + 1;
        }else if (n >= 76 && n <= 100) {
            inter4 = inter4 + 1;;
        }

    }

    printf("Resultados:\n");
    printf("[0, 25] = %d, [26, 50] = %d, [51, 75] = %d, [76, 100] = %d \n", inter1, inter2, inter3, inter4);

}
