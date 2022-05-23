#include <iostream>
#include <vector>

using namespace std;

void exibir(vector<int> vet){
	cout << "[ ";
	for(auto elem: vet){
		cout << elem << ' ';
	}
	cout << "]" << endl;
}

vector<int> resolver(vector<int> inicial, vector<int> sairam){
	for(auto itS = sairam.begin(); itS != sairam.end(); itS++){
		for(auto itI = inicial.begin(); itI != inicial.end(); itI++){
			if(*itS == *itI){
				inicial.erase(itI);
				break;
			}
		}
	}
	return inicial;
}

int main() {
    int n, m;
    vector<int> filaInicial, sairam;
	string entrada;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		filaInicial.push_back(num);
	}
	
	cin >> m;

	for(int i = 0; i < m; i++){
		int num;
		cin >> num;
		sairam.push_back(num);
	}

	// exibir(filaInicial);
	// exibir(sairam);
	exibir(resolver(filaInicial, sairam));
	
    return 0;
}
