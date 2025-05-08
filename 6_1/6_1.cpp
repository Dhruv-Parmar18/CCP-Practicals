#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *data;
    int size;
    int capacity;

    void resize()
    {
        capacity *= 2;
        cout << "Resize Called !" << endl;
        int *newData = new int[capacity];
        for (int i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    DynamicArray(int initialCapacity = 4)
    {
        capacity = initialCapacity;
        data = new int[capacity];
        size = 0;
    }

    ~DynamicArray()
    {
        delete[] data;
    }

    void insert(int value)
    {
        if (size == capacity)
        {
            resize();
        }
        data[size++] = value;
    }

    void remove(int index)
    {
        if (index >= size)
        {
            cerr << "Index out of bounds.\n";
            return;
        }
        for (int i = index; i < size - 1; ++i)
        {
            data[i] = data[i + 1];
        }
        --size;
    }

    int get(int index) const
    {
        if (index >= size || index < 0)
        {
            cerr << "Index out of bounds.\n";
            return -1;
        }
        return data[index];
    }

    void set(int index, int value)
    {
        if (index >= size)
        {
            cerr << "Index out of bounds.\n";
            return;
        }
        data[index] = value;
    }

    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void print() const
    {
        cout << "[";
        for (int i = 0; i < size; ++i)
        {
            cout << data[i];
            if (i != size - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
};
int main()
{
    DynamicArray arr;

    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);
    arr.print();
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);

    cout << "\n\nDhruv Parmar" << endl
         << "24CE071" << endl;

    return 0;
}