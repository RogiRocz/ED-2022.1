#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<int>> matInt;

struct Pos {
	int l, c;

	Pos(int l, int c) : l(l), c(c) {
	}
};

void exibir(matInt vet) {
	for (auto row : vet) {
		for (auto col : row) {
			cout << col << ' ';
		}
		cout << endl;
	}
}

void entrada(matInt &vet, fstream &arq) {
	string aux;
	int j = 0;
	for (int i = 0; i < vet.size(); i++) {
		getline(arq, aux);
		for (auto elem : aux) {
			int num = elem - '0';
			if (num > 0 && num <= (int)vet.size()) {
				vet[i][j] = num;
			}
			j++;
		}
		j = 0;
	}
}

bool verificarLinha(matInt vet, int row, int value, int limQua = 0) {
	if (limQua == 0) {
		for (int i = 0; i < (int)vet.size(); i++) {
			if (vet[row][i] == value) {
				return false;
			}
		}
	} else {
		for (int i = 0; i < limQua; i++) {
			if (vet[row][i] == value) {
				return false;
			}
		}
	}

	return true;
}

bool verificarColuna(matInt vet, int col, int value, int limQua = 0) {
	if (limQua == 0) {
		for (int i = 0; i < (int)vet.size(); i++) {
			if (vet[i][col] == value) {
				return false;
			}
		}
	} else {
		for (int i = 0; i < limQua; i++) {
			if (vet[i][col] == value) {
				return false;
			}
		}
	}

	return true;
}

bool verificarQuadrante(matInt vet, Pos pos, int value) {
	if (vet.size() == 4) {
		auto inicioQua = Pos((pos.l / 2) * 2, (pos.c / 2) * 2);
		for (int i = 0; i < 2; i++) {
			if (!(verificarLinha(vet, inicioQua.l + i, value, 2) &&
				  verificarColuna(vet, inicioQua.c + i, value, 2))) {
				return false;
			}
		}

		return true;
	} else {
		auto inicioQua = Pos((pos.l / 3) * 3, (pos.c / 3) * 3);
		for (int i = 0; i < 3; i++) {
			if (!(verificarLinha(vet, inicioQua.l + i, value, 3) &&
				  verificarColuna(vet, inicioQua.c + i, value, 3))) {
				return false;
			}
		}

		return true;
	}

	return false;
}

Pos posVazia(matInt vet) {
	for (int i = 0; i < (int)vet.size(); i++) {
		for (int j = 0; j < (int)vet[0].size(); j++) {
			if (vet[i][j] == 0) {
				return Pos(i, j);
			}
		}
	}

	return Pos(-1, -1);
}

bool resolver(matInt &vet, int i = 1) {
	auto pos = posVazia(vet);
	int l = pos.l, c = pos.c;

	if (l == -1 || c == -1) {
		return true;
	}

	if (i > vet.size()) {
		return false;
	}

	cout << "i :" << i << " l: " << l << " c: " << c << endl;
	if (verificarLinha(vet, l, i) && verificarColuna(vet, c, i) &&
		verificarQuadrante(vet, pos, i)) {
		vet[l][c] = i;
		exibir(vet);
		cout << endl;
		return resolver(vet);
	}

	resolver(vet, ++i);
}

int main() {
	string aux;
	size_t s;
	int n;

	fstream arq("dadosSudoku.txt", fstream::in);
	getline(arq, aux);
	n = stoi(aux, &s);

	if (n != 4 && n != 9) {
		cerr << "So trabalhamos com sudoku 4 x 4 ou 9 x 9";
		exit(1);
	}

	matInt vet(n, vector<int>(n, 0));

	// Fazer entrada para arquivo txt
	entrada(vet, arq);

	exibir(vet);
	cout << endl;

	resolver(vet);

	exibir(vet);

	arq.close();
	return 0;
}