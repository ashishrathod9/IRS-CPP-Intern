#include <iostream>
#include "math_utils.h"

int main() {
    int a = 5;
    int b = 3;
    int sum = add(a, b);
    int product = multiply(4, 7);
    
    std::cout << "sum: " << sum << std::endl;
    std::cout << "product: " << product << std::endl;
    return 0;
}