#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<vector<int>> matInt;

struct Pos{
    int l, c;
    
    Pos(int l, int c) : l(l), c(c){}
};

void exibir(matInt vet){
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

bool verificarAnt(matInt vet, Pos pos, int value, char direcao){
    switch(direcao){
        case 'l':
        // A linha permanece a mesma a coluna varia
            if(pos.c < 0){
                return true;
            }
            
            if(vet[pos.l][pos.c] == value){
                return false;
            }
            
            return verificarAnt(vet, Pos(pos.l, pos.c - 1), value, direcao);
            break;
        case 'c':
            // A coluna permanece a mesma a linha varia
            if(pos.l < 0){
                return true;
            }
            
            if(vet[pos.l][pos.c] == value){
                return false;
            }
            
            return verificarAnt(vet, Pos(pos.l - 1, pos.c), value, direcao);
            break;
        default:
            cout << "Opcao invalida";
            break;
    }
    
}

bool verificarPos(matInt vet, Pos pos, int value, char direcao){
    switch(direcao){
        case 'l':
        // A linha permanece a mesma a coluna varia
            if(pos.c == vet.size()){
                return true;
            }
            
            if(vet[pos.l][pos.c] == value){
                return false;
            }
            
            return verificarPos(vet, Pos(pos.l, pos.c + 1), value, direcao);
            break;
        case 'c':
            // A coluna permanece a mesma a linha varia
            if(pos.l == vet.size()){
                return true;
            }
            
            if(vet[pos.l][pos.c] == value){
                return false;
            }
            
            return verificarPos(vet, Pos(pos.l + 1, pos.c), value, direcao);
            break;
        default:
            cout << "Opcao invalida";
            break;
    }
}

bool verificarLinha(matInt vet, Pos pos, int value){
    return verificarAnt(vet, pos, value, 'c') &&
    verificarPos(vet, pos, value, 'c');
}

bool verificarColuna(matInt vet, Pos pos, int value){
    return verificarAnt(vet, pos, value, 'l') &&
    verificarPos(vet, pos, value, 'l');
}

int verificaQuadrante(matInt vet);

bool posValida(Pos p){
    return p.l == -1 || p.c == -1 ? false : true;
}

void resolver(matInt& vet){
    auto posVazia = [](vector<vector<int>> vet){
        for(int i = 0; i < (int)vet.size(); i++){
            for(int j = 0; j < (int)vet[0].size(); j++){
                if(vet[i][j] == 0){
                    return Pos(i, j);
                }
            }
        }
        
        return Pos(-1, -1);
    };
    
    auto pos = posVazia(vet);
    int l = pos.l, c = pos.c;
    
    if(posValida(pos)){
        for(int i = 1; i <= vet.size(); i++){
            if(verificarLinha(vet, pos, i) && 
            verificarColuna(vet, pos, i)){
                vet[l][c] = i;
            }
        }
        resolver(vet);
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
    
    resolver(vet);
    
    exibir(vet);

    return 0;
}
