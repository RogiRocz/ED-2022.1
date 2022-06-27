#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

struct Ponto {
	int l, c;
	Ponto(int l, int c) : l(l), c(c) {
	}
};

void exibir(vector<string> map) {
	for (auto linha : map) {
		cout << linha << endl;
	}
}

vector<string> produzirMapa(int numL, int numC, fstream *file) {
	vector<string> result(numL, "");
	for (int i = 0; i < numL; i++) {
		string line;
		getline(*file, line);
		stringstream ss(line);
		for (int j = 0; j < numC; j++) {
			string terreno;
			ss >> terreno;
			result[i].push_back(*(terreno.begin() + j));
		}
	}
	return result;
}

vector<Ponto> pegarVizinhos(Ponto p) {
	return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

bool dentro(vector<string> map, Ponto p) {
	int limiteL = map.size(), limiteC = map[0].size();
	if ((p.l < 0 || p.l >= limiteL) || (p.c < 0 || p.c >= limiteC)) {
		return false;
	}

	return true;
}

bool ehArvore(vector<string> map, Ponto p) {
	return map[p.l][p.c] == '#';
}

void possiveisIncediaveis(
	vector<string> &map,
	Ponto p,
	stack<Ponto> &incendiaveis) {
	for (auto viz : pegarVizinhos(p)) {
		if (dentro(map, viz) && ehArvore(map, viz)) {
			incendiaveis.push(viz);
			map[viz.l][viz.c] = '*';
			possiveisIncediaveis(map, viz, incendiaveis);
		}
	}
}

void queimar(vector<string> &map, Ponto p) {
	stack<Ponto> incendiaveis;
	bool temVizinhos = true;
	auto aux = p;

	incendiaveis.push(p);
	map[p.l][p.c] = '*';

	possiveisIncediaveis(map, p, incendiaveis);

	auto fogo = [&map](Ponto *q) { map[q->l][q->c] = 'o'; };

	for (size_t i = 0; i < incendiaveis.size(); i++) {
		cout << incendiaveis.size() << endl;
		exibir(map);
		auto ponto = incendiaveis.top();
		map[ponto.l][ponto.c] = 'o';
		incendiaveis.pop();
	}

	
}

int main() {
	fstream file("dadosBurn.txt", fstream::in);
	if (file.is_open()) {
		string line;
		int numL, numC;
		int l, c;

		getline(file, line);
		stringstream ss(line);
		ss >> numL >> numC;
		ss >> l >> c;
		Ponto pontoInicial(l, c);

		vector<string> map = produzirMapa(numL, numC, &file);

		queimar(map, pontoInicial);

		exibir(map);
	}

	file.close();
	return 0;
}