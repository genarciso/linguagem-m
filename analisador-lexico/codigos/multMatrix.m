int main(string args) {
    int inteiro = 5 + 5 - 3;
	float flutuante = 3.25f / 3;
	double d = 0.25 * 5;

    matriz x = {2, 2, {0, 1}, {3, 4}};
    matriz lmi = inteiro*matriz;
    matriz rmi = matriz*inteiro;
    matriz lmf = flutuante*matriz;
    matriz rmf = matriz*flutuante;
    matriz lmd = d*matriz;
    matriz rmd = matriz*d;

    if(lmi == rmi) {
        print("True");
    }

    if(lmf == rmf) {
        print("True");
    }

    if (lmd = rmd) {
        print("True");
    }
}