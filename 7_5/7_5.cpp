#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to return a user-defined manipulator for currency formatting
ostream &currency(ostream &os)
{
    os << "rupees ";
    return os;
}

// Structure to store student data
struct Student
{
    string name;
    float marks;
    float tuitionFee;
};

// Function to display a formatted table of students
void displayStudents(Student students[], int count)
{
    cout << "\n======= Student Academic Report =======\n";
    cout << left << setw(20) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < count; ++i)
    {
        cout << left << setw(20) << students[i].name
             << setw(10) << fixed << setprecision(2) << students[i].marks
             << currency << setw(14) << fixed << setprecision(2) << students[i].tuitionFee << endl;
    }
}

int main()
{
    // Updated data: name, marks, tuition fee
    Student students[] = {
        {"Aryan", 88.5f, 45000.00f},
        {"Rudra", 91.0f, 47000.50f},
        {"Soham", 85.25f, 44000.75f},
        {"Zahid", 89.75f, 46000.00f}};

    int studentCount = sizeof(students) / sizeof(students[0]);

    displayStudents(students, studentCount);

    cout << "\n\nDhruv Parmar" << endl
         << "24CE071" << endl;

    return 0;
}