#include <iostream>
#include <vector>
#include <string>

using namespace std;

void exibir(vector<vector<int>> vet){
    for(auto row : vet){
        for(auto col : row){
            cout << col << ' ';
        }
        cout << endl;
    }
}

void entrada(vector<vector<int>>& vet, int n){
    string aux;
    int j = 0;
    for(int i = 0; i < n; i++){
        getline(cin, aux);
        for(auto elem : aux){
            int num = elem - '0';
            if(num > 0 && num <= n){
                vet[i][j] = num;
            }
            j++;
        }
        j = 0;
    }
    
    
}

int main() {
    string aux;
    size_t s;
    int n;
    
    getline(cin, aux);
    n = stoi(aux, &s);
    
    if(n != 4 && n != 9){
        cerr << "So trabalhamos com sudoku 4 x 4 ou 9 x 9";
        exit(1);
    }
    
    vector<vector<int>> vet(n, vector<int>(n, 0));
    
    // Fazer entrada para arquivo txt
    entrada(vet, n);
    
    exibir(vet);

    return 0;
}
