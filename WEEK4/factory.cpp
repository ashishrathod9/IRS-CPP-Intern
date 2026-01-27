#include <iostream>
#include <memory>
#include <string>


class Payment
{
public:
    virtual ~Payment() = default;
    virtual void pay(double amount) = 0;
};


class UpiPayment : public Payment
{
public:
    void pay(double amount) override
    {
        std::cout << "Paid ₹" << amount << " using UPI\n";
    }
};

class CardPayment : public Payment
{
public:
    void pay(double amount) override
    {
        std::cout << "Paid ₹" << amount << " using CARD\n";
    }
};


class PaymentFactory
{
public:
    virtual ~PaymentFactory() = default;

    // Factory Method
    virtual std::unique_ptr<Payment> createPayment() = 0;
};


class UpiPaymentFactory : public PaymentFactory
{
public:
    std::unique_ptr<Payment> createPayment() override
    {
        return std::make_unique<UpiPayment>();
    }
};

class CardPaymentFactory : public PaymentFactory
{
public:
    std::unique_ptr<Payment> createPayment() override
    {
        return std::make_unique<CardPayment>();
    }
};


class PaymentService
{
public:
    void processPayment(PaymentFactory& factory, double amount)
    {
        // Client does NOT know which payment type is created
        std::unique_ptr<Payment> payment = factory.createPayment();
        payment->pay(amount);
    }
};


int main()
{
    PaymentService service;

    UpiPaymentFactory upiFactory;
    CardPaymentFactory cardFactory;

    service.processPayment(upiFactory, 500.0);
    service.processPayment(cardFactory, 1200.0);

    return 0;
}

