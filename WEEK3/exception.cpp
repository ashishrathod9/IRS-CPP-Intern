#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
using namespace std;

// ============================================
// CUSTOM EXCEPTION CLASS
// ============================================
class NegativeNumberException : public exception {
private:
    int errorValue;
public:
    NegativeNumberException(int val) : errorValue(val) {}
    
    const char* what() const noexcept override {
        return "Negative number error detected!";
    }
    
    int getErrorValue() const {
        return errorValue;
    }
};

// ============================================
// RESOURCE CLASS FOR EXCEPTION PROPAGATION
// ============================================
class ResourceManager {
public:
    ResourceManager() {
        cout << "\n[Resource Created]" << endl;
    }
    ~ResourceManager() {
        cout << "[Resource Destroyed]" << endl;
    }
};

// ============================================
// FUNCTION DECLARATIONS WITH noexcept
// ============================================
void safeFunction(int x) noexcept {
    cout << "\nSafe function called with: " << x << endl;
}

void riskyFunction(int x) noexcept(false) {
    if (x < 0) {
        throw NegativeNumberException(x);
    }
    cout << "Risky function executed successfully with: " << x << endl;
}

// ============================================
// DEMONSTRATION FUNCTIONS
// ============================================

// Example 1: Built-in Type Exception
void demoBuiltInException() {
    cout << "\n========== DEMO 1: Built-in Type Exception ==========\n";
    int number = 7;
    try {
        if (number % 2 != 0) {
            throw -1;
        }
    }
    catch (int errorCode) {
        cout << "Exception Caught: " << errorCode << endl;
    }
}

// Example 2: Standard Exception
void demoStandardException() {
    cout << "\n========== DEMO 2: Standard Exception ==========\n";
    vector<int> numbers = {10, 20, 30};
    
    try {
        numbers.at(10);
    }
    catch (out_of_range& err) {
        cout << "Caught: " << err.what() << endl;
    }
}

// Example 3: Custom Exception
void demoCustomException() {
    cout << "\n========== DEMO 3: Custom Exception ==========\n";
    int testValues[] = {15, -8, 25};
    
    for (int val : testValues) {
        try {
            riskyFunction(val);
        }
        catch (NegativeNumberException& err) {
            cout << "Exception caught: " << err.what() 
                 << " | Value = " << err.getErrorValue() << endl;
        }
    }
}

// Example 4: Multiple Catch Blocks
void demoMultipleCatchBlocks() {
    cout << "\n========== DEMO 4: Multiple Catch Blocks ==========\n";
    
    int testCase = 2;
    
    try {
        if (testCase == 1) {
            throw invalid_argument("Invalid argument detected");
        }
        else if (testCase == 2) {
            throw out_of_range("Out of range detected");
        }
        else {
            throw "Unknown error type";
        }
    }
    catch (invalid_argument& err) {
        cout << "Caught invalid_argument: " << err.what() << endl;
    }
    catch (out_of_range& err) {
        cout << "Caught out_of_range: " << err.what() << endl;
    }
    catch (...) {
        cout << "Caught an unknown exception" << endl;
    }
}

// Example 5: Catch by Value
void demoCatchByValue() {
    cout << "\n========== DEMO 5: Catch by Value ==========\n";
    try {
        throw runtime_error("Runtime error occurred");
    }
    catch (runtime_error err) {
        cout << "Caught (by value): " << err.what() << endl;
    }
}

// Example 6: Catch by Reference (Polymorphic)
void demoCatchByReference() {
    cout << "\n========== DEMO 6: Catch by Reference ==========\n";
    try {
        throw runtime_error("Runtime error occurred");
    }
    catch (exception& err) {
        cout << "Caught (by reference): " << err.what() << endl;
    }
}

// Example 7: Exception Propagation
void demoExceptionPropagation() {
    cout << "\n========== DEMO 7: Exception Propagation ==========\n";
    try {
        cout << "Inside try block" << endl;
        ResourceManager resource;
        throw 404;
        cout << "After throw (not executed)" << endl;
    }
    catch (int errorCode) {
        cout << "Exception Caught: " << errorCode << endl;
    }
    cout << "After catch block" << endl;
}

// Example 8: Nested Try-Catch Blocks
void demoNestedTryCatch() {
    cout << "\n========== DEMO 8: Nested Try-Catch ==========\n";
    
    try {
        cout << "Outer try block" << endl;
        
        try {
            cout << "Inner try block" << endl;
            throw runtime_error("Error from inner block");
        }
        catch (logic_error& err) {
            cout << "Inner catch: " << err.what() << endl;
        }
    }
    catch (runtime_error& err) {
        cout << "Outer catch: " << err.what() << endl;
    }
}

// Example 9: Rethrowing Exception
void demoRethrowing() {
    cout << "\n========== DEMO 9: Rethrowing Exception ==========\n";
    
    try {
        try {
            throw overflow_error("Overflow detected");
        }
        catch (overflow_error& err) {
            cout << "Inner catch: " << err.what() << endl;
            cout << "Rethrowing exception..." << endl;
            throw;
        }
    }
    catch (overflow_error& err) {
        cout << "Outer catch: " << err.what() << endl;
    }
}

// Example 10: noexcept Specification
void demoNoexceptSpecification() {
    cout << "\n========== DEMO 10: noexcept Specification ==========\n";
    
    safeFunction(42);
    
    try {
        riskyFunction(-5);
    }
    catch (NegativeNumberException& err) {
        cout << "Caught in main: " << err.what() << endl;
    }
}

// ============================================
// MAIN FUNCTION
// ============================================
int main() {
    cout << "\n********************************************\n";
    cout << "  C++ EXCEPTION HANDLING DEMONSTRATION\n";
    cout << "********************************************\n";
    
    try {
        demoBuiltInException();
        demoStandardException();
        demoCustomException();
        demoMultipleCatchBlocks();
        demoCatchByValue();
        demoCatchByReference();
        demoExceptionPropagation();
        demoNestedTryCatch();
        demoRethrowing();
        demoNoexceptSpecification();
        
        cout << "\n********************************************\n";
        cout << "  ALL DEMONSTRATIONS COMPLETED SUCCESSFULLY\n";
        cout << "********************************************\n\n";
    }
    catch (...) {
        cout << "\nUnexpected error in main!" << endl;
    }
    
    return 0;
}
