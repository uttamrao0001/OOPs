#include <iostream>
using namespace std;

// Wrapping data and functions together to protect data from direct access.
// Use private/protected access specifiers.Use public access specifier for functions that can be accessed from outside the class.

class BankAccount
{
private:
    double balance;

public:
    void setBalance(double b) { balance = b; }
    double getBalance() { return balance; }
};

int main()
{
    BankAccount account;
    account.setBalance(5000);
    cout << "Balance: " << account.getBalance() << endl;
    return 0;
}
