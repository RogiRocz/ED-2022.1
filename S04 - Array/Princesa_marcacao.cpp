#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vetInt;

void exibirVector(vetInt elems, int pos)
{
	cout << "[ ";
    for (int i = 0; i < elems.size(); i++)
    {
        if (i == pos)
        {
            if (elems[i] > 0)
            {
                cout << elems[i] << "> ";
            }
            else
            {
                cout << "<" << elems[i] << " ";
            }
        }
        else
        {
            cout << elems[i] << " ";
        }
    }
	cout << "]" << endl;
}

void matar(vetInt &elems, int &pos)
{
    if (elems[pos] > 0)
    {
        if (pos + 1 < (int)elems.size())
        {
            elems.erase(elems.begin() + pos + 1);
        }
        else
        {
            elems.erase(elems.begin());
			pos--;
        }
    }
    else
    {
        if (pos - 1 > 0)
        {
            elems.erase((elems.begin() + pos) - 1);
            pos--;
        }else if(pos - 1 == 0){
			elems.erase(elems.begin());
			pos--;
		}
        else
        {
			// Quando comecar com um numero negativo e pos == 0
            elems.pop_back();
            //pos = elems.size() - 1;
        }
    }
}

void passarEspada(vetInt elems, int &pos)
{
    if (elems[pos] > 0)
    {
        if (pos + 1 < elems.size())
        {
            pos++;
        }
        else
        {
            pos = 0;
        }
    }
    else
    {
        if (pos - 1 >= 0)
        {
            pos--;
        }
        else
        {
            pos = elems.size() - 1;
        }
    }
}

void sobrarUm(vetInt elems, int pos)
{
    while (elems.size() != 1)
    {
        matar(elems, pos);
        passarEspada(elems, pos);
        exibirVector(elems, pos);
    }
}

int main()
{
    vetInt elems;
    int tam;
    int pos;
    int fase;
    int trocaSinal;

    cin >> tam >> pos >> fase;
    --pos;

	if(fase > 0){
		fase = 1;
	}else if(fase < 0){
		fase = -1;
	}
	
    trocaSinal = fase;

    for (int i = 0; i < tam; i++)
    {
        elems.push_back(i + 1);
    }

    for (auto &elem : elems)
    {
        elem *= trocaSinal;
        trocaSinal *= -1;
    }

    exibirVector(elems, pos);

    sobrarUm(elems, pos);

    return 0;
}