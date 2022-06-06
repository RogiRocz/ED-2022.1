#include <iostream>
#include <list>

using namespace std;

void exibir(list<int> vet, int pos){
	cout << "[ ";
	for(auto i = vet.begin(); i != vet.end(); i++){
		if(pos == 0){
			if(vet[pos] > 0){
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

int main(){
	int tam, pos, fase;
	cin >> tam >> pos >> fase;
	pos -= 1;

	if(pos < 0 || pos >= tam){
		cout << "A posicao tem que esta dentro do tamanho" << endl;
		exit(1);
	}

	if(fase != 1 || fase != -1){
		cout << "O terceiro valor so aceita -1 ou 1" << endl;
		exit(1);
	}

	list<int> vet;

	for(int i = 0; i < tam; i++){
		vet.push_back(i + 1);
	}

	int trocaSinal = fase;

	for(int i = 0; i < tam; i++){
		vet[i] *= trocaSinal;
		trocaSinal *= -1;
	}

	exibir(vet, pos);
	//sobrarUm(vet, pos);
	
	return 0;
}