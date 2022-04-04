#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vecInt;

bool existe(vecInt fila, int value)
{
    for (vecInt::iterator it = fila.begin(); it != fila.end(); it++)
    {
        if (*it == value)
            return true;
    }

    return false;
}

int contar(vecInt fila, int value)
{
    int i = 0;
    for (vecInt::iterator it = fila.begin(); it != fila.end(); it++)
    {
        if (*it == value)
            i++;
    }

    return i;
}

int procurar(vecInt fila, int value)
{
    int i = 0;
    for (vecInt::iterator it = fila.begin(); it != fila.end(); it++)
    {
        if (*it == value)
            break;
        i++;
    }

    if (i == fila.size())
        return -1;

    return i;
}

int procurar_apartir(vecInt fila, int value, int inicio)
{
    int i = inicio;
    for (vecInt::iterator it = fila.begin(); it != fila.end(); it++)
    {
        if (*it == value)
            break;
        i++;
    }

    if (i == fila.size())
        return -1;

    return i;
}

int main()
{
    int value = -99;
    vecInt fila{-1, -50, -1, -99, -1};

    // cout << existe(fila, value) << endl;
    // cout << contar(fila, value) << endl;
    cout << procurar(fila, value) << endl;

    return 0;
}