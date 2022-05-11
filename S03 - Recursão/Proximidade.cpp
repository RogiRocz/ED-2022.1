#include <iostream>

using namespace std;

void exibir(string dados)
{
    cout << dados;
}

bool verificarAnt(string dados, int prox, int pos, int value)
{
    cout << "ANT" << endl;
    cout << "Dados: " << dados << " Prox :" << prox << " Pos: " << pos << " Value: " << value << endl;
    
    if (pos < 0 || prox == 0)
    {
        return 1;
    }

    if (dados[pos] == (value + '0'))
    {
        return 0;
    }
    
    return 1 * verificarAnt(dados, prox - 1, pos - 1, value);
}

int verificarPos(string dados, int prox, int pos, int value)
{   
    cout << "POS" << endl;
    cout << "Dados: " << dados << " Prox :" << prox << " Pos: " << pos << " Value: " << value << endl;
    
    if(pos >= dados.size() || prox == 0)
    {
        return 1;
    }
    
    if(dados[pos] == (value + '0'))
    {
        return 0;
    }
    
    return 1 * verificarPos(dados, prox - 1, pos + 1, value);
}

void saida(string dados, int prox)
{
    auto posVazia = [](string dados)
    {
        for (int i = 0; i < (int)dados.size(); i++)
        {
            if (dados[i] == '_')
            {
                return i;
            }
        }
        return -1;
    };
    
    int pos = posVazia(dados);

    while(pos != -1){
        for(int i = 0; i <= prox; i++){
            if(verificarAnt(dados, prox, pos, i) && verificarPos(dados, prox, pos, i))
            {
                dados[pos] = i + '0';
                
            }
        }
        cout << "------------------------" << endl;
        pos = posVazia(dados);
    }
    exibir(dados);
}

int main(int argc, char const *argv[])
{
    char dados[100];
    int prox;

    fgets(dados, 100, stdin);
    cin >> prox;
    
    if (!(prox > 0 && prox < 100))
    {
        cerr << "Proximidade so aceita valores de 1 ate 99";
        exit(1);
    }

    saida(dados, prox);

    return 0;
}
