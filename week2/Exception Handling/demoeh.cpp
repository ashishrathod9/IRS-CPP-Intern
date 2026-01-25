#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Custom exception class
class InsufficientFundsException : public exception
{
private:
  string message;

public:
  InsufficientFundsException(const string &msg) : message(msg) {}
  const char *what() const noexcept override
  {
    return message.c_str();
  }
};

class BankAccount
{
private:
  double balance;
  string accountNumber;

public:
  BankAccount(string accNum, double initialBalance)
      : accountNumber(accNum), balance(initialBalance)
  {
    if (initialBalance < 0)
    {
      throw invalid_argument("Initial balance cannot be negative");
    }
  }

  void deposit(double amount)
  {
    if (amount <= 0)
    {
      throw invalid_argument("Deposit amount must be positive");
    }
    balance += amount;
    cout << "Deposited: $" << amount << endl;
  }

  void withdraw(double amount)
  {
    if (amount <= 0)
    {
      throw invalid_argument("Withdrawal amount must be positive");
    }
    if (amount > balance)
    {
      throw InsufficientFundsException(
          "Insufficient funds. Available: $" + to_string(balance));
    }
    balance -= amount;
    cout << "Withdrawn: $" << amount << endl;
  }

  double getBalance() const { return balance; }
};

// Function demonstrating division by zero
double divide(double numerator, double denominator)
{
  if (denominator == 0)
  {
    throw runtime_error("Division by zero error");
  }
  return numerator / denominator;
}

// Function demonstrating array access
int accessArray(int arr[], int size, int index)
{
  if (index < 0 || index >= size)
  {
    throw out_of_range("Array index out of bounds");
  }
  return arr[index];
}

int main()
{
  // Example 1: Basic exception handling
  cout << "=== Example 1: Division ===\n";
  try
  {
    double result = divide(10, 2);
    cout << "Result: " << result << endl;

    result = divide(10, 0);
    cout << "This won't print" << endl;
  }
  catch (runtime_error &e)
  {
    cout << "Caught exception: " << e.what() << endl;
  }

  // Example 2: Multiple catch blocks
  cout << "\n=== Example 2: Array Access ===\n";
  int numbers[] = {10, 20, 30, 40, 50};
  try
  {
    cout << "Element at index 2: " << accessArray(numbers, 5, 2) << endl;
    cout << "Element at index 10: " << accessArray(numbers, 5, 10) << endl;
  }
  catch (out_of_range &e)
  {
    cout << "Out of range error: " << e.what() << endl;
  }
  catch (exception &e)
  {
    cout << "General exception: " << e.what() << endl;
  }

  // Example 3: Custom exceptions with bank account
  cout << "\n=== Example 3: Bank Account ===\n";
  try
  {
    BankAccount account("ACC123", 1000.0);
    cout << "Initial balance: $" << account.getBalance() << endl;

    account.deposit(500);
    account.withdraw(300);

    cout << "Current balance: $" << account.getBalance() << endl;

    // This will throw InsufficientFundsException
    account.withdraw(2000);
  }
  catch (InsufficientFundsException &e)
  {
    cout << "Custom exception caught: " << e.what() << endl;
  }
  catch (invalid_argument &e)
  {
    cout << "Invalid argument: " << e.what() << endl;
  }
  catch (...)
  { // Catch-all handler
    cout << "Unknown exception occurred" << endl;
  }

  // Example 4: Exception in constructor
  cout << "\n=== Example 4: Constructor Exception ===\n";
  try
  {
    BankAccount invalidAccount("ACC456", -500); // Invalid balance
  }
  catch (invalid_argument &e)
  {
    cout << "Constructor exception: " << e.what() << endl;
  }

  cout << "\n=== Program continues normally ===\n";
  cout << "Exception handling allows graceful error recovery!" << endl;

  return 0;
}
