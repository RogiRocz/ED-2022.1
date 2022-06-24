#include <iostream>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

struct Ponto{
	int l, c;
	//Ponto(int l, int c)l(l), c(c){}
};

int main(){
	fstream file("dadosBurn.txt", fstream::in);
	if(file.is_open()){
		string line;
		int l, c;
		Ponto pontoInicial;
		
		getline(file, line);
		line >> l >> c;
		
		
		
	}


	file.close();
	return 0;
}