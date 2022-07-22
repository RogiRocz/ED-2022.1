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

	string to_string(){
		stringstream ss;
		ss << "Ponto l: " << l << " c: " << c;
		return ss.str();
	}
};

vector<Ponto> getVizinhos(Ponto p) {
	return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

void exibir(vector<string> mapa) {
	for (auto row : mapa) {
		for (auto col : row) {
			cout << col;
		}
		cout << endl;
	}
}

bool acharCaminho(vector<string> &mapa, stack<Ponto> &caminho, Ponto pInicial, Ponto pFinal){
	int row = pInicial.l;
	int col = pInicial.c;

	if(mapa[row][col] != ' '){return false;}

	if(row == pFinal.l && col == pFinal.c){return true;}

	mapa[row][col] = '*';
	
	for(auto viz : getVizinhos(pInicial)){
		if(acharCaminho(mapa, caminho, viz, pFinal)){
			caminho.push(viz);
			return true;
		}
	}

	mapa[row][col] = ' ';
	return false;
}

int main() {
	fstream file("./dadosLabirinto.txt", fstream::in);
	if (file.is_open()) {
		int numL, numC;
		string line;
		getline(file, line);
		stringstream ss(line);
		ss >> numL >> numC;

		vector<string> mapa(numL);
		stack<Ponto> caminho;

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
			mapa[l] = line;

			l++;
		}
		acharCaminho(mapa, caminho, pInicial, pFinal);
		caminho.push(pInicial);

		while(!caminho.empty()){
			auto lQueimar = caminho.top().l;
			auto cQueimar = caminho.top().c;
			mapa[lQueimar][cQueimar] = '.';
			caminho.pop();
		}
		exibir(mapa);
	} else {
		cerr << "Falha ao abrir o arquivo." << endl;
	}

	file.close();
	return 0;
}