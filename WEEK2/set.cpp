#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // Insert elements
    s.insert(10);
    s.insert(5);
    s.insert(20);

    // Search element
    if (s.find(10) != s.end())
        cout << "10 is found." << endl;

    // Traversing
    for (int x : s)
        cout << x << " ";

    // Count
    cout << "\nCount of 5: " << s.count(5) << endl;

    // Delete
    s.erase(5);

    return 0;
}
