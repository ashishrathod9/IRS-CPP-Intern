#include <iostream>
using namespace std;

class ProductA {
public:
    virtual void show() = 0;
    virtual ~ProductA() {}
};

class ProductA1 : public ProductA {
public:
    void show() override {
        cout << "ProductA1 created\n";
    }
};

class ProductA2 : public ProductA {
public:
    void show() override {
        cout << "ProductA2 created\n";
    }
};

class ProductB {
public:
    virtual void show() = 0;
    virtual ~ProductB() {}
};

class ProductB1 : public ProductB {
public:
    void show() override {
        cout << "ProductB1 created\n";
    }
};

class ProductB2 : public ProductB {
public:
    void show() override {
        cout << "ProductB2 created\n";
    }
};

class AbstractFactory {
public:
    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
    virtual ~AbstractFactory() {}
};

class FactoryForType1 : public AbstractFactory {
public:
    ProductA* createProductA() override {
        return new ProductA1();
    }

    ProductB* createProductB() override {
        return new ProductB1();
    }
};

class FactoryForType2 : public AbstractFactory {
public:
    ProductA* createProductA() override {
        return new ProductA2();
    }

    ProductB* createProductB() override {
        return new ProductB2();
    }
};

int main() {

    AbstractFactory* factory1 = new FactoryForType1();

    ProductA* a1 = factory1->createProductA();
    ProductB* b1 = factory1->createProductB();

    a1->show();
    b1->show();

    delete a1;
    delete b1;
    delete factory1;


    AbstractFactory* factory2 = new FactoryForType2();

    ProductA* a2 = factory2->createProductA();
    ProductB* b2 = factory2->createProductB();

    a2->show();
    b2->show();

    delete a2;
    delete b2;
    delete factory2;

    return 0;
}
