#include <iostream>
using namespace std;

class phone
{
public:
    string ram;
    string battery;
    string display;
    string camera;

    void show()
    {
        cout << ram << endl;
        cout << battery << endl;
        cout << display << endl;
        cout << camera << endl;
    }
};

class builder
{
    phone* p;

public:
    builder()
    {
        p = new phone();
    }

    void buildram()
    {
        p->ram = "8GB RAM";
    }

    void buildbattery()
    {
        p->battery = "5000mAh Battery";
    }

    void builddisplay()
    {
        p->display = "AMOLED Display";
    }

    void buildcamera()
    {
        p->camera = "64MP Camera";
    }

    phone* getphone()
    {
        return p;
    }
};

int main()
{
    builder b;

    b.buildram();
    b.buildbattery();
    b.builddisplay();
    b.buildcamera();

    phone* p = b.getphone();
    p->show();

    delete p;
    return 0;
}
