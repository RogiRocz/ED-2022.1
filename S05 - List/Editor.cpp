#include <iostream>
#include <iterator>
#include <list>

using namespace std;

string formatar(string line) {
	string saida;
	auto cursor = saida.begin();

	auto caracteresAceitos = [](char c) {
		if ((c >= 'a' && c <= 'z') || c == '-') {
			return true;
		}
		return false;
	};

	auto mover_cursor_esquerda = [](string saida, int pos_cursor) {
		return pos_cursor - 1 >= 0;
	};

	auto mover_cursor_direita = [](string saida, int pos_cursor) {
		return pos_cursor + 1 <= saida.size();
	};

	auto pos_cursor = [&]() { return distance(saida.begin(), cursor); };

	auto inserir_palavra = [&](string &saida, string::iterator cursor, char c) {
		int j = pos_cursor();
		string resto = saida.substr(j);
		saida.resize(j + 1);
		saida[j] = c;
		saida += resto;
	};

	for (int i = 0; i <= (int)line.size(); i++) {
		auto letter = line[i];
		if (caracteresAceitos(letter)) {
			inserir_palavra(saida, cursor, letter);
			advance(cursor, +1);
		}
		if (letter == 'R') {
			letter = '\n';
			inserir_palavra(saida, cursor, letter);
			advance(cursor, +1);
		}
		if (letter == 'B') {
			if (mover_cursor_esquerda(saida, pos_cursor())) {
				advance(cursor, -1);
				cursor = saida.erase(cursor);
			}
		}
		if (letter == 'D') {
			if (mover_cursor_direita(saida, pos_cursor())) {
				cursor = saida.erase(cursor);
			}
		}
		if (letter == '<') {
			if (mover_cursor_esquerda(saida, pos_cursor())) {
				advance(cursor, -1);
			}
		}
		if (letter == '>') {
			if (mover_cursor_direita(saida, pos_cursor())) {
				advance(cursor, +1);
			}
		}
	}
	inserir_palavra(saida, cursor, '|');
	return saida;
}

int main() {
	string line;
	cin >> line;
	cout << formatar(line) << endl;

	return 0;
}