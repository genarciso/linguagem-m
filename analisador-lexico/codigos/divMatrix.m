int main(string args) {
    int inteiro = 5 + 5 - 3;
	float flutuante = 3.25f / 3;
	double d = 0.25 * 5;

    matrix x = {2, 2, {0, 1}, {3, 4}};
    matrix ldi = inteiro/matrix;
    matrix rdi = matrix/inteiro;
    matrix ldf = flutuante/matrix;
    matrix rdf = matrix/flutuante;
    matrix ldd = d/matrix;
    matrix rdd = matrix/d;

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