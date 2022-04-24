#include <iostream>
#include <vector>
#include <sstream>
#include <time.h>
#include <algorithm>

using namespace std;
typedef vector<int> vecInt;

string to_string(vecInt fila)
{
    stringstream ss;
    for (auto elem : fila)
    {
        ss << elem << ' ';
    }

    return ss.str();
}

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

vector<int> pegar_homens(const vector<int> &fila)
{
    vecInt vetHomens;
    for (auto elem : fila)
    {
        if (elem > 0)
            vetHomens.push_back(elem);
    }

    return vetHomens;
}

vector<int> pegar_calmos(const vector<int> &fila)
{
    vecInt vetCalmos;
    for (auto elem : fila)
    {
        if (abs(elem) <= 10)
            vetCalmos.push_back(elem);
    }

    return vetCalmos;
}

vector<int> pegar_mulheres_calmas(const vector<int> &fila)
{
    vecInt vetMulheresCalmas;
    for (auto elem : fila)
    {
        if (elem < 0 && abs(elem) <= 10)
            vetMulheresCalmas.push_back(elem);
    }

    return vetMulheresCalmas;
}

vector<int> inverter_com_copia(const vector<int> &fila)
{
    vecInt vetInvertido;
    for (auto elem : fila)
    {
        vetInvertido.insert(vetInvertido.begin(), elem);
    }

    return vetInvertido;
}

void inverter_inplace(vector<int> &fila)
{
    int vetSize = (int)fila.size();
    int count = vetSize / 2;

    for (int i = 0; i < count; i++)
    {
        int aux = fila[i];
        fila[i] = fila[vetSize - i - 1];
        fila[vetSize - i - 1] = aux;
    }
}

void embaralhar(vector<int> &fila)
{
    int vetSize = (int)fila.size();
    srand(time(NULL));

    for (int i = 0; i < vetSize; i++)
    {
        int numRandomico = rand() % vetSize;
        int aux = fila[i];
        fila[i] = fila[numRandomico];
        fila[numRandomico] = aux;
    }
}

void ordenar(vector<int> &fila)
{
    if (fila.size() < 2)
        return;
    for (int i = 0; i < (int)fila.size(); i++)
    {

        for (int j = 0; j < (int)fila.size() - 1; j++)
        {
            if (fila[j] > fila[j + 1])
            {
                int aux = fila[j];
                fila[j] = fila[j + 1];
                fila[j + 1] = aux;
            }
        }
    }
}

vector<int> exclusivos(const vector<int> &fila)
{
    vecInt vetExclusivos;
    bool exclusivo{false};

    vetExclusivos.push_back(fila[0]);

    for (int i = 0; i < (int)fila.size(); i++)
    {
        for (auto elem : vetExclusivos)
        {
            if (fila[i] != elem)
            {
                exclusivo = true;
            }
            else
            {
                exclusivo = false;
                break;
            }
        }
        if (exclusivo)
        {
            vetExclusivos.push_back(fila[i]);
        }
        exclusivo = false;
    }

    return vetExclusivos;
}

vector<int> diferentes(const vector<int> &fila)
{
    vecInt vetDiferentes;
    bool diferente{false};

    vetDiferentes.push_back(abs(fila[0]));

    for (int i = 0; i < (int)fila.size(); i++)
    {
        for (auto elem : vetDiferentes)
        {
            if (abs(fila[i]) != elem)
            {
                diferente = true;
            }
            else
            {
                diferente = false;
                break;
            }
        }
        if (diferente)
        {
            vetDiferentes.push_back(abs(fila[i]));
        }
        diferente = false;
    }

    return vetDiferentes;
}

vector<int> abandonados(const vector<int> &fila)
{
    vecInt vetExclusivos = exclusivos(fila);
    vecInt vetAbandonados = fila;
    for (size_t i = 0; i < vetAbandonados.size(); i++)
    {
        for (size_t j = 0; j < vetExclusivos.size(); j++)
        {
            if (vetAbandonados[i] == vetExclusivos[j])
            {
                vetAbandonados.erase(vetAbandonados.begin() + i);
                vetExclusivos.erase(vetExclusivos.begin() + j);
                i = -1; // voltar por inicio dos abandonados
                break;
            }
        }
    }

    return vetAbandonados;
}

vector<int> sozinhos(const vector<int> &fila)
{
    vecInt vetExcluisivos = fila;
    vecInt vetSozinhos;

    for (size_t i = 0; i < vetExcluisivos.size() - 1; i++)
    {
        bool sozinho{true};
        for (size_t j = i + 1; j < vetExcluisivos.size(); j++)
        {
            if (abs(vetExcluisivos[i]) == abs(vetExcluisivos[j]))
            {
                sozinho = false;
                break;
            }
        }
        if (sozinho)
        {
            vetSozinhos.push_back(vetExcluisivos[i]);
        }
    }

    return vetSozinhos;
}

vector<int> mais_ocorrencias(const vector<int> &fila)
{
    vecInt contOcorrencias;
    int cont{1};
    for (size_t i = 0; i < fila.size() - 1; i++)
    {
        for (size_t j = i + 1; j < fila.size(); j++)
        {
            if (abs(fila[i]) == abs(fila[j]))
            {
                cont++;
            }
        }
        contOcorrencias.push_back(cont);
        cont = 1;
    }

    int maiorOcorrencia;
    for (size_t i = 0; i < contOcorrencias.size() - 1; i++)
    {
        if (contOcorrencias[i] > contOcorrencias[i + 1])
        {
            maiorOcorrencia = contOcorrencias[i];
        }
    }

    return {maiorOcorrencia};
}

vector<int> mais_recorrencias(const vector<int> &fila)
{
    vector<pair<int, int>> recorrencias;
    int cont{1};

    for (size_t i = 0; i < fila.size() - 1; i++)
    {
        pair<int, int> contaRecorrencia = make_pair(fila[i], cont);

        for (size_t j = i + 1; j < fila.size(); j++)
        {
            if (abs(fila[i]) == abs(fila[j]))
            {
                contaRecorrencia.second = ++cont;
            }
        }

        recorrencias.push_back(contaRecorrencia);
        cont = 1;
    }

    vecInt maioresRecorrencias;
    for (auto elem : recorrencias)
    {
        if (elem.second > 2)
            maioresRecorrencias.push_back(elem.first);
    }

    return maioresRecorrencias;
}

int briga(const vecInt &fila)
{
    int contBrigas{0};
    for (size_t i = 0; i < fila.size() - 1; i++)
    {
        if (abs(fila[i]) > 50)
        {
            if (abs(fila[i - 1]) > 30 && abs(fila[i + 1]) > 30)
            {
                contBrigas++;
            }
        }
    }

    return contBrigas;
}

vector<int> apaziguados(const vecInt &fila)
{
    vecInt posicoesHiperEstressados;
    for (size_t i = 0; i < fila.size() - 1; i++)
    {
        if (abs(fila[i]) > 80)
        {
            if (abs(fila[i - 1]) < 10 || abs(fila[i + 1]) < 10)
            {
                posicoesHiperEstressados.push_back(i);
            }
        }
    }

    return posicoesHiperEstressados;
}

int quantos_times(const vecInt &fila)
{
    int contTimes{0};
    int contIntegrantes{1};

    for (size_t i = 0; i < fila.size() - 1; i++)
    {
        if (fila[i] > 0 && fila[i + 1] > 0)
        {
            contIntegrantes++;
        }
        else if (fila[i] < 0 && fila[i + 1] < 0)
        {
            contIntegrantes++;
        }
        else
        {
            if (contIntegrantes >= 2)
            {
                contTimes++;
                contIntegrantes = 1;
            }
        }
    }

    if (contIntegrantes >= 2)
    {
        contTimes++;
        contIntegrantes = 1;
    }

    return contTimes;
}

vector<int> maior_time(const vector<int> &fila)
{
    vecInt maiorTime;
    vector<vector<int>> times;
    int contIntegrantes{1};

    for (size_t i = 0; i < fila.size(); i++)
    {
        if (fila[i] > 0 && fila[i + 1] > 0)
        {
            contIntegrantes++;
        }
        else if (fila[i] < 0 && fila[i + 1] < 0)
        {
            contIntegrantes++;
        }
        else
        {
            if (contIntegrantes >= 2)
            {
                vecInt time;
                for (size_t j = i - contIntegrantes + 1; j < i + 1; j++)
                {
                    time.push_back(fila[j]);
                }
                times.push_back(time);
            }
            contIntegrantes = 1;
        }
    }

    int maior{0}, somaValores{0}, index;

    for (int i = 0; i < (int)times.size(); i++)
    {
        for (auto valor : times[i])
        {
            somaValores += abs(valor);
        }

        if (somaValores > maior)
        {
            maior = somaValores;
            somaValores = 0;
            index = i;
        }

        // cout << to_string(time) << endl;
    }

    for (auto valor : times[index])
    {
        maiorTime.push_back(valor);
    }

    return maiorTime;
}

int sem_time(vecInt fila)
{
    vector<vector<int>> times;
    int contIntegrantes{1};

    for (size_t i = 0; i < fila.size(); i++)
    {
        if (fila[i] > 0 && fila[i + 1] > 0)
        {
            contIntegrantes++;
        }
        else if (fila[i] < 0 && fila[i + 1] < 0)
        {
            contIntegrantes++;
        }
        else
        {
            if (contIntegrantes >= 2)
            {
                vecInt time;
                for (size_t j = i - contIntegrantes + 1; j < i + 1; j++)
                {
                    time.push_back(fila[j]);
                }
                times.push_back(time);
                contIntegrantes = 1;
            }
        }
    }

    int qntdIntegrantesTotal{0};
    for (auto time : times)
    {
        qntdIntegrantesTotal += time.size();
    }

    return fila.size() - qntdIntegrantesTotal;
}

int casais(vecInt fila)
{
    int qntdCasais{0};
    for (size_t i = 0; i < fila.size() - 1; i++)
    {
        for (size_t j = i + 1; j < fila.size(); j++)
        {
            if ((fila[i] > 0 && fila[j] < 0) || (fila[i] < 0 && fila[j] > 0))
            {
                if (abs(fila[i]) == abs(fila[j]))
                {
                    qntdCasais++;
                    fila[i] = 0;
                    fila[j] = 0;
                }
            }
        }
    }

    return qntdCasais;
}

int trios(vecInt fila)
{
    int qntdTrios{0};

    for (size_t i = 0; i < fila.size() - 2; i++)
    {
        for (size_t j = i + 1; j < fila.size() - 1; j++)
        {
            for (size_t k = j + 1; k < fila.size(); k++)
            {
                if (abs(fila[i]) == abs(fila[j]) && abs(fila[j]) == abs(fila[k]))
                {
                    fila[i] = 0;
                    fila[j] = 0;
                    fila[k] = 0;
                    qntdTrios++;
                }
            }
        }
    }

    return qntdTrios;
}

vecInt remove(const vecInt &fila, int pessoa)
{
    vecInt fila2 = fila;
    vecInt novaFila;
    for (auto &elem : fila2)
    {
        if (elem == pessoa)
        {
            elem = 0;
        }
    }

    for (auto elem : fila2)
    {
        if (elem != 0)
        {
            novaFila.push_back(elem);
        }
    }

    return novaFila;
}

vecInt insert(const vecInt &fila, int pessoa, int pos)
{
    vecInt fila2 = fila;

    if (pos >= 0 && pos < fila2.size())
    {
        vecInt::iterator it = fila2.begin() + pos - 1;
        fila2.insert(it, pessoa);
    }

    return fila2;
}

vecInt dance(const vecInt &fila)
{
    vecInt fila2 = fila;
    vecInt quemFicou;

    auto tirarPares = [&fila2]()
    {
        for (size_t i = 0; i < fila2.size() - 1; i++)
        {
            if (abs(fila2[i]) == abs(fila2[i + 1]))
            {
                fila2[i] = 0;
                fila2[i + 1] = 0;
            }
        }

        while (find(fila2.begin(), fila2.end(), 0) != fila2.end())
        {
            fila2.erase(find(fila2.begin(), fila2.end(), 0));
        }
    };

    tirarPares();
    tirarPares();

    return fila2;
}

int main()
{
    int value = 0;
    vecInt fila{3, -3, 3, -12, -5, 5, 12, -13, 1, -1};

    // cout << existe(fila, value) << endl;
    // cout << contar(fila, value) << endl;
    cout << to_string(dance(fila)) << endl;

    return 0;
}