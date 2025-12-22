#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "First element: " << arr[0] << endl;
    cout << "Last element: " << arr[4] << endl;
    cout << endl;
    
    string str = "Hello World";
    cout << "String: " << str << endl;
    cout << "Length: " << str.length() << endl;
    cout << "First character: " << str[0] << endl;
    cout << "Substring (0,5): " << str.substr(0, 5) << endl;
    str += " C++";
    cout << "After append: " << str << endl;
    cout << endl;
    
    map<string, int> ages;
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 35;
    ages["David"] = 28;
    
    cout << "Map (key-value pairs):" << endl;
    for (auto pair : ages) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Alice's age: " << ages["Alice"] << endl;
    cout << "Map size: " << ages.size() << endl;
    cout << endl;
    
    set<int> numbers;
    numbers.insert(5);
    numbers.insert(2);
    numbers.insert(8);
    numbers.insert(2);
    numbers.insert(1);
    
    cout << "Set (unique sorted elements): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Set size: " << numbers.size() << endl;
    cout << "Contains 5: " << (numbers.count(5) > 0 ? "Yes" : "No") << endl;
    cout << "Contains 10: " << (numbers.count(10) > 0 ? "Yes" : "No") << endl;
    cout << endl;
    
    queue<string> q;
    q.push("First");
    q.push("Second");
    q.push("Third");
    q.push("Fourth");
    
    cout << "Queue size: " << q.size() << endl;
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    
    cout << "Dequeue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << "Queue empty: " << (q.empty() ? "Yes" : "No") << endl;
    
    return 0;
}
