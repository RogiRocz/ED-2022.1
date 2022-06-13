#include <iostream>
#include <list>
#include <sstream> // string stream
#include <vector>

using namespace std;

enum cmd { INVALID = -1, END, INIT, IN, TIC, SHOW, FINISH };

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
	if (s == "show") {
		return SHOW;
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

	Cliente(string id, int d, int p) {
		this->id = id;
		this->docs = d;
		this->pac = p;
	}

	string str() {
		stringstream ss;
		ss << id << ":" << docs << ":" << pac;
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
		this->caixas.reserve(numCaixas);
		for (int i = 0; i < (int)this->caixas.capacity(); i++) {
			this->caixas[i] == nullptr;
		}
	}

	void insert(Cliente *c) {
		this->filaEntrada.push_back(c);
	}

	bool empty() {
		for (int i = 0; i < this->caixas.capacity(); i++) {
			if (this->caixas[i] != nullptr) {
				return false;
			}
		}

		return true;
	}

	void tic() {
		this->filaSaida.clear();

		for (int i = 0; i < (int)this->caixas.capacity(); i++) {
			auto cliente = &(this->caixas[i]);
			if(cliente != nullptr){
				if((*cliente)->pac == 0){
					auto it = this->caixas.begin() + i;
					this->caixas.erase(it);
				}
			}
		}

		for (int i = 0; i < (int)this->caixas.capacity(); i++) {
			auto cliente = &(this->caixas[i]);

			if (cliente != nullptr) {
				if ((*cliente)->docs != 0) {
					(*cliente)->docs--;
				} else {
					this->filaSaida.push_back((*cliente));
				}
			} else {
				if (!this->filaEntrada.empty()) {
					(*cliente) = filaEntrada.front();
					this->filaEntrada.pop_front();
				}
			}
		}

		for (auto &cliente : this->filaEntrada) {
			if (cliente->pac > 0) {
				cliente->pac--;
			} else {
				this->filaSaida.remove(cliente);
			}
		}
	}

	void showAll() {
		for (int i = 0; i < (int)this->caixas.capacity(); i++) {
			auto cliente = this->caixas[i];
			cout << "[" << (cliente == nullptr ? "" : cliente->str()) << "]";
		}

		cout << endl;

		cout << "in :{ ";
		for (auto cliente : filaEntrada) {
			cout << cliente->str() << " ";
		}
		cout << "}" << endl;

		cout << "out:{ ";
		for (auto cliente : filaSaida) {
			cout << cliente->str() << " ";
		}
		cout << "}" << endl;
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
		switch (stringToCMD(cmd)) {
		case END:
			continua = false;
			break;
		case INIT: {
			int size;
			ss >> size;
			banco = Banco(size);
		} break;
		case IN: {
			string id;
			int docs, pac;
			ss >> id >> docs >> pac;
			banco.insert(new Cliente(id, docs, pac));
		} break;
		case TIC:
			banco.tic();
			break;
		case SHOW:
			banco.showAll();
			break;
		case FINISH:
			while (!banco.empty()) {
				banco.tic();
				cout << "Processados: " << banco.docsProcessados << endl;
				cout << "Perdidos: " << banco.docsPerdidos - 1 << endl;
				cout << "tics: " << banco.tics << endl;
			}
			break;
		default:
			cout << "Comando nao reconhecido" << endl;
			break;
		}
	}

	return 0;
}