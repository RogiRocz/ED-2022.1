#include <iostream>
#include <vector>
#include <sstream> // String stream

using namespace std;

vector<int> entrada()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    while (ss >> value)
    {
        vet.push_back(value);
    }

    return vet;
}

string exibirVet(vector<int> vet)
{
    stringstream ss;

    ss << "[ ";
    for (auto elem : vet)
    {
        ss << elem << ' ';
    }
    ss << ']';

    return ss.str();
}

/* vector<int> rvet2(vector<int> vet, vector<int>::iterator begin, vector<int>::iterator end)
{
    // [1,2,3,4]
    if (begin == end)
    {
        return vector<int>{*end}; // [1]
    }
    // Gabriel tua voz cortou

    // [1,2,3] -> [3.2,1]
    vector<int> result = rvet2(begin, end - 1);

    // [4,3,2,1]
    result.insert(begin, *end);

    // [4,3,2,1]
    return result;
} */

vector<int> rvet(vector<int> vet)
{
    if (vet.size() == 1)
    {
        return vet;
    }

    int first = vet.front();
    vet.erase(vet.begin());
    vector<int> vetInvertido = rvet(vet);
    vetInvertido.push_back(first);

    return vetInvertido;
}

int sum(vector<int> vet)
{
    if (vet.size() == 1)
    {
        return vet.front();
    }

    int soma{0};
    // auto it = vet.begin();
    soma += sum(vet + 1) + vet.front();

    return soma;
}

int mult(vector<int> vet)
{
    int mult{1};
    for (size_t i = 0; i < vet.size(); i++)
    {
        mult *= vet[i];
    }

    return mult;
}

int min(vector<int> vet)
{
    int minValue = vet[0];
    for (size_t i = 0; i < vet.size(); i++)
    {
        minValue = min(minValue, vet[i]);
    }

    return minValue;
}

vector<int> inv(vector<int> vet)
{
    return rvet(vet);
}

void saida(const vector<int> &vet)
{
    cout << "vet: " << exibirVet(vet) << endl;
    cout << "rvet: " << exibirVet(rvet(vet)) << endl;
    cout << "sum: " << sum(vet) << endl;
    cout << "mult: " << mult(vet) << endl;
    cout << "min: " << min(vet) << endl;
    cout << "inv: " << exibirVet(inv(vet)) << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> vet;

    vet = entrada();
    saida(vet);

    return 0;
}
