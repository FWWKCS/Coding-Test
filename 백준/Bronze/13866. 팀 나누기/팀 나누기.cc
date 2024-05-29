#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int x;
    vector<int> level;
    for (int i = 0; i < 4; i++) {
        cin >> x;
        level.push_back(x);
    }

    sort(level.begin(), level.end());

    cout << abs((level[0]+level[3])-(level[1]+level[2]));
}