#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>
#include <algorithm>

enum Tipo_terreno{
    ARVORE,
    VAZIO,
    QUEIMADO
};

using namespace std;

vector<char> produzirMapa(int nc){
    srand(time(NULL));
    vector<char> coluna(nc);
    for (auto &elem : coluna)
    {
        int numRandomico = rand() % 3;
        Tipo_terreno tipo = (Tipo_terreno)numRandomico;
        switch (numRandomico)
        {
        case 0:
            elem = '#';
            break;
        case 1:
            elem = '.';
            break;
            case 2:
            elem = 'o';
            break;
        default:
            break;
        }
        // cout << "Tipo: " << (char)tipo << endl;
        // elem = tipo;
    }
    

    // random_shuffle(coluna.begin(), coluna.end());

    return coluna;
}

int main(){
    string entrada = "2 3 1 1";
    stringstream ss(entrada);
    
    int nl, nc, l, c;
    ss >> nl >> nc >> l >> c;
    
    
    vector<vector<char>> vet(nl);
    for (auto it = vet.begin(); it != vet.end(); it++)
    {
        *it = produzirMapa(nc);
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
