#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Observer {
public:
    virtual void update(const string& eventData) = 0;
    virtual ~Observer() {}
};



class Publisher {
public:
    virtual void subscribe(Observer* o) = 0;
    virtual void unsubscribe(Observer* o) = 0;
    virtual void notify() = 0;
    virtual ~Publisher() {}
};



class Store : public Publisher {
private:
    vector<Observer*> subscribers;
    string product;

public:
    void subscribe(Observer* o) override {
        subscribers.push_back(o);
    }

    void unsubscribe(Observer* o) override {
        for (auto it = subscribers.begin(); it != subscribers.end(); ++it) {
            if (*it == o) {
                subscribers.erase(it);
                break;
            }
        }
    }

    void setProduct(const string& p) {
        product = p;
        notify();
    }

    void notify() override {
        for (Observer* o : subscribers) {
            o->update(product);
        }
    }
};



class EmailCustomer : public Observer {
private:
    string email;

public:
    EmailCustomer(const string& e) : email(e) {}

    void update(const string& product) override {
        cout << "Email to " << email
             << ": Product available -> " << product << endl;
    }
};

class SmsCustomer : public Observer {
private:
    string phone;

public:
    SmsCustomer(const string& p) : phone(p) {}

    void update(const string& product) override {
        cout << "SMS to " << phone
             << ": Product available -> " << product << endl;
    }
};



int main() {

    Store appleStore;

    Observer* customer1 = new EmailCustomer("ashish@gmail.com");
    Observer* customer2 = new SmsCustomer("9999999999");

    appleStore.subscribe(customer1);
    appleStore.subscribe(customer2);

    appleStore.setProduct("iPhone 16");

    cout << "----\n";

    appleStore.unsubscribe(customer2);

    appleStore.setProduct("MacBook M4");

    delete customer1;
    delete customer2;

    return 0;
}
