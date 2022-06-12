#include <iostream>
#include <list>
#include <sstream> // string stream
#include <vector>

using namespace std;

Enum cmd{INVALID = -1, END, SHOW, IN, INIT, TIC, FINISH};

cmd stringToCMD(string s) {
	if (s == "end") {
		return END;
	}
	if (s == "init") {
		return INIT;
	}
	if (s == "in") {
		return IN;
	}
	if (s == "tic") {
		return TIC;
	}
	if (s == "finish") {
		return FINISH;
	}

	return INVALID;
}

struct Cliente {
	string id;
	int docs;
	int pac;

	Cliente(string name, int d, int p) {
		this->id = name;
		this->docs = d;
		this->pac = p;
	}

	string str() {
		stringstream ss;
		ss << id << ":" << docs << ":" << pac << endl;
		return ss.str();
	}
};

struct Banco {
	vector<Cliente *> caixas;
	list<Cliente *> filaEntrada;
	list<Cliente *> filaSaida;
	int docsProcessados{0};
	int docsPerdidos{0};
	int tics{0};

	Banco(int numCaixas) {
		this->caixas = numCaixas;
	}

	void insert(Cliente *c) {
	}

	bool empyt() {
	}

	void tic() {
	}

	void showAll() {
		for (auto cliente : caixas) {
			cout << "[" << (cliente == nullptr ? "" : cliente->str()) << "]";
		}
		cout << "\nin :{ ";
		for (auto cliente : filaEntrada)
			cout << cliente->str() << " ";
		cout << "}\nout:{ ";
		for (auto cliente : filaSaida)
			cout << cliente->str() << " ";
		cout << "}\n";
	}
};

int main() {
	Banco banco(3);
	string line, cmd;
	bool continua = true;
	while (continua) {
		getline(cin, line);
		stringstream ss(line);
		ss >> cmd;
		switch(stringToCMD(cmd){
		case END:
			continua = false;
			break;
		case INIT:
			int size;
			ss >> size;
			banco = Banco(size);
			break;
		case IN:
			break;
		case TIC:
			banco.tic();
			break;
		case SHOW:
			banco.showAll();
			break;
		case FINISH:
			break;
		default:
			cout << "Comando nao reconhecido" << endl;
			break;
		}
	}

	return 0;
}