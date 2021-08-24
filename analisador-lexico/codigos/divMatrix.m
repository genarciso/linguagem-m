int main(string args) {
    int inteiro = 5 + 5 - 3;
	float flutuante = 3.25f / 3;
	double d = 0.25 * 5;

    matriz x = {2, 2, {0, 1}, {3, 4}};
    matriz ldi = inteiro/matriz;
    matriz rdi = matriz/inteiro;
    matriz ldf = flutuante/matriz;
    matriz rdf = matriz/flutuante;
    matriz ldd = d/matriz;
    matriz rdd = matriz/d;

    if(ldi == rdi) {
        print("True");
    }

    if(ldf == rdf) {
        print("True");
    }

    if (ldd = rdd) {
        print("True");
    }
}