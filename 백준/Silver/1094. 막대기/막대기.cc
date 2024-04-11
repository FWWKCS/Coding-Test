#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    int X; cin >> X;

    int target = 0;
    vector<int> stick(1, 64);

    while (true) {
        if (accumulate(stick.begin(), stick.end(), 0) == X) break;

        target = stick.back();
        stick.pop_back();
        stick.push_back(target / 2);
        stick.push_back(target / 2);

        if (accumulate(stick.begin(), stick.end()-1, 0) >= X) {
            stick.pop_back();
        }
    }

    cout << stick.size();
}