#include <iostream>
#include <vector>

using namespace std;

void exibirVet(vector<int> vet)
{
    cout << "[ ";
    for (size_t i = 0; i < vet.size(); i++)
    {
        cout << vet[i] << ' ';
    }
    cout << "]" << endl;
}

vector<int> somaValores(vector<int> vet)
{
    auto result = [vet]()
    {
        vector<int> aux;
        for (size_t i = 0; i < vet.size() - 1; i++)
        {
            aux.push_back(vet[i] + vet[i + 1]);
        }
        return aux;
    };

    return result();
}

void trianguloSoma(vector<int> vet)
{
    // somar(vet);
    if (vet.size() == 1)
    {
        return;
    }

    vector<int> vetSomado = somaValores(vet);
    trianguloSoma(vetSomado);
    exibirVet(vetSomado);
}

int main()
{
    vector<int> vet = {1, 2, 4, 8, 16, 32, 64};

    trianguloSoma(vet);
    exibirVet(vet);
    return 0;
}
