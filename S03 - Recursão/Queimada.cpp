#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>
#include <algorithm>

enum Tipo_terreno
{
    ARVORE,
    VAZIO,
};

struct Ponto
{
    int l;
    int c;
    Ponto(int l, int c) : l(l), c(c) {}
    // this->l = l;
    // this->c = c;
};

using namespace std;

string produzirMapa(int nc, int dif)
{
    srand(time(NULL) + dif);
    string coluna(nc, ' ');
    for (auto &letra : coluna)
    {
        int numRandomico = rand() % 2;
        switch (numRandomico)
        {
        case ARVORE:
            letra = '#';
            break;
        case VAZIO:
            letra = '.';
            break;
        default:
            letra = '^';
            break;
        }
    }

    return coluna;
}

void exibirMatriz(vector<string> vet)
{
    for (auto row : vet)
    {
        for (auto letra : row)
        {
            cout << letra << ' ';
        }
        cout << endl;
    }
    getchar();
}

void queimar(vector<string> &vet, Ponto p)
{
    // cout << p.l << ' ' << p.c << endl;
    int l = p.l;
    int c = p.c;

    if (l < 0 || l >= vet.size() || c < 0 || c >= vet[0].size())
    {
        return;
    }

    if (vet[l][c] != '#')
    {
        return;
    }

    vet[l][c] = 'o';
    exibirMatriz(vet);

    queimar(vet, Ponto(l, c - 1));
    queimar(vet, Ponto(l - 1, c));
    queimar(vet, Ponto(l, c + 1));
    queimar(vet, Ponto(l + 1, c));
}

int main()
{
    string entrada = "5 5 0 0";
    stringstream ss(entrada);

    int nl, nc, l, c;
    ss >> nl >> nc >> l >> c;

    vector<string> vet(nl);
    for (int i = 0; i < nc; i++)
    {
        vet[i] = produzirMapa(nc, i);
    }

    for (auto row : vet)
    {
        for (auto letra : row)
        {
            cout << letra << ' ';
        }
        cout << endl;
    }

    cout << endl;

    queimar(vet, Ponto(l, c));

    return 0;
}
