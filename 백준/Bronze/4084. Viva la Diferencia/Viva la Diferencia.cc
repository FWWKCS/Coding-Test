#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;
    vector<int> seq;
    while (getline(cin, line)) {
        if (line == "0 0 0 0") break;
        istringstream iss(line);
        int x;
        while (iss >> x) seq.push_back(x);

        int count = 0;
        while (seq[0] != seq[1] || seq[1] != seq[2] || seq[2] != seq[3] || seq[3] != seq[0]) {
            vector<int> tmp(4, 0);
            tmp[0] = abs(seq[0]-seq[1]);
            tmp[1] = abs(seq[1]-seq[2]);
            tmp[2] = abs(seq[2]-seq[3]);
            tmp[3] = abs(seq[3]-seq[0]);

            count++;

            for (int i = 0; i < 4; i++) seq[i] = tmp[i];
        }

        cout << count << "\n";
        seq.clear();
    }
}