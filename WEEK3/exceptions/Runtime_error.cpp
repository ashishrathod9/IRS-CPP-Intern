#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

int main() {
    ifstream file("data.txt");

    try {
        if (!file) {
            throw runtime_error("File not found");
        }
        cout << "File opened successfully";
    }
    catch (const exception& e) {
        cout << "Error: " << e.what();
    }
}
