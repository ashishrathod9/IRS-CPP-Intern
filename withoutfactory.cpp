#include <iostream>
#include <string>

class PaymentService {
public:
    void processPayment(const std::string& method) {
        if (method == "CARD") {
            std::cout << "Processing card payment\n";
            // Card payment logic here
        } else if (method == "UPI") {
            std::cout << "Processing UPI payment\n";
            // UPI payment logic here
        } else {
            std::cout << "Unknown payment method\n";
        }
    }
};

int main() {
    PaymentService service;
    service.processPayment("CARD");
    service.processPayment("UPI");
    // If you add a new payment method like "WALLET", you have to add another else-if here.
    return 0;
}
