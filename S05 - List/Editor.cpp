#include <iostream>
#include <list>

using namespace std;

void cadaCaracter(string line) {
	for (int i = 0; i <= (int)line.size(); i++) {
		cout << "'" << line[i] << "'" << endl;
	}
}

bool caracteresAceitos(char c) {
	if ((c >= 'a' && c <= 'z') || c == '-') {
		return true;
	}
	return false;
}

string formatar(string line) {
	string saida;
	auto cursor = saida.begin();

	auto mover_cursor_esquerda = [](string saida, string::iterator cursor) {
		return (cursor - 1) != begin(saida);
	};

	auto mover_cursor_direita = [](string saida, string::iterator cursor) {
		return (cursor + 1) != end(saida);
	};

	for (int i = 0; i <= (int)line.size(); i++) {
		auto letter = line[i];
		if (caracteresAceitos(letter)) {
			saida += letter;
		}
		if (letter == 'R') {
			letter = '\n';
			saida += letter;
		}
		if (letter == 'B') {
			if (mover_cursor_esquerda(saida, cursor)) {
				cursor--;
				cursor = saida.erase(cursor);
			}
		}
		if (letter == 'D') {
			if (mover_cursor_direita(saida, cursor)) {
				i++;
			}
		}
		// if (letter == '<') {
		// 	if (mover_cursor_esquerda(saida, cursor)) {
		// 		cursor = line.erase(cursor);
		// 		cursor--;
		// 	}
		// 	saida += letter;
		// }
		// if (letter == '>') {
		// 	if (mover_cursor_direita(saida, cursor)) {
		// 		cursor = line.erase(cursor);
		// 		cursor++;
		// 	}
		// 	saida += letter;
		// }
		cursor++;
	}
	saida += '|';
	return saida;
}

void teste(string line) {
	string t;
	t += 'A';
	t += 'M';
	t += 'O';
	t += 'R';
	cout << t << endl;
}

int main() {
	string line = "euRamDo";
	// cin >> line;
	// teste(line);
	string saida = formatar(line);
	// cadaCaracter(line);
	cout << saida << endl;

	return 0;
}