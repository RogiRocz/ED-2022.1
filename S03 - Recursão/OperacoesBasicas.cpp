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

    int result{0};
    int first = vet.front();
    vet.erase(vet.begin());
    result += sum(vet) + first;

    return result;
}

int mult(vector<int> vet)
{
    int result{1};
    if (vet.size() == 1)
    {
        return vet.front();
    }
    
    int first = vet.front();
    vet.erase(vet.begin());
    result *= first * mult(vet);

    return result;
}

int menor(vector<int> vet)
{
    int minus {0};
    if (vet.size() == 1)
    {
        return vet.front();
    }

    int first = vet.front();
    vet.erase(vet.begin());
    minus = min(first, menor(vet));

    return minus;
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
    cout << "min: " << menor(vet) << endl;
    cout << "inv: " << exibirVet(inv(vet)) << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> vet;

    vet = entrada();
    saida(vet);

    return 0;
}
