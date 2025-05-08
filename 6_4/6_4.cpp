#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base constructor called" << endl;
    }

    virtual ~Base()
    {
        cout << "Base destructor called!" << endl;
    }

    virtual void show()
    {
        cout << "Base class show function" << endl;
    }
};

class Derived : public Base
{
private:
    int *data;

public:
    Derived()
    {
        data = new int(42);
        cout << "Derived constructor : Resource Allocated" << endl;
    }

    ~Derived()
    {
        delete data;
        cout << "Derived destructor : Resources Deallocated" << endl;
    }
};

int main()
{
    Base *obj = new Derived();
    obj->show();

    delete obj;

    cout << "\n\nDhruv Parmar" << endl
         << "24CE071" << endl;

    return 0;
}