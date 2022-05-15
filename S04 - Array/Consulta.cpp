#include <iostream>
#include <vector>
#include <sstream> // String stream

using namespace std;

string exibir(vector<int> entrada)
{
    stringstream ss;
    for (auto elem : entrada)
    {
        ss << elem << ' ';
    }

    return ss.str();
}

vector<int> matchingStrings(vector<string> c, vector<string> b)
{
    vector<int> result;
    for (auto elemB : b)
    {
        pair<string, int> match(elemB, 0);
        for (auto elemC : c)
        {
            if (elemC == elemB)
            {
                match.second++;
            }
        }
        result.push_back(match.second);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int sizeCon, sizeBus;
    string strCon, strBus;
    vector<string> consulta, busca;

    cin >> sizeCon;

    for (size_t i = 0; i < sizeCon; i++)
    {
        cin >> strCon;
        consulta.push_back(strCon);
    }

    cin >> sizeBus;

    for (size_t i = 0; i < sizeBus; i++)
    {
        cin >> strBus;
        busca.push_back(strBus);
    }

    cout << exibir(matchingStrings(consulta, busca)) << endl;
    // cout << sizeCon << " " << exibir(con) << " " << sizeBus << " " << exibir(bus);

    return 0;
}