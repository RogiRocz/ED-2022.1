#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

struct Ponto {
	int l;
	int c;

	Ponto(int l, int c) : l(l), c(c) {
	}
};

vector<Ponto> getVizinhos(Ponto p) {
	return {{p.c - 1, p.l}, {p.c, p.l - 1}, {p.c + 1, p.l}, {p.c, p.l + 1}};
}

void exibir (vector<vector<string>> mapa){
	for(auto row : mapa){
		cout << row << endl;		
	}
}

int main() {
	vector<vector<string>> mapa;
	fstream file("./dadosLabirinto.txt", fstream::in);
	if (file.is_open()) {
		int numL, numC;
		string line;
		getline(file, line);
		stringstream ss(line);
		ss >> numL >> numC;
		auto itMapa = mapa.begin();
		while(getline(file, line)){
			*itMapa = line;
			itMapa++;
		}
		exibir(mapa);
	} else {
		cerr << "Falha ao abrir o arquivo." << endl;
	}

	file.close();
	return 0;
}