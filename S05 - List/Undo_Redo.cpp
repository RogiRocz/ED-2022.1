#include <iostream>
#include <list>
#include <utility>

using namespace std;

void mostrar(list<pair<string, int>> undo, list<pair<string, int>> redo) {
	for (auto elem : undo) {
		cout << "saida: " << elem.first << " cursor: " << elem.second << endl;
	}

	for (auto elem : redo) {
		cout << "saida: " << elem.first << " cursor: " << elem.second << endl;
	}

	cout << endl;
}

bool caracteresAceitos(char c) {
	if ((c >= 'a' && c <= 'z') || c == '-') {
		return true;
	}
	return false;
}

bool mover_cursor_esquerda(string saida, int pos_cursor) {
	return pos_cursor - 1 >= 0;
}

bool mover_cursor_direita(string saida, int pos_cursor) {
	return pos_cursor + 1 <= saida.size();
}

string formatar(string line) {
	string saida;
	auto cursor = saida.begin();
	list<pair<string, int>> undo;
	int cursorUndo;
	list<pair<string, int>> redo;
	int cursorRedo;

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
			cursorUndo = pos_cursor();
			undo.push_back(make_pair(saida, cursorUndo));
			inserir_palavra(saida, cursor, letter);
			advance(cursor, +1);
		}
		if (letter == 'R') {
			cursorUndo = pos_cursor();
			undo.push_back(make_pair(saida, cursorUndo));
			letter = '\n';
			inserir_palavra(saida, cursor, letter);
			advance(cursor, +1);
		}
		if (letter == 'B') {
			cursorUndo = pos_cursor();
			undo.push_back(make_pair(saida, cursorUndo));
			if (mover_cursor_esquerda(saida, pos_cursor())) {
				advance(cursor, -1);
				cursor = saida.erase(cursor);
			}
		}
		if (letter == 'D') {
			if (mover_cursor_direita(saida, pos_cursor())) {
				cursorUndo = pos_cursor();
				undo.push_back(make_pair(saida, cursorUndo));
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
		if (letter == 'Z') {
			string saidaAux = saida;
			auto cursorAux = pos_cursor();
			saida = undo.back().first;
			advance(cursor, undo.back().second);
			// cursorRedo = cursorAux;
			redo.push_back(make_pair(saidaAux, cursorAux));
		}
		if (letter == 'Y') {
			saida = redo.back().first;
			advance(cursor, redo.back().second);
			undo.back().first = saida;
			undo.back().second = pos_cursor();
			redo.clear();
		}
		mostrar(undo, redo);
	}
	inserir_palavra(saida, cursor, '|');
	return saida;
}

list<string> teste(string line);

void exibir(list<string> t) {
	for (auto elem : t) {
		cout << elem << endl;
	}
}

int main() {
	string line = "abcZZd";
	// cin >> line;
	cout << formatar(line) << endl;
	// teste(line);

	return 0;
}