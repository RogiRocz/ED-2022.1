#include <iostream>
#include <list>

using namespace std;

void cadaCaracter(string line){
	for(int i = 0; i <= (int)line.size(); i++){
		cout << "'" << line[i] << "'" << endl;
	}
}

bool caracteresAceitos(char c){
	if((c >= 'a' && c <= 'z') || c == '-'){
		return true;
	}
	return false;
}


string formatar(string line){
	string saida;
	auto cursor = saida.begin();

	auto mover_cursor_esquerda = [](string::iterator cursor){
		return *(cursor - 1) != 0;
	};
	
	auto mover_cursor_direita = [](string::iterator cursor){
		return *(cursor + 1) != 0;
	};
	
	for(int i = 0; i <= (int)line.size(); i++){
		auto letter = line[i];
		if(caracteresAceitos(letter)){
			saida += letter;
		}
		if(letter == 'R'){
			letter = '\n';
			saida += letter;
		}
		if(letter == 'B'){
			if(mover_cursor_esquerda(cursor)){
				cursor--;
				cursor = line.erase(cursor);
				cursor = line.erase(cursor);
			}			
			saida += letter;
		}
		if(letter == 'D'){
			if(mover_cursor_direita(cursor)){
				cursor++;
				cursor = line.erase(cursor);
				cursor = line.erase(cursor);
			}	
			saida += letter;
		}
		if(letter == '<'){
			if(mover_cursor_esquerda(cursor)){
				cursor = line.erase(cursor);
				cursor--;
			}
			saida += letter;
		}
		if(letter == '>'){
			if(mover_cursor_direita(cursor)){
				cursor = line.erase(cursor);
				cursor++;
			}
			saida += letter;
		}
		cursor++;
	}
	return saida;
}

void teste(string line){
	auto it = line.begin();
	it = it - 1;
	cout << (int)*it << endl;
}

int main(){
	string line = "euRamo<<<";
	//cin >> line;
	//teste(line);
	string saida = formatar(line);
	//cadaCaracter(line);
	cout << saida << endl;

	return 0;
} 