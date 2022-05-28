#include <iostream>
#include <sstream> // String stream

using namespace std;

struct Vector
{
    int size{0};
    int capacity{0};
    int *data{nullptr};

    Vector(int c)
    {
        this->capacity = c;
        this->data = new int[c];
    }

    void operator=(const Vector &other)
    {
        this->capacity = other.capacity;
        this->size = other.size;
        delete[] this->data;
        this->data = new int[other.capacity];
        for (int i = 0; i < other.size; i++)
        {
            this->data[i] = other.data[i];
        }
    }

    Vector(Vector &other)
    {
        *this = other;
    }

    void add(int value)
    {
        if (this->size + 1 > this->capacity)
        {
            this->size++;
            auto newData = new int[this->size];
            for (int i = 0; i < this->size - 1; i++)
            {
                newData[i] = this->data[i];
            }
            newData[this->size - 1] = value;
			delete [] this->data;
            this->data = newData;
        }
    }

    ~Vector()
    {
        delete this->data;
        this->data = nullptr;
    }
};

enum CMD
{
    invalid = -1,
    End,
    Init,
    Status,
    Add,
    Show
};

CMD stringToCMD(string s)
{
    if (s == "end")
    {
        return End;
    }
    if (s == "init")
    {
        return Init;
    }
    if (s == "status")
    {
        return Status;
    }
    if (s == "add")
    {
        return Add;
    }
    if (s == "show")
    {
        return Show;
    }

    return invalid;
}

string exibir(Vector vet)
{
    stringstream ss;
    ss << "[ ";
    for (int i = 0; i < vet.size; i++)
    {
        ss << vet.data[i] << ' ';
    }
    ss << "]";
    return ss.str();
}

int main()
{
    string line, cmd;
    int value;
    bool continua = true;

    Vector v(0);

    while (continua)
    {
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
        switch (stringToCMD(cmd))
        {
        case End:
            continua = false;
            break;
        case Init:
            ss >> value;
            v = Vector(value);
            break;
        case Status:
            cout << "size: " << v.size << " capacity: " << v.capacity << endl;
            break;
        case Add:
            while (ss >> value)
            {
                v.add(value);
            }
            break;
        case Show:
            cout << exibir(v) << endl;
            break;
        default:
            cout << "Comando invalido" << endl;
            break;
        }
    }

    return 0;
}