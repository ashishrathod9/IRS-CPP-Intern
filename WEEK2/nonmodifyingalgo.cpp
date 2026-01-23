#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> v = {1, 2, 3, 4, 2, 5, 6};

    cout << "for_each: ";
    for_each(v.begin(), v.end(), [](int x) {
        cout << x << " ";
    });
    cout << "\n";

    auto it1 = find(v.begin(), v.end(), 3);
    if (it1 != v.end())
        cout << "find: 3 found at index " << distance(v.begin(), it1) << "\n";

    auto it2 = find_if(v.begin(), v.end(), [](int x) {
        return x > 4;
    });
    if (it2 != v.end())
        cout << "find_if: first element > 4 is " << *it2 << "\n";

    int c1 = count(v.begin(), v.end(), 2);
    cout << "count: number of 2s = " << c1 << "\n";

    int c2 = count_if(v.begin(), v.end(), [](int x) {
        return x % 2 == 0;
    });
    cout << "count_if: even numbers = " << c2 << "\n";

    vector<int> v2 = {1, 2, 0, 4, 2, 5, 6};
    auto p = mismatch(v.begin(), v.end(), v2.begin());
    if (p.first != v.end()) {
        cout << "mismatch: v has " << *p.first
             << ", v2 has " << *p.second << "\n";
    }

    vector<int> v3 = {1, 2, 3, 4, 2, 5, 6};
    bool same = equal(v.begin(), v.end(), v3.begin());
    cout << "equal: v and v3 are "
         << (same ? "equal" : "not equal") << "\n";

    vector<int> pattern = {2, 5};
    auto it3 = search(v.begin(), v.end(),
                      pattern.begin(), pattern.end());
    if (it3 != v.end()) {
        cout << "search: pattern {2,5} found at index "
             << distance(v.begin(), it3) << "\n";
    }
   
    auto mn = min_element(v.begin(), v.end());
    auto mx = max_element(v.begin(), v.end());
    cout << "min element: " << *mn << "\n";
    cout << "max element: " << *mx << "\n";

    sort(v.begin(), v.end());
    cout << "sorted: ";
    for_each(v.begin(), v.end(), [](int x) {
        cout << x << " ";
    });
    return 0;
}
