#include <iostream>
using namespace std;

void inputData(double &balance, double &annualTaxRate, int &months);
void processTransactions(int months, double balance, double annualTaxRate);
double getValidatedAmount(string message);

int main()
{
    int months;
    double annualTaxRate;
    double balance;

    inputData(balance, annualTaxRate, months);
    processTransactions(months, balance, annualTaxRate);

    return 0;
}

void inputData(double &balance, double &annualTaxRate, int &months)
{
    cout << "Enter initial balance: ";
    cin >> balance;

    cout << "Enter annual tax rate (%): ";
    cin >> annualTaxRate;

    cout << "Enter total number of months: ";
    cin >> months;
}

void processTransactions(int months, double balance, double annualTaxRate)
{
    double deposits[months];
    double withdrawals[months];
    double taxes[months];

    double totalDeposit = 0;
    double totalWithdrawal = 0;
    double totalTax = 0;

    double monthlyTaxRate = annualTaxRate / 12 / 100;

    for (int i = 0; i < months; i++)
    {
        cout << "\nMonth " << i + 1 << endl;

        deposits[i] = getValidatedAmount("Enter deposit amount: ");
        balance += deposits[i];
        totalDeposit += deposits[i];

        withdrawals[i] = getValidatedAmount("Enter withdrawal amount: ");
        balance -= withdrawals[i];
        totalWithdrawal += withdrawals[i];

        taxes[i] = balance * monthlyTaxRate;
        balance -= taxes[i];
        totalTax += taxes[i];
    }
    cout<<endl;
    cout << " Account Summary " << endl;
    cout << "Final Balance: " << balance << endl;
    cout << "Total Deposited: " << totalDeposit << endl;
    cout << "Total Withdrawn: " << totalWithdrawal << endl;
    cout << "Total Tax Deducted: " << totalTax << endl;
}

double getValidatedAmount(string message)
{
    double amount;
    do
    {
        cout << message;
        cin >> amount;
    } while (amount < 0);

    return amount;
}
