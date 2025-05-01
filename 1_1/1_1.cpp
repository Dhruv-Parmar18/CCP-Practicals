/*
A bank wants to create a simple system to manage customer bank accounts. The system should
allow customers to perform basic banking operations such as depositing money, withdrawing
money, and checking their account balance.
Each bank account will need to have an account holder's name, a unique account number, and
a balance. Deposits should increase the account balance, while withdrawals should only be
allowed if there are sufficient funds in the account. If an attempt is made to withdraw more
money than is available, an error message should be displayed. Customers should also have the
ability to view their account balance whenever required.
The system must be designed using Object-Oriented Programming principles, focusing on
creating a simple and efficient solution to manage the accounts effectively. The system should
ensure that all account details are secure and accessible only through authorized methods.


deposit()
withdraw()
balance()

name
acc num
balance
*/

#include <iostream>
using namespace std;

class BankAccount
{
private:
    char accountHolder[50];
    char accountNumber[30];
    double balance;

public:
    BankAccount(const char holder[], const char accNum[], double initialBalance = 0.0)
    {
        int i = 0;
        while (holder[i] != '\0' && i < 49)
        {
            accountHolder[i] = holder[i];
            i++;
        }
        accountHolder[i] = '\0';

        i = 0;
        while (accNum[i] != '\0' && i < 19)
        {
            accountNumber[i] = accNum[i];
            i++;
        }
        accountNumber[i] = '\0';

        balance = (initialBalance >= 0) ? initialBalance : 0.0;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful! New balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > balance)
        {
            cout << "Insufficient balance." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal successful! Remaining balance: $" << balance << endl;
        }
    }

    void checkBalance()
    {
        cout << "Account Balance: $" << balance << endl;
    }

    void getAccountInfo()
    {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        checkBalance();
    }
};

int main()
{
    char name[50], accNum[20];
    double initialBalance, amount;
    int choice;

    cout << "Enter account holder name: ";
    cin.getline(name, 50);
    cout << "Enter account number: ";
    cin.getline(accNum, 20);
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account1(name, accNum, initialBalance);

    do
    {
        cout << "\n1. View Account Info\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            account1.getAccountInfo();
            break;
        case 2:
            cout << "Enter deposit amount: ";
            cin >> amount;
            account1.deposit(amount);
            break;
        case 3:
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            account1.withdraw(amount);
            break;
        case 4:
            account1.checkBalance();
            break;
        case 5:
            cout << "Thank you! Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    cout << "\n\nDhruv Parmar" << endl << "24CE071" << endl;
    
    return 0;
}