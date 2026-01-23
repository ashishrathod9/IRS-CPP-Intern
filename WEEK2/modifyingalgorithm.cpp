#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b(5);

    // copy
    copy(a.begin(), a.end(), b.begin());

    // copy_if (copy only even numbers)
    vector<int> c;
    copy_if(a.begin(), a.end(), back_inserter(c),
            [](int x){ return x % 2 == 0; });

    // move
    vector<int> d(5);
    move(a.begin(), a.end(), d.begin());

    // fill
    fill(d.begin(), d.begin() + 2, 100);

    // transform (multiply by 10)
    transform(d.begin(), d.end(), d.begin(),
              [](int x){ return x * 10; });

    // replace
    replace(d.begin(), d.end(), 1000, 999);

    // remove
    d.erase(remove(d.begin(), d.end(), 999), d.end());

    // remove_if (remove values > 300)
    d.erase(remove_if(d.begin(), d.end(),
                      [](int x){ return x > 300; }),
            d.end());

    // unique (remove consecutive duplicates)
    vector<int> e = {1, 1, 2, 2, 3, 3};
    e.erase(unique(e.begin(), e.end()), e.end());

    // rotate
    vector<int> f = {1, 2, 3, 4, 5};
    rotate(f.begin(), f.begin() + 2, f.end());

    // partition (even first, odd later)
    vector<int> g = {1, 2, 3, 4, 5, 6};
    partition(g.begin(), g.end(),
              [](int x){ return x % 2 == 0; });

    // reverse
    reverse(g.begin(), g.end());

    // output everything
    cout << "b (copy): ";
    for(int x : b) cout << x << " ";
    cout << "\n";

    cout << "c (copy_if even): ";
    for(int x : c) cout << x << " ";
    cout << "\n";

    cout << "d (after move, fill, transform, remove): ";
    for(int x : d) cout << x << " ";
    cout << "\n";

    cout << "e (unique): ";
    for(int x : e) cout << x << " ";
    cout << "\n";

    cout << "f (rotate): ";
    for(int x : f) cout << x << " ";
    cout << "\n";

    cout << "g (partition + reverse): ";
    for(int x : g) cout << x << " ";
    cout << "\n";

    return 0;
}
