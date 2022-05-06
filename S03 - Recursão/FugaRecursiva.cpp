#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void exibirVet(vector<string> vet)
{
    for (auto elem : vet)
    {
        cout << elem << endl;
    }
    getchar();
}

int posInicial(vector<string> vet)
{
    if (vet[0] == 'I')
    {
        return 0;
    }

    vet.erase(vet.begin());
    return 1 + posInicial(vet);
}

int posFinal(vector<string> vet)
{
    if (vet[0] == 'F')
    {
        return 0;
    }

    return 1 + posFinal(vet.erase(vet.begin()));
}

void fugir(vector<string> vet)
{
    int inicio = posInicial(vet);
    int fim = posFinal(vet);

    cout << "Inicio: " << inicio << ' ' << "Fim: " << fim << endl;
}

int main()
{
    ifstream ifs("./Entrada.txt", ifstream::in);
    int nl, nc;
    ifs >> nl >> nc;
    vector<string> vet(nl);
    if (ifs.good())
    {
        string line;
        int i = 0;
        while (getline(ifs, line))
        {
            // cout << line << endl;
            vet.push_back(line);
            i++;
        }
    }

    fugir(vet);

    ifs.close();
    return 0;
}