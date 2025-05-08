#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    // Constructors
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex &other)
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex &other)
    {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload << operator for output
    friend ostream &operator<<(ostream &out, const Complex &c)
    {
        out << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i";
        return out;
    }

    // Overload >> operator for input
    friend istream &operator>>(istream &in, Complex &c)
    {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};

// Optional: Batch operation function
void batchAdd(const vector<Complex> &nums)
{
    Complex sum;
    for (const auto &num : nums)
    {
        sum = sum + num;
    }
    cout << "\nSum of all complex numbers: " << sum << endl;
}

int main()
{
    Complex c1, c2;

    // Input two complex numbers
    cout << "Input first complex number:\n";
    cin >> c1;
    cout << "\nInput second complex number:\n";
    cin >> c2;

    // Perform addition and subtraction
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    // Display results
    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Addition Result: " << sum << endl;
    cout << "Subtraction Result: " << diff << endl;

    // Optional: Batch operations
    vector<Complex> list = {c1, c2, Complex(3, 4), Complex(-1.5, 2.5)};
    batchAdd(list);

    cout << "\n\nDhruv Parmar" << endl
         << "24CE071" << endl;

    return 0;
}