int main(string args) {
    matrix a = {2, 2, {0, 1}, {3, 4}};
    matrix b = {2, 2, {0, 1}, {3, 4}};
    matrix c = a-b;
    matriz d = b-a;

    if(c == d || d == c) {
        print("True");
    }
}