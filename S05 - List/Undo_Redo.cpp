#include <iostream>
#include <list>
#include <utility>

using namespace std;

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

	cursorUndo = pos_cursor();
	undo.push_back(make_pair(saida, cursorUndo));

	for (int i = 0; i <= (int)line.size(); i++) {
		auto letter = line[i];
		if (caracteresAceitos(letter)) {
			inserir_palavra(saida, cursor, letter);
			advance(cursor, +1);
			cursorUndo = pos_cursor();
			undo.push_back(make_pair(saida, cursorUndo));
			redo.clear();
		}
		if (letter == 'R') {
			letter = '\n';
			inserir_palavra(saida, cursor, letter);
			advance(cursor, +1);
			cursorUndo = pos_cursor();
			undo.push_back(make_pair(saida, cursorUndo));
			redo.clear();
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
			if ((int)undo.size() != 1) {
				string saidaAux = saida;
				int cursorAux = pos_cursor();
				undo.pop_back();
				saida = undo.back().first;
				advance(cursor, -1 * pos_cursor());
				advance(cursor, undo.back().second);
				redo.push_back(make_pair(saidaAux, cursorAux));
			}
		}
		if (letter == 'Y') {
			if ((int)redo.size() != 0) {
				saida = redo.back().first;
				advance(cursor, -1 * pos_cursor());
				advance(cursor, redo.back().second);
				undo.push_back(make_pair(saida, pos_cursor()));
				redo.pop_back();
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