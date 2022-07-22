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

	Ponto() {
	}
};

vector<Ponto> getVizinhos(Ponto p) {
	return {{p.c - 1, p.l}, {p.c, p.l - 1}, {p.c + 1, p.l}, {p.c, p.l + 1}};
}

void exibir(vector<vector<string>> mapa) {
	for (auto row : mapa) {
		for (auto col : row) {
			cout << col;
		}
		cout << endl;
	}
}

int main() {
	fstream file("./dadosLabirinto.txt", fstream::in);
	if (file.is_open()) {
		int numL, numC;
		string line;
		getline(file, line);
		stringstream ss(line);
		ss >> numL >> numC;

		vector<vector<string>> mapa(numL);
		stack<Ponto> caminho;

		auto itMapa = mapa.begin();
		int l = 0, c = 0;
		Ponto pInicial;
		Ponto pFinal;
		while (getline(file, line)) {
			auto mudandoPontos = [&](string &line) {
				for (auto &letter : line) {
					if (letter == 'I') {
						pInicial.l = l;
						pInicial.c = c;
						letter = ' ';
					}
					if (letter == 'F') {
						pFinal.l = l;
						pFinal.c = c;
						letter = ' ';
					}

					c++;
				}
				c = 0;
			};

			mudandoPontos(line);
			itMapa->push_back(line);
			itMapa++;

			l++;
		}
		caminho.push(pInicial);
		// acharCaminho(mapa, caminho, pInicial, pFinal);
		caminho.push(pFinal);

		while(!caminho.empty()){
			int lQueimar, cQueimar;
			lQueimar =  caminho.top().l;
			cQueimar = caminho.top().c;
			auto row = mapa[lQueimar];
			row[cQueimar] = '.';
			caminho.pop();
		}
		exibir(mapa);
	} else {
		cerr << "Falha ao abrir o arquivo." << endl;
	}

	file.close();
	return 0;
}