#include <iostream>
#include <vector>

using namespace std;

void exibirVet(vector<int> vet);

int trianguloSoma(vector<int>& vet){
    if(vet.size() == 1){
        exibirVet(vet);
        return vet[0];
    }
    auto it = vet.begin();
    int soma = *it + *(it + 1);
    it = vet.erase(it);
    //vet.insert(it, soma);
    trianguloSoma(vet);
}

int main() {
    vector<int> vet = {1, 2, 3}
    trianguloSoma(vet);

    return 0;
}
