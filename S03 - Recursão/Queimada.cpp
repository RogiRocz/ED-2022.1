#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> produzirMapa(int nc){
    
}

int main(){
    string entrada = "2 3 1 1";
    stringstream ss(entrada);
    
    int nl, nc, l, c;
    ss >> nl >> nc >> l >> c;
    
    vector<vector<int>> vet;
    for(int i = 0; i < nl; i++){
        vet[i].push_back(produzirMapa(nc));
    }
    
    
    return 0;
}
