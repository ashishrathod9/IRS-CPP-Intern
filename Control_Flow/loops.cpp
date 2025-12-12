#include <iostream>
using namespace std;

int main() {
    cout << "counting 1 to 5: ";
    int i;
    for (i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    


    cout << "counting 5 to 1: ";
    int j = 5;
    while (j >= 1) {
        cout << j << " ";
        j--;
    }
    cout << endl;
    



    cout << "printing 1 to 3: ";
    int k = 1;
    do {
        cout << k << " ";
        k++;
    } while (k <= 3);
    cout << endl;
    
    return 0;
}