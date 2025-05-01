/*
In a growing city, a newly established bank sought to streamline its operations by implementing a
digital system to manage customer Accounts. The management envisioned a system where each
Account would store details about the Account holder, their unique Account number, and the current
Balance. To ensure flexibility and Accounturacy, they required functionalities for creating Accounts with
varying initial Balances, Depositing Money, Withdrawing funds (with checks for sufficient Balance), and
generating detailed Account summaries.
The bank's IT team faced the challenge of developing a robust solution. They began by sketching out
the essential features of the system. The team highlighted that new Accounts could be created in two
ways: one with no initial Balance, and another with specified Account details and a starting Amount.
Additionally, they recognized the need for reliable mechanisms to handle Deposits and Withdrawals,
ensuring proper validation to prevent overdrafts. Displaying Account details in a clear format was also
prioritized for customer communication.
To ensure scalability, the team decided to simulate the system by creating multiple Accounts using the
proposed methods. They tested various scenarios, such as Depositing and Withdrawing Amounterent
Amounts, handling edge cases like insufficient funds, and verifying that the Account summaries were
Accurate. This iterative approach helped them refine the system and ensure its readiness for
deployment.

AccountNum
Name
Balance
CreateAccount(initialBalance) //with default parameters
Deposit()
Withdraw() //without overdraft
AccountSummary() //viewData() list of accounts and details
minimum balance only for Withdraw not create
account search
ERRORS - MIN BAL, NO ACCount FOUND

psuedocode per fn and class diagram
coding convention - spaces comments camelcase, even in class diagram
*/

#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    BankAccount(string holder, string number, double initialBalance)
        : accountHolder(holder), accountNumber(number), balance(initialBalance) {}

    BankAccount(string holder, string number)
        : accountHolder(holder), accountNumber(number), balance(0.0) {}

    string getAccountHolder() const
    {
        return accountHolder;
    }

    string getAccountNumber() const
    {
        return accountNumber;
    }

    double getBalance() const
    {
        return balance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0)
        {
            if (balance >= amount)
            {
                balance -= amount;
                cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << endl;
            }
            else
            {
                cout << "Insufficient funds. Current balance: $" << balance << endl;
            }
        }
        else
        {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        }
    }

    void displayAccountSummary() const
    {
        cout << "\n--- Account Summary ---" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "-----------------------" << endl;
    }
};

int main()
{
    string holder, number;
    double initialBalance, depositAmount, withdrawAmount;

    cout << "--- Create Account 1 ---" << endl;
    cout << "Enter Account Holder Name: ";
    getline(cin >> ws, holder);
    cout << "Enter Account Number: ";
    getline(cin >> ws, number);
    cout << "Enter Initial Balance: $";
    cin >> initialBalance;
    BankAccount account1(holder, number, initialBalance);
    account1.displayAccountSummary();

    cout << "\n--- Create Account 2 (No Initial Balance) ---" << endl;
    cout << "Enter Account Holder Name: ";
    getline(cin >> ws, holder);
    cout << "Enter Account Number: ";
    getline(cin >> ws, number);
    BankAccount account2(holder, number);
    account2.displayAccountSummary();

    cout << "\n--- Deposit to Account 1 ---" << endl;
    cout << "Enter Deposit Amount: $";
    cin >> depositAmount;
    account1.deposit(depositAmount);
    account1.displayAccountSummary();

    cout << "\n--- Deposit to Account 2 ---" << endl;
    cout << "Enter Deposit Amount: Rupees ";
    cin >> depositAmount;
    account2.deposit(depositAmount);
    account2.displayAccountSummary();

    cout << "\n--- Withdraw from Account 1 ---" << endl;
    cout << "Enter Withdrawal Amount: Rupees ";
    cin >> withdrawAmount;
    account1.withdraw(withdrawAmount);
    account1.displayAccountSummary();

    cout << "\n--- Withdraw from Account 2 ---" << endl;
    cout << "Enter Withdrawal Amount: Rupees ";
    cin >> withdrawAmount;
    account2.withdraw(withdrawAmount);
    account2.displayAccountSummary();

    cout << "\n\nDhruv Parmar" << endl << "24CE071" << endl;

    return 0;
}