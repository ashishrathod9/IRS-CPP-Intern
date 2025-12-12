#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
    
    vector<int> marks;
    marks.push_back(85);
    marks.push_back(92);
    marks.push_back(78);
    marks.push_back(88);
    
    cout << "marks: ";
    int i;
    for (i = 0; i < marks.size(); i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
    
    
    map<string, int> ages;
    ages["ravi"] = 22;
    ages["priya"] = 21;
    ages["amit"] = 23;
    
    cout << "ravi age: " << ages["ravi"] << endl;
    
    
    set<int> rollnumbers;
    rollnumbers.insert(101);
    rollnumbers.insert(102);
    rollnumbers.insert(101); 
    rollnumbers.insert(103);
    
    cout << "roll numbers: ";
    for (int roll : rollnumbers) {
        cout << roll << " ";
    }
    cout << endl;
    
    
    queue<string> students;
    students.push("ram");
    students.push("shyam");
    
    cout << "first student: " << students.front() << endl;
    
    return 0;
}