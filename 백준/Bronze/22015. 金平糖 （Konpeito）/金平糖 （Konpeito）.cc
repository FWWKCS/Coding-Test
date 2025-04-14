#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> info(3);
    for (auto &x : info) cin >> x;
    sort(info.begin(), info.end());

    cout << info[2]-info[0] + info[2]-info[1];
}