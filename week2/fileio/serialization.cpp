#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int roll;
    string branch;

    friend ofstream& operator<<(ofstream &ofs, const Student &s);
    friend ifstream& operator>>(ifstream &ifs, Student &s);
};

ofstream& operator<<(ofstream &ofs, const Student &s) {
    ofs << s.name << endl;
    ofs << s.roll << endl;
    ofs << s.branch << endl;
    return ofs;
}

ifstream& operator>>(ifstream &ifs, Student &s) {
    ifs >> s.name;
    ifs >> s.roll;
    ifs >> s.branch;
    return ifs;
}

int main() {
    Student s1;
    s1.name = "bharat";
    s1.roll = 1;
    s1.branch = "cs";

    ofstream ofs("Student.txt", ios::trunc);
    ofs << s1;
    ofs.close();

    ifstream ifs("Student.txt");
    ifs >> s1;
    ifs.close();

    cout << s1.name << endl;
    cout << s1.roll << endl;
    cout << s1.branch << endl;

    return 0;
}
