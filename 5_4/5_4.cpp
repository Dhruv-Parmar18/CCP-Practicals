#include <iostream>
#include <queue>
using namespace std;

// Forward declaration to resolve circular dependency
class Fahrenheit;

// Class to represent Celsius temperature
class Celsius
{
    float celsiusTemp; // Celsius temperature value
public:
    // Constructor with default value
    Celsius(float temp = 0) : celsiusTemp(temp) {}

    // Type conversion to Fahrenheit
    operator Fahrenheit();

    // Equality operator to compare two Celsius objects
    bool operator==(const Celsius &other) const
    {
        return celsiusTemp == other.celsiusTemp;
    }

    // Function to take input from user
    void input()
    {
        cout << "Enter Celsius: ";
        cin >> celsiusTemp;
    }

    // Function to display Celsius temperature
    void show() const
    {
        cout << celsiusTemp << "°C";
    }

    // Getter
    float get() const { return celsiusTemp; }
};

// Class to represent Fahrenheit temperature
class Fahrenheit
{
    float fahrenheitTemp; // Fahrenheit temperature value
public:
    // Constructor with default value
    Fahrenheit(float temp = 0) : fahrenheitTemp(temp) {}

    // Type conversion to Celsius
    operator Celsius()
    {
        return Celsius((fahrenheitTemp - 32) * 5.0 / 9.0);
    }

    // Equality operator to compare two Fahrenheit objects
    bool operator==(const Fahrenheit &other) const
    {
        return fahrenheitTemp == other.fahrenheitTemp;
    }

    // Function to take input from user
    void input()
    {
        cout << "Enter Fahrenheit: ";
        cin >> fahrenheitTemp;
    }

    // Function to display Fahrenheit temperature
    void show() const
    {
        cout << fahrenheitTemp << "°F";
    }

    // Getter
    float get() const { return fahrenheitTemp; }
};

// Define Celsius to Fahrenheit conversion logic
Celsius::operator Fahrenheit()
{
    return Fahrenheit((celsiusTemp * 9.0 / 5.0) + 32);
}

// Function to compare Celsius and Fahrenheit temperatures
bool areEqual(Celsius c, Fahrenheit f)
{
    return c == Celsius(f); // Convert Fahrenheit to Celsius and compare
}

// Main application logic
void temperatureSystem()
{
    queue<Celsius> celsiusQueue;       // Queue to store Celsius objects (dynamic storage)
    queue<Fahrenheit> fahrenheitQueue; // Queue to store Fahrenheit objects
    Celsius celsiusArray[100];         // Static array for Celsius
    Fahrenheit fahrenheitArray[100];   // Static array for Fahrenheit
    int storageIndex = 0;              // Index to track array usage

    int choice, storageType;

    // Ask user for preferred storage mechanism
    cout << "Storage Type: 1. Queue (FIFO)  2. Array (Static) :: ";
    cin >> storageType;

    do
    {
        // Menu options
        cout << "\n--- Temperature Conversion Menu ---\n";
        cout << "1. Convert Celsius to Fahrenheit\n";
        cout << "2. Convert Fahrenheit to Celsius\n";
        cout << "3. Compare Celsius and Fahrenheit\n";
        cout << "4. Show All Stored Conversions\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Celsius celsiusObj;
        Fahrenheit fahrenheitObj;

        switch (choice)
        {
        case 1:
            // Celsius to Fahrenheit conversion
            celsiusObj.input();
            fahrenheitObj = celsiusObj;
            celsiusObj.show();
            cout << " = ";
            fahrenheitObj.show();
            cout << "\n";

            if (storageType == 1)
            {
                celsiusQueue.push(celsiusObj);
                fahrenheitQueue.push(fahrenheitObj);
            }
            else
            {
                celsiusArray[storageIndex] = celsiusObj;
                fahrenheitArray[storageIndex++] = fahrenheitObj;
            }
            break;

        case 2:
            // Fahrenheit to Celsius conversion
            fahrenheitObj.input();
            celsiusObj = fahrenheitObj;
            fahrenheitObj.show();
            cout << " = ";
            celsiusObj.show();
            cout << "\n";

            if (storageType == 1)
            {
                celsiusQueue.push(celsiusObj);
                fahrenheitQueue.push(fahrenheitObj);
            }
            else
            {
                celsiusArray[storageIndex] = celsiusObj;
                fahrenheitArray[storageIndex++] = fahrenheitObj;
            }
            break;

        case 3:
            // Compare values
            celsiusObj.input();
            fahrenheitObj.input();
            cout << (areEqual(celsiusObj, fahrenheitObj) ? "Temperatures are Equal.\n" : "Temperatures are Not Equal.\n");
            break;

        case 4:
            // Show all stored conversions
            cout << "\n--- Stored Conversions ---\n";
            if (storageType == 1)
            {
                // From queue
                auto tempCQueue = celsiusQueue;
                auto tempFQueue = fahrenheitQueue;

                while (!tempCQueue.empty())
                {
                    tempCQueue.front().show();
                    cout << " = ";
                    tempFQueue.front().show();
                    cout << "\n";
                    tempCQueue.pop();
                    tempFQueue.pop();
                }
            }
            else
            {
                // From array
                for (int i = 0; i < storageIndex; ++i)
                {
                    celsiusArray[i].show();
                    cout << " = ";
                    fahrenheitArray[i].show();
                    cout << "\n";
                }
            }
            break;

        case 0:
            // Exit
            break;
        default:
            cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 0);
}
// Entry point of the program
int main()
{
    temperatureSystem();

    cout << "\n\nDhruv Parmar" << endl
         << "24CE071" << endl;

    return 0;
}