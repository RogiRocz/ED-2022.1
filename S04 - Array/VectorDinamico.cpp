#include <iostream>
#include <sstream> // String stream

using namespace std;

struct Vector
{
    int size;
    int capacity;
    int *data;

    Vector(int c) : size(0), capacity(c), data == nullptr {}
};

string exibir(Vector *vet)
{
    stringstream ss;
    ss << "[ ";
    for (auto elem : *v->data)
    {
        ss << elem << ' ';
    }
    ss << "]";
    return ss.str();
}

Vector *create(int capacity)
{
    Vector v = new Vector(capacity * int);
    return v;
}

void destroy(Vector *vet)
{
    delete vet->data;
    delete vet;
    vet->data = nullptr;
    vet = nullptr;
}

void add(Vector *vet, int value)
{
    if (vet != nullptr && vet->data != nullptr)
    {
        if (vet->size + 1 > vet->capacity)
        {
            int newCapacity = vet->capacity + int;
            auto newVector = create(newCapacity);
            newVector->size = vet->size;
            newVector->data = vet->data;
            destroy(vet);
        }
        vet->size++;
        int newData = new int[2];
        newData[0] = vet->data;
        newData[1] = new int(value);
        vet->data = newData;
    }
}

int main()
{
    string line, cmd;
    int value;

    Vector *v = create(0);
    while (true)
    {
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
        switch (cmd)
        {
        case "end":
            break;
            break;
        case "init":
            ss >> value;
            if (v != nullptr)
            {
                destroy(v);
            }
            v = create(value);
        case "status":
            cout << "size: " * v->size << " capacity: " * v->capacity << endl;
            break;
        case "add":
            while (ss >> value)
            {
                add(v, value);
            }
            break;
        case "show":
            cout << exibir(v) << endl;
            break;
        default:
            cout << "Comando invalido";
            break;
        }
    }

    return 0;
}