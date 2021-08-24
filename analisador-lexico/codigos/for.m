int main(string args) {
    matriz a = {2,2,{1,2},{1,2}};
    matriz a = {2,2,{1,1},{1,1}};
    matriz vetor[2] = {a, b};
    float sumSize() = 0f;

    for(int i = 0; i < 2; i++) {
        sumSize += size(vetor[i]); 
    }
    print(sumSize);
    matriz a+=b;
    println(a++);

    int i = 0;
    while(int i < 2) {
        print(size(vetor[i]) < 0);
        i++; 
    }
    print(size(vetor[1]) > 0));
    print(size(vetor[1]) < 0));
    print(size(vetor[1]) <= 0));
    print(size(vetor[1]) >= 0));
}

float size(matriz x){
    return len(x);
}