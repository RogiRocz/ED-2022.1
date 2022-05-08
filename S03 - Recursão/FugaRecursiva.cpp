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

void procurarCaminho(vector<string> &vet, Ponto inicio, Ponto fim)
{
    int l = inicio.l;
    int c = inicio.c;
    if (l < 0 && l >= vet.size() || c < 0 && c >= vet[0].size())
    {
        return;
    }

    if (vet[l][c] != '_')
    {
        return;
    }

    if (l == fim.l && c == fim.c)
    {
        vet[l][c] = '.';
        return;
    }
    vet[l][c] = '*';
    procurarCaminho(vet, Ponto(l, c - 1), fim);
    procurarCaminho(vet, Ponto(l - 1, c), fim);
    procurarCaminho(vet, Ponto(l, c + 1), fim);
    procurarCaminho(vet, Ponto(l + 1, c), fim);
    vet[l][c] = '.';
}

void fugir(vector<string> vet)
{
    auto inicio = posInicial(vet);
    auto fim = posFinal(vet);

    vet[inicio.l][inicio.c] = '_';
    vet[fim.l][fim.c] = '_';

    procurarCaminho(vet, inicio, fim);
    exibirVet(vet);
}

int main()
{
    ifstream ifs("./Entrada.txt", ifstream::in);
    int nl, nc;
    ifs >> nl >> nc;
    vector<string> vet;
    if (ifs.good())
    {
        ifs.seekg((int)ifs.tellg() + 1);
        string line;
        while (getline(ifs, line))
        {
            // cout << line << endl;
            vet.push_back(line);
        }
    }

    fugir(vet);
    // exibirVet(vet);

    ifs.close();
    return 0;
}