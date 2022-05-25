#include <iostream>
#include <sstream> // String stream

using namespace std;

struct Vector
{
    int size;
    int capacity;
    int *data;

    Vector(int c) : size(0), capacity(c), data(nullptr) {}
};

enum CMD{
	invalid = -1, End, Init, Status, Add, Show
};

CMD stringToCMD(string s){
	if(s == "end"){return End;}
	if(s == "init"){return Init;}
	if(s == "status"){return Status;}
	if(s == "add"){return Add;}
	if(s == "show"){return Show;}

	return invalid;
}

string exibir(Vector *vet)
{
    stringstream ss;
    ss << "[ ";
    for (int i = 0; i < vet->size; i++)
    {
        ss << vet->data[i] << ' ';
    }
    ss << "]";
    return ss.str();
}

Vector *create(int capacity)
{
    Vector *v = new Vector(capacity);
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
    if (vet != nullptr)
    {
        if (vet->size + 1 > vet->capacity)
        {
            int newCapacity = 2 * vet->capacity;
            vet->capacity = newCapacity;
        }
        vet->size++;
		auto newData = new int[vet->size];
		for(int i = 0; i < vet->size - 1; i++){
			newData[i] = vet->data[i];
		}
		newData[vet->size - 1] = value;
		vet->data = newData;
    }
}

int main()
{
    string line, cmd;
    int value;
	bool continua = true;

    Vector *v = create(0);
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
            if (v != nullptr)
            {
                destroy(v);
            }
            v = create(value);
			break;
        case Status:
            cout << "size: " << v->size << " capacity: " << v->capacity << endl;
            break;
        case Add:
            while (ss >> value)
            {
                add(v, value);
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