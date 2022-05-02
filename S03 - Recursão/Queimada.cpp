#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>
#include <algorithm>

enum Tipo_terreno{
    ARVORE,
    VAZIO,
};

// enum Tipo_terreno{
//     ARVORE,
//     VAZIO,
//     QUEIMADO
// };

using namespace std;

vector<char> produzirMapa(int nc, int dif){
    srand(time(NULL) + dif);
    vector<char> coluna(nc);
    for (auto &elem : coluna)
    {
        int numRandomico = rand() % 2;
        Tipo_terreno tipo = (Tipo_terreno)numRandomico;
        switch (tipo)
        {
        case ARVORE:
            elem = '#';
            break;
        case VAZIO:
            elem = '.';
            break;
        default:
            elem = '^';
            break;
        }
        // cout << "Tipo: " << (char)tipo << endl;
        // elem = tipo;
    }
    

    // random_shuffle(coluna.begin(), coluna.end());

    return coluna;
}

int main(){
    string entrada = "5 5 1 1";
    stringstream ss(entrada);
    
    int nl, nc, l, c;
    ss >> nl >> nc >> l >> c;
    
    
    vector<vector<char>> vet(nl);
    for (int i = 0; i < nc; i++)
    {
        vet[i] = produzirMapa(nc, i);
    }
    
    for (auto row : vet)
    {
        for (auto col : row)
        {
            cout << col << ' ';
        }
        cout << endl;        
    }
    
    
    
    
    return 0;
}
