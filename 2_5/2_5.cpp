/*
A regional banking institution sought to improve its loan management process by developing a system
that could efficiently handle loan details for applicants. The system was expected to streamline the
calculation of monthly EMIs (Equated Monthly Instalments) and provide detailed loan summaries for
customers. This initiative aimed to enhance customer experience by offering accurate and transparent
information about their loans.
To meet these requirements, the bank's technology team was tasked with designing a solution. They
envisioned a system where each loan would be uniquely identified by a loan ID, and additional details
such as the applicant's name, total loan amount, annual interest rate, and loan tenure in months
would be stored. The team also emphasized the importance of accurately calculating the EMI using a
standard formula based on the loan amount, interest rate, and tenure. The formula incorporated
compound interest principles to determine the fixed monthly payment for the loan term.
EMI = P * R * (1 + R)^T / ((1 + R)^T - 1)
As part of the implementation, the developers planned to initialize loans either with default values for
testing purposes or with actual customer data provided at the time of application. The system needed
to include a feature to display comprehensive loan details, including the calculated EMI, in a
customerfriendly format. This functionality was intended to aid both customers and bank staff in managing
loan-related queries effectively.

loan management:
emi
loan summary()
emi()
loan id
name
total amount
interest rate
tenure(months)



correct and efficient code///
output formatting///
indentation///
naming///
comments///
*/

#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class loan
{
private:
    int loan_Id;
    string applicant_name;
    double loan_amount;
    double interest_Rate; // ANNUAL RATE IS PERCENTAGE
    int loanTerm;

public:
    loan() // default constructor to initialize value to default
    {
        loan_Id = 0;
        applicant_name = "INPUT NOT GIVEN";
        loan_amount = 0.0;
        interest_Rate = 0.0;
        loanTerm = 0;
    }
    loan(int Id, string name, double amount, double Rate, int loan_tenure)
    // parametrized constructor to initialize with user inputs
    {
        loan_Id = Id;
        applicant_name = name;
        loan_amount = amount;
        interest_Rate = Rate;
        loanTerm = loan_tenure;
    }

    // Member function to calculate monthly EMI
    double calculateEMI()
    {
        double p = loan_amount;

        // Convert annual interest rate to monthly rate
        double r = (interest_Rate / 100) / 12;
        // Use the EMI formula
        int t = loanTerm;
        double EMI = p * r * pow(1 + r, t) / (pow(1 + r, t) - 1);
        return EMI;
    }

    // Member function to display loan details
    void displayLoandetails()
    {
        double EMI = calculateEMI();
        cout << "Loan ID: " << loan_Id << endl;
        cout << "Applicant Name: " << applicant_name << endl;
        cout << "Loan Amount: " << loan_amount << endl;
        cout << "Interest Rate: " << interest_Rate << "%" << endl;
        cout << "Loan Term (in months): " << loanTerm << endl;
        cout << "Monthly EMI: " << EMI << endl;
    }
};

int main()
{
    int loan_id;
    string applicantname;
    double loan_amount, interset_Rate;
    int loanTerm;

    cout << "Enter the loan Id:";
    cin >> loan_id;
    cin.ignore();

    cout << "Enter Applicant Name::";
    getline(cin, applicantname);

    cout << "Enter the loan Amount:";
    cin >> loan_amount;

    cout << "Enter the interset Rate:";
    cin >> interset_Rate;

    cout << "Enter the loan Tenure(month):";
    cin >> loanTerm;

    // create a loan object for parametrized constructor
    loan Loan(loan_id, applicantname, loan_amount, interset_Rate, loanTerm);

    Loan.displayLoandetails();

    cout << "\n\nDhruv Parmar" << endl
         << "24CE071" << endl;

    return 0;
}