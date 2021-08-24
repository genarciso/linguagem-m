int main(string args) {
    matriz a = {2, 2, {0, 1}, {3, 4}};
    matriz b = {2, 2, {0, 1}, {3, 4}};
    matriz c = a+b;
    matriz d = b+a;

    if(c == d && d == c){
        print("True");
    }
}