#include <iostream>
#include <list>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	list<pair<int, int>> pontos;
	queue<char> times;
	string line;
	
	fstream file;
	file.open("Crosses.txt", fstream::in);
	for(int i = 0; i < 15; i++){
		getline(file, line);
		stringstream ss(line);
		int pontos1, pontos2;
		ss >> pontos1 >> pontos2;
		pontos.push_back(make_pair(pontos1, pontos2));
	}

	for(int i = 0; i < 16; i++){
		times.push(65 + i);
	}

	auto itPontos = pontos.begin();

	while(times.size() != 1){
		auto time1 = times.front();
		times.pop();
		auto time2 = times.front();
		times.pop();

		if(itPontos->first > itPontos->second){
			times.push(time1);
		}else{
			times.push(time2);
		}

		itPontos++;
	}

	cout << times.front() << endl;

	file.close();
	return 0;
}