#include <iostream>
using namespace std;

int main() {
    int *arr = new int[3];

    arr[0] = 5;
    arr[1] = 10;
    arr[2] = 15;

    for(int i = 0; i < 3; i++)
        cout << arr[i] << " ";

    delete[] arr;

    return 0;
}
