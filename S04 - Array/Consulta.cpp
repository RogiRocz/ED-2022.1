#include <iostream>
#include <vector>
#include <sstream> // String stream

using namespace std;

vector<int> matchingStrings(string e, string c);

int main(int argc, char const *argv[])
{
    int sizeE, sizeC;
    stringstream ss;
    string e, c;

    cin >> sizeC;
    cin.getline(c, c.max_size());
    cout << sizeC << c;

    return 0;
}
