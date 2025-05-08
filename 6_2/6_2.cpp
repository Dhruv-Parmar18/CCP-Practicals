#include <iostream>
using namespace std;

class Point
{
private:
    float x, y;

public:
    Point(float x = 0, float y = 0) : x(x), y(y) {}

    Point *shift(float dx, float dy)
    {
        this->x += dx;
        this->y += dy;
        return this;
    }

    void print() const
    {
        cout << "Updated Position: (" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    float x, y, dx1, dy1, dx2, dy2;

    cout << "Enter the original point (x y): ";
    cin >> x >> y;

    Point p(x, y);

    cout << "Enter the first shift (dx1 dy1): ";
    cin >> dx1 >> dy1;
    p.shift(dx1, dy1)->print();

    cout << "Enter the second shift (dx2 dy2): ";
    cin >> dx2 >> dy2;
    p.shift(dx2, dy2)->print();

    cout << "\n\nDhruv Parmar" << endl
         << "24CE071" << endl;

    return 0;
}