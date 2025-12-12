#include <iostream>
using namespace std;

int main() {
    
    int age = 22;
    float height = 5.6f;
    double salary = 45000.75;
    char grade = 'A';
    bool isstudent = true;
    
    
    int marks[5] = {85, 92, 78, 88, 95};
    
    
    const int max_students = 50;
    static int count = 0;
    
    cout << "rahul age: " << age << endl;
    cout << "priya height: " << height << endl;
    cout << "amit grade: " << grade << endl;
    cout << "first mark: " << marks[0] << endl;
    cout << "max students: " << max_students << endl;
    
    return 0;
}