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

bool verificarAnt(matInt vet, Pos pos, int value, char direcao) {
	cout << "l: " << pos.l << " c: " << pos.c << " value: " << value << endl;
	switch (direcao) {
	case 'l':
		// A linha permanece a mesma a coluna varia
		if (pos.c < 0) {
			return true;
		}

		if (vet[pos.l][pos.c] == value) {
			return false;
		}

		pos.c--;

		return verificarAnt(vet, pos, value, direcao);
		break;
	case 'c':
		// A coluna permanece a mesma a linha varia
		if (pos.l < 0) {
			return true;
		}

		if (vet[pos.l][pos.c] == value) {
			return false;
		}

		pos.l--;

		return verificarAnt(vet, pos, value, direcao);
		break;
	default:
		cout << "Opcao invalida";
		break;
	}
}

bool verificarPos(matInt vet, Pos pos, int value, char direcao) {
	cout << "l: " << pos.l << " c: " << pos.c << " value: " << value << endl;
	switch (direcao) {
	case 'l':
		// A linha permanece a mesma a coluna varia
		if (pos.c == vet.size()) {
			return true;
		}

		if (vet[pos.l][pos.c] == value) {
			return false;
		}

		pos.c++;

		return verificarPos(vet, pos, value, direcao);
		break;
	case 'c':
		// A coluna permanece a mesma a linha varia
		if (pos.l == vet.size()) {
			return true;
		}

		if (vet[pos.l][pos.c] == value) {
			return false;
		}

		pos.l++;

		return verificarPos(vet, pos, value, direcao);
		break;
	default:
		cout << "Opcao invalida";
		break;
	}
}

bool verificarLinha(matInt vet, Pos pos, int value) {
	cout << "____________________" << endl;
	return verificarAnt(vet, pos, value, 'c') &&
		verificarPos(vet, pos, value, 'c');
}

bool verificarColuna(matInt vet, Pos pos, int value) {
	cout << "____________________" << endl;
	return verificarAnt(vet, pos, value, 'l') &&
		verificarPos(vet, pos, value, 'l');
}

bool verificaQuadrante(matInt vet, Pos pos, int value){
    switch(vet.size()){
        case 4:
            auto inicioQua = Pos((pos.l / 2) * 2, (pos.c / 2) * 2 );
            auto diagonalPri = vet[inicioQua.l][inicioQua.c]  == vet[inicioQua.l + 1][inicioQua.c + 1];
            auto diagonalSec = vet[inicioQua.l][inicioQua.c + 1]  == vet[inicioQua.l + 1][inicioQua.c];
            return !(diagonalPri || diagonalSec);
        break;
        case 9:
            auto inicioQua = Pos((pos.l / 3) * 3, (pos.c / 3) * 3 );
        break;
        default:
            cout << "Ué?";
        break;
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

    if(l == -1 || c == -1){return true;}

    if(i > vet.size()){return false;}

	if (verificarLinha(vet, pos, i) && verificarColuna(vet, pos, i) && verificarQuadrante(vet, pos, i)) {
		vet[l][c] = i;
        return resolver(vet, 1);
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

	resolver(vet);

	exibir(vet);

	arq.close();
	return 0;
}
