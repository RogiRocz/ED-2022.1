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

int procurar_apartir(vecInt fila, int value, int inicioBusca)
{
    int i = inicioBusca;
    for (vecInt::iterator it = fila.begin() + i; it != fila.end(); it++)
    {
        if (*it == value)
            break;
        i++;
    }

    if (i == fila.size() && i != inicioBusca)
        return -1;

    return i;
}

int procurar_menor(vecInt &fila)
{
    vecInt::iterator it = fila.begin();
    if (fila.size() == 1)
    {
        return *fila.begin();
    }
    else
    {
        if (*it < *(it + 1))
        {
            fila.erase(it + 1);
            return procurar_menor(fila);
        }
        else
        {
            fila.erase(it);
            return procurar_menor(fila);
        }
    }

    return *(fila.begin());
}

int procurar_pos_menor(vecInt fila)
{
    int pos = 0, menor = *fila.begin();

    for (auto num : fila)
    {
        if (menor > num)
        {
            menor = num;
        }
    }

    for (auto num : fila)
    {
        if (menor == num)
        {
            return pos;
        }

        pos++;
    }
}

int procurar_pos_menor_apartir(vecInt fila, int inicio)
{
    int pos = 0, menor = *fila.begin();

    for (vecInt::iterator it = fila.begin() + inicio; it != fila.end(); it++)
    {
        if (menor > *it)
        {
            menor = *it;
        }
    }

    for (auto num : fila)
    {
        if (menor == num)
        {
            return pos;
        }

        pos++;
    }
}

int procurar_pos_melhor_se(vecInt fila)
{
    int pos = 0, menor = -1;

    for (auto num : fila)
    {
        if (num > 0)
        {
            menor = num;
            break;
        }
    }

    if (menor == -1)
        return menor;

    for (vecInt::iterator it = fila.begin(); it != fila.end(); it++)
    {
        if (*it > 0 && menor > *it)
        {
            menor = *it;
        }
    }

    for (auto num : fila)
    {
        if (menor == num)
        {
            return pos;
        }

        pos++;
    }
}

float calcular_stress_medio(vecInt fila)
{
    float media{0};
    for (auto elem : fila)
    {
        elem = elem < 0 ? elem * -1 : elem;
        media += elem;
    }
    media /= fila.size();

    return media;
}

string mais_homens_ou_mulheres(vecInt fila)
{
    int contH{0}, contM{0};
    string resultado{};

    for (auto elem : fila)
    {
        elem < 0 ? contM++ : contH++;
    }

    resultado = contH > contM ? "homens" : "mulheres";
    resultado = contH - contM == 0 ? "empate" : resultado;

    return resultado;
}

string qual_metade_mais_estressada(vecInt fila)
{
    int mod = fila.size() % 2, cont{0}, soma{0}, somaPrimeira{0}, somaSegunda{0};

    int div = mod == 0 ? fila.size() / 2 : fila.size() / 2 + 1;

    for (int i = 0; i < div; i++)
    {
        fila[i] = fila[i] < 0 ? fila[i] * -1 : fila[i];
        soma += fila[i];
    }

    somaPrimeira = soma;
    soma = 0;

    for (int i = div; i < fila.size(); i++)
    {
        fila[i] = fila[i] < 0 ? fila[i] * -1 : fila[i];
        soma += fila[i];
    }

    somaSegunda = soma;

    string resultado{""};

    resultado = somaPrimeira > somaSegunda ? "primeira" : "segunda";
    resultado = somaPrimeira == somaSegunda ? "empate" : resultado;

    return resultado;
}

vecInt clonar(const vecInt &fila)
{
    vecInt vetClonado;
    for (auto elem : fila)
    {
        vetClonado.push_back(elem);
    }

    return vetClonado;
}

int main()
{
    int value = 0;
    vecInt fila{50, 98, 2, -50, -1, -99};

    // cout << existe(fila, value) << endl;
    // cout << contar(fila, value) << endl;
    cout << clonar(fila) << endl;

    return 0;
}