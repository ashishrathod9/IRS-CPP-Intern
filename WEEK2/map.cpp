#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;
    
    // Insert elements
    m.insert({1, "One"});
    m.insert({3, "Three"});
    m[2] = "Two";

    // Find element
    if (m.find(2) != m.end())
        cout << "Key 2 found: " << m[2] << endl;

    // Traverse map
    for (auto &p : m)
        cout << p.first << " -> " << p.second << endl;

    // Delete by key
    m.erase(1);

    // Size
    cout << "Size: " << m.size() << endl;

    return 0;
}
