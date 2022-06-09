#include <iostream>
#include <list>

using namespace std;

void exibir(list<int> vet, int pos){
	cout << "[ ";
	for(auto i = vet.begin(); i != vet.end(); i++){
		if(pos == 0){
			if(*i > 0){
				cout << *i << "> ";
			}else{
				cout << "<" << *i << ' ';
			}
		}else{
			cout << *i << ' ';
		}
		pos--;
	}
	cout << "]" << endl;
}

void matar(list<int>& vet, int pos){
	list<int>::iterator itElem = vet.begin() + pos;
	if(*itElem > 0){
		if(pos + 1 >= vet.size()){
			vet.erase(vet.begin());
		}else{
			vet.erase(itElem + 1);
		}
	}else{
		if(pos - 1 < 0){
			vet.erase(vet.end());
		}else if(pos - 1 >= 0){
			vet.erase(itElem - 1);
		}
	}
}

void passarEspada(list<int> vet, int& pos){
	auto itElem = vet.begin() + pos;
	if(*itElem > 0){
		if(pos + 1 >= vet.size()){
			pos = 0;
		}else{
			pos++;
		}
	}else{
		if(pos - 1 < 0){
			pos = vet.size() - 1;
		}else if(pos - 1 >= 0){
			pos--;
		}
	}
}

void sobrarUm(list<int> vet, int pos){
	while(vet.size() != 1){
		matar(vet, pos);
		passarEspada(vet, pos);
		exibir(vet, pos);
	}
}

int main(){
	int tam, pos, fase;
	cin >> tam >> pos >> fase;
	pos -= 1;

	if(pos < 0 || pos >= tam){
		cout << "A posicao tem que esta dentro do tamanho" << endl;
		exit(1);
	}

	if(fase != 1 && fase != -1){
		cout << "O terceiro valor so aceita -1 ou 1" << endl;
		exit(1);
	}

	list<int> vet;

	for(int i = 0; i < tam; i++){
		vet.push_back(i + 1);
	}

	int trocaSinal = fase;

	for(auto it = vet.begin(); it != vet.end(); it++){
		*it *= trocaSinal;
		trocaSinal *= -1;
	}

	exibir(vet, pos);
	sobrarUm(vet, pos);
	
	return 0;
}