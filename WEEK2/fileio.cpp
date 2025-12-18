#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    float marks;
};

void addStudent() {
    Student s;
    cout << "Enter name: ";
    cin >> s.name;
    cout << "Enter age: ";
    cin >> s.age;
    cout << "Enter marks: ";
    cin >> s.marks;

    ofstream out("students.txt", ios::app);
    out << s.name << " " << s.age << " " << s.marks << endl;
    out.close();
}

void showAll() {
    ifstream in("students.txt");
    string name;
    int age;
    float marks;

    while(in >> name >> age >> marks)
        cout << name << " " << age << " " << marks << endl;

    in.close();
}

int main() {
    int choice;

    while(true) {
        cout << "\n1. Add Student\n2. Show All Students\n3. Exit\n";
        cin >> choice;

        if(choice == 1) addStudent();
        else if(choice == 2) showAll();
        else break;
    }

    return 0;
}
