#include <iostream>
#include <list>

using namespace std;

void cadaCaracter(string line){
	for(int i = 0; i <= line.size(); i++){
		cout << "'" << line[i] << "'" << endl;
	}
}

void formatar(string line){}

int main(){
	string line;
	cin >> line;
	//formatar(line);
	cadaCaracter(line);
	cout << line << endl;

	return 0;
}