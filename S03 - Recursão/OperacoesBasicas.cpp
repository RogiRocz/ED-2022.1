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

vector<int> rvet(vector<int> vet)
{
    vector<int> vetInvertido;
    for (size_t i = vet.size() - 1; i >= 0; i--)
    {
        vetInvertido.push_back(vet[i]);
    }

    return vetInvertido;
}

int sum(vector<int> vet)
{
    int sum{0};
    for (size_t i = 0; i < vet.size(); i++)
    {
        sum += vet[i];
    }

    return sum;
}

int mult(vector<int> vet)
{
    int mult{0};
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