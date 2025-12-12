#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;
    
public:
    BankAccount(double initial_amount) {
        balance = initial_amount;
    }
    
    void deposit(double amount) {
        if (amount > 0) {
            balance = balance + amount;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance = balance - amount;
            return true;
        }
        return false;
    }
    
    double getbalance() {
        return balance;
    }
};

int main() {
    BankAccount ravi_account(5000);
    
    cout << "ravi initial balance: " << ravi_account.getbalance() << endl;
    
    ravi_account.deposit(1500);
    cout << "after deposit: " << ravi_account.getbalance() << endl;
    
    bool success = ravi_account.withdraw(800);
    if (success) {
        cout << "after withdrawal: " << ravi_account.getbalance() << endl;
    }
    
    return 0;
}