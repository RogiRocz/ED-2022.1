#include <iostream>
#include <list>

using namespace std;

struct Cliente{
	string id;
	int docs;
	int pac;
};

struct Banco{
	vector<Cliente*> caixas;
	list<Cliente*> filaEntrada;
	list<Cliente*> filaSaida;
};

int main(){
	int numCaixas, qntdClientes;
	int paciClientes, qntdDocs;
	int limPessoas;

	// Pseudocodigo para cada iteracao
	tic();
	
	return 0;
}