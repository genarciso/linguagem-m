#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main() {
	double n = 0;
int inter1 = 0;
int inter2 = 0;
int inter3 = 0;
int inter4 = 0;
n = 11.100000 + 11;
loopStart0: if(!(n >= 0)) {
	goto loopEnd0;
}
	{
	printf("Digite um número: ");
scanf("%d", &n);
if(n >= 0 && n <= 25){
	inter1 = inter1 + 1;
} 
else if(n >= 26 && n <= 50){
	inter2 = inter2 + 1;
} 
else if(n >= 51 && n <= 75){
	inter3 = inter3 + 1;
} 
else if(n >= 76 && n <= 100){
	inter4 = inter4 + 1;
} 
else{
	printf("Intervalo não encontrado\n");
}
}
	goto loopStart0;
loopEnd0:;

printf("Resultados:\n");
printf("[0, 25] = %d, [26, 50] = %d, [51, 75] = %d, [76, 100] = %d \n", inter1,inter2,inter3,inter4);
}

