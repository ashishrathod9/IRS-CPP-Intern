#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

struct Student {
    string name;
    int score;
};

// Helper function to convert a string to uppercase
void to_uppercase(string &s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
}

int main() {
    // Step 1: Read student data from students.txt
    ifstream input("students.txt");
    vector<Student> students;
    string name;
    int score;

    while (input >> name >> score) {
        students.push_back({name, score});
    }

    // Step 2: Filter out students who scored less than 50
    students.erase(remove_if(students.begin(), students.end(),
                      [](const Student &s) { return s.score < 50; }),
                   students.end());

    // Step 3: Transform remaining student names to uppercase
    for (auto &student : students) {
        to_uppercase(student.name);
    }

    // Step 4: Sort by score, highest to lowest
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.score > b.score;
    });

    // Step 5: Write the results to passed_students.txt
    ofstream output("passed_students.txt");
    for (const auto & student : students) {
        output << student.name << " " << student.score << endl;
    }

    return 0;
}
