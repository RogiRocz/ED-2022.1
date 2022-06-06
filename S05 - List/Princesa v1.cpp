#include <iostream>
#include <list>

using namespace std;

void exibir(list<int> vet, int pos){
	cout << "[ ";
	for(auto i = vet.begin(); i != vet.end(); i++){
		if(pos == 0){
			cout << *i << "> ";
		}else{
			cout << *i << ' ';
		}
		pos--;
	}
	cout << "]" << endl;
}

void matar(list<int>& vet, int pos){
	auto it = vet.begin();
	int walk{0};
	if(pos + 1 < (int) vet.size()){
		walk = pos + 1;
	}
	advance(it, walk);
	vet.erase(it);
}

void passarEspada(list<int>& vet, int& pos){
	if(pos + 1 >= (int)vet.size()){
		pos = 0;
	}else{
		pos++;
	}
}

void sobrarUm(list<int>& vet, int pos){
	while(vet.size() != 1){
		matar(vet, pos);
		passarEspada(vet, pos);
		exibir(vet, pos);
	}
}

int main(){
	int tam, pos;
	cin >> tam >> pos;
	pos -= 1;

	if(pos < 0 || pos >= tam){
		cout << "A posicao tem que esta dentro do tamanho" << endl;
		exit(1);
	}

	list<int> vet;

	for(int i = 0; i < tam; i++){
		vet.push_back(i + 1);
	}

	exibir(vet, pos);
	sobrarUm(vet, pos);
	
	return 0;
}