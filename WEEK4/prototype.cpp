#include <iostream>
using namespace std;

class Phone {
public:
    string ram;
    string battery;
    string camera;

    Phone() {}

    Phone(string r, string b, string c) {
        ram = r;
        battery = b;
        camera = c;
    }

    Phone* clone() {
        return new Phone(ram, battery, camera);
    }

    void show() {
        cout << ram << endl;
        cout << battery << endl;
        cout << camera << endl;
    }
};

int main() {

    Phone* original = new Phone("8GB RAM", "5000mAh", "64MP");

    Phone* copy1 = original->clone();
    Phone* copy2 = original->clone();

    copy1->ram = "12GB RAM";

    original->show();
    cout << "-----\n";
    copy1->show();
    cout << "-----\n";
    copy2->show();

    delete original;
    delete copy1;
    delete copy2;

    return 0;
}
