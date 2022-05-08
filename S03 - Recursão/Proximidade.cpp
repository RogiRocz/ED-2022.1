#include <iostream>

using namespace std;

void exibir(string dados)
{
    cout << dados << endl;
}

void verificarAnt(string dados, int pos, int prox)
{
    if (pos < 0 || pos >= dados.size())
    {
        return;
    }

    if (dados.front() ==)
    {
    }
}

void verificarPos(string dados, int pos, int prox)
{
}

void saida(string dados, int prox)
{
    // Tem que passar os valores testes pra verificar
    int posBlank = [dados]()
    {
        for (size_t i = 0; i < dados.size(); i++)
        {
            if (dados[i] == '_')
            {
                return i;
            }
        }
        return -1;
    };

    // Verificar se tem repetido proximo
    verificarAnt(dados, posBlank(), prox);
    verificarPos(dados, posBlank(), prox);
}

int main(int argc, char const *argv[])
{
    char dados[100] = "01_2_";
    int prox = 3;

    // gets(dados);
    // cin >> prox;
    if (!(prox > 0 && prox < 100))
    {
        cerr << "Proximidade so aceita valores de 1 ate 99";
        exit(1);
    }

    saida(dados, prox);
    // cout << "Dados: " << dados << " Prox: " << prox;

    return 0;
}