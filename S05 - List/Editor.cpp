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

	auto pos_cursor = [](string saida, string::iterator cursor) {
		int i = 0;
		for (auto it = saida.begin(); it != saida.end(); it++) {
			if (*it == *cursor)
				break;
			i++;
		}
		return i;
	};

	auto inserir_palavra = [&](string& saida, string::iterator cursor, char c) {
		int j = pos_cursor(saida, cursor);
		string resto = saida.substr(j);
		saida.resize(j + 1);
		saida[j] = c;
		saida += resto;
	};

	for (int i = 0; i <= (int)line.size(); i++) {
		auto letter = line[i];
		if (caracteresAceitos(letter)) {
			inserir_palavra(saida, cursor, letter);
			cursor++;
		}
		if (letter == 'R') {
			letter = '\n';
			inserir_palavra(saida, cursor, letter);
			cursor++;
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
		if (letter == '<') {
			if (mover_cursor_esquerda(saida, cursor)) {
				cursor--;
			}
		}
		if (letter == '>') {
			if (mover_cursor_direita(saida, cursor)) {
				cursor++;
			}
		}
		cout << saida << endl;
	}
	cout << endl;
	inserir_palavra(saida, cursor, '|');
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
	string line = "euRamo<<<<<<<como-";
	// cin >> line;
	// teste(line);
	string saida = formatar(line);
	// cadaCaracter(line);
	cout << saida << endl;

	return 0;
}