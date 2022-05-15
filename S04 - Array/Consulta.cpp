#include <iostream>
#include <vector>
#include <sstream> // String stream

using namespace std;

vector<int> matchingStrings(string e, string c);

string exibir(vector<string> entrada)
{
    stringstream ss;
    for (auto elem : entrada)
    {
        ss << elem;
    }

    return ss.str();
}

int main(int argc, char const *argv[])
{
    int sizeCon, sizeBus;
    string strCon, strBus;
    vector<string> con, bus;

    cin >> sizeCon;

    for (size_t i = 0; i < sizeCon; i++)
    {
        cin >> strCon;
        con.push_back(strCon);
    }

    cin >> sizeBus;

    for (size_t i = 0; i < sizeBus; i++)
    {
        cin >> strBus;
        bus.push_back(strBus);
    }

    cout << sizeCon << exibir(con) << sizeBus << exibir(bus);

    return 0;
}