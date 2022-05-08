#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct Ponto
{
    int l, c;
    Ponto(int l, int c) : l(l), c(c) {}
};

void exibirVet(vector<string> vet)
{
    for (auto row : vet)
    {
        cout << row << endl;
    }
    // getchar();
}

Ponto posInicial(vector<string> vet)
{
    for (size_t i = 0; i < vet.size(); i++)
    {
        for (size_t j = 0; j < vet[0].size(); j++)
        {
            if (vet[i][j] == 'I')
            {
                return Ponto(i, j);
            }
        }
    }
}

Ponto posFinal(vector<string> vet)
{
    for (size_t i = 0; i < vet.size(); i++)
    {
        for (size_t j = 0; j < vet[0].size(); j++)
        {
            if (vet[i][j] == 'F')
            {
                return Ponto(i, j);
            }
        }
    }
}

vector<Ponto> get_vizinhos(Ponto p)
{
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

bool procurarCaminho(vector<string> &vet, Ponto atual, Ponto destino)
{
    int l = atual.l;
    int c = atual.c;

    if (l == destino.l && c == destino.c)
    {
        vet[l][c] = '.';
        return true;
    }

    if (vet[l][c] != '_')
    {
        return false;
    }

    vet[l][c] = '.';
    for (auto viz : get_vizinhos(atual))
    {
        if (procurarCaminho(vet, viz, destino))
        {
            return true;
        }
    }

    vet[l][c] = '_';
    return false;
}

void fugir(vector<string> &vet)
{
    Ponto inicio = posInicial(vet);
    Ponto fim = posFinal(vet);

    vet[inicio.l][inicio.c] = '_';
    vet[fim.l][fim.c] = '_';

    procurarCaminho(vet, inicio, fim);
}

int main()
{
    ifstream arq("./Entrada.txt", ifstream::in);
    int nl, nc;
    arq >> nl >> nc;
    vector<string> vet;
    if (arq.good())
    {
        string prox;
        getline(arq, prox);
        string line;
        while (getline(arq, line))
        {
            // cout << line << endl;
            vet.push_back(line);
        }
    }

    fugir(vet);
    exibirVet(vet);

    arq.close();
    return 0;
}