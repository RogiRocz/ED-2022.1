#include <iostream>
#include <list>

using namespace std;
typedef list<int> listInt;

void matar(listInt &lista, int pos)
{
    if (pos + 1 >= lista.size())
    {
        lista.erase(lista.begin());
    }
    else
    {
        listInt::iterator it = lista.begin();
        advance(it, pos + 1);
        lista.erase(it);
    }
}

void passarEspada(listInt lista, int &pos)
{
    if (pos + 1 >= lista.size())
    {
        pos = 0;
    }
    else
    {
        pos++;
    }
}

void exibirLista(listInt lista, int pos)
{
    int i = 0;
    for (listInt::iterator it = lista.begin(); it != lista.end(); it++)
    {
        if (i == pos)
        {
            cout << *it << "> ";
        }
        else
        {
            cout << *it << ' ';
        }
        i++;
    }

    cout << endl;
}

void sobrarUm(listInt lista, int pos)
{
    exibirLista(lista, pos);

    while (lista.size() > 1)
    {
        matar(lista, pos);
        passarEspada(lista, pos);
        exibirLista(lista, pos);
    }
}

int main()
{
    int tam, pos;
    listInt lista;

    cin >> tam >> pos;
    pos--;
    // cout << pos << endl;

    for (int i = 0; i < tam; i++)
    {
        lista.push_back(i + 1);
    }

    sobrarUm(lista, pos);

    return 0;
}