int main(string args) {
    int inteiro = 5 + 5 - 3;
	float flutuante = 3.25f / 3;
	double d = 0.25 * 5;

    matriz x = {2, 2, {0, 1}, {3, 4}}
    matriz y = {2, 2, {0, 1}, {3, 4}}
    matriz mult = x*y;

    if(y*x == mult) {
        print("True");
    } 
}