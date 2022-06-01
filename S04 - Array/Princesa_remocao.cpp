#include <iostream>
#include <vector>

using namespace std;

void exibirVector(vector<int> elems, int pos){
  int novaPos = pos > elems.size() ? 0 : pos;

  for(int i = 0; i < elems.size(); i++){
    if(elems[i] != 0){
      if(i == pos){
        cout << elems[i] << "> ";
      }else{
        cout << elems[i] << " ";
      }
    }
  }
  cout << endl;
}

void matar(vector<int>& elems, int pos){
  int proxPos = pos + 1 > elems.size()  ? 0 : pos + 1;
	if(elems[pos + 1] == 0){
		proxPos = 0;
	}
  elems[proxPos] = 0;
}

void verificarVivos(vector<int>& elems, int& pos){
  for(int i = 0; i < elems.size(); i++){
    if(elems[i] == 0){
      int proxI = i + 1;
      if(proxI < elems.size()){
        elems[i] = elems[proxI];
        elems[proxI] = 0;
      }
    }
  }
}

void passarEspada(vector<int>& elems, int& pos){
  if(elems[pos + 1] == 0){
    pos = 0;
  }else{
    pos++;
  }
}

void sobrarUm(vector<int>& elems, int pos){
	exibirVector(elems, pos);
  while(elems[pos + 1] != 0 || elems[pos - 1] != 0){
	  matar(elems, pos);
	  verificarVivos(elems, pos);
	  passarEspada(elems, pos);
	  exibirVector(elems, pos);
  }
}

int main() {
  vector<int> elems;
  int tam;
  int pos;

  cin >> tam >> pos;
  pos--;

  for(int i = 0; i < tam; i++){
    elems.push_back(i + 1);
  }
	
  sobrarUm(elems, pos);

return 0;
}