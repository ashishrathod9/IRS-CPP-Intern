#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
using namespace std;

int main() {
    int arr[3] = {1, 2, 3};
    for(int i = 0; i < 3; i++)
        cout << arr[i] << " ";
    cout << endl;

    string s = "Ashish";
    s.append(" Rathod");
    cout << s << endl;

    vector<int> v = {10, 20, 30};
    v.push_back(40);
    for(int x : v) cout << x << " ";
    cout << endl;

    map<string, int> mp;
    mp["Ashish"] = 22;
    mp["Ravi"] = 25;
    for(auto &p : mp) cout << p.first << " " << p.second << endl;

    set<int> st = {5,1,3,3,5};
    for(int x : st) cout << x << " ";
    cout << endl;

    queue<string> q;
    q.push("A");
    q.push("B");
    q.push("C");
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;

    return 0;
}
