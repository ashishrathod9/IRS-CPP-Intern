#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main() {
    ifstream file("input.txt");
    map<string, int> freq;
    string word;

    while (file >> word) {
        freq[word]++;
    }

    for (auto &p : freq) {
        cout << p.first << " : " << p.second << endl;
    }

    return 0;
}

