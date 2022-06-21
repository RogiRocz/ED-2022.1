#include <iostream>
#include <list>
#include <utility>

using namespace std;

int pos_cursor(string saida, string::iterator cursor) {
	return distance(saida.begin(), cursor);
}

void mostrar(
	list<pair<string, string::iterator>> undo,
	list<pair<string, string::iterator>> redo) {
	for (auto elem : undo) {
		cout << "saida: " << elem.first
			 << " cursor: " << pos_cursor(elem.first, elem.second) << endl;
	}

	for (auto elem : redo) {
		cout << "saida: " << elem.first
			 << " cursor: " << pos_cursor(elem.first, elem.second) << endl;
	}
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
	list<pair<string, string::iterator>> undo;
	auto cursorUndo = undo.begin();
	list<pair<string, string::iterator>> redo;
	auto cursorRedo = redo.begin();

	auto inserir_palavra = [&](string &saida, string::iterator cursor, char c) {
		int j = pos_cursor(saida, cursor);
		string resto = saida.substr(j);
		saida.resize(j + 1);
		saida[j] = c;
		saida += resto;
	};

	for (int i = 0; i <= (int)line.size(); i++) {
		auto letter = line[i];
		if (caracteresAceitos(letter)) {
			// cursorUndo = cursor;
			undo.push_back(make_pair(saida, cursor));
			inserir_palavra(saida, cursor, letter);
			advance(cursor, +1);
		}
		if (letter == 'R') {
			// cursorUndo = cursor;
			undo.push_back(make_pair(saida, cursor));
			letter = '\n';
			inserir_palavra(saida, cursor, letter);
			advance(cursor, +1);
		}
		if (letter == 'B') {
			// cursorUndo = cursor;
			undo.push_back(make_pair(saida, cursor));
			if (mover_cursor_esquerda(saida, pos_cursor(saida, cursor))) {
				advance(cursor, -1);
				cursor = saida.erase(cursor);
			}
		}
		if (letter == 'D') {
			if (mover_cursor_direita(saida, pos_cursor(saida, cursor))) {
				// cursorUndo = cursor;
				undo.push_back(make_pair(saida, cursor));
				cursor = saida.erase(cursor);
			}
		}
		if (letter == '<') {
			if (mover_cursor_esquerda(saida, pos_cursor(saida, cursor))) {
				advance(cursor, -1);
			}
		}
		if (letter == '>') {
			if (mover_cursor_direita(saida, pos_cursor(saida, cursor))) {
				advance(cursor, +1);
			}
		}
		if (letter == 'Z') {
			string saidaAux = saida;
			auto cursorAux = cursor;
			saida = undo.back().first;
			cursor = undo.back().second;
			// cursorRedo = cursorAux;
			redo.push_back(make_pair(saidaAux, cursorAux));
		}
		if (letter == 'Y') {
			undo.back().first = saida;
			undo.back().second = cursor;
			cursor = redo.back().second;
			saida = redo.back().first;
			redo.clear();
		}
		mostrar(undo, redo);
	}
	inserir_palavra(saida, cursor, '|');
	return saida;
}

list<string> teste(string line) {
	list<string> t;
	for (int i = 0; i < line.size(); i++) {
		t.push_back(line);
	}
	return t;
}

void exibir(list<string> t) {
	for (auto elem : t) {
		cout << elem << endl;
	}
}

int main() {
	string line = "abcZZd";
	// cin >> line;
	cout << formatar(line) << endl;
	// exibir(teste(line));

	return 0;
}