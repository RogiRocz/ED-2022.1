#include <iostream>
#include <vector>

using namespace std;

void exibir(vector<int> vet){
    cout << "[ ";
    for(auto elem : vet){
        cout << elem << ' ';
    }
    cout << "]" << endl;
}

void rotar(vector<int> &vet, int rot){
    if(rot == 0){return;}
    int last = vet.back();
    vet.pop_back();
    vet.insert(vet.begin(), last);
    rotar(vet, rot - 1);
}

int main() {
    int size, rot;
    cin >> size >> rot;
    vector<int> vet;
    
    for(int i = 0; i < size; i++)
    {
        vet.push_back(i + 1);
    }
    
    exibir(vet);
    rotar(vet, rot);
    exibir(vet);

    return 0;
}
