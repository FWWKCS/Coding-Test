#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> blocks(1, 0);

    int d = 1;
    int k = 4;
    int idx = 1;

    while (blocks.back() < int(pow(10, 9))) {
        blocks.push_back(blocks[idx-1] + d);

        d += k * idx;
        idx++;
    }

    int n; cin >> n;
    for (int i = 1; i < blocks.size(); i++) {
        if (blocks[i] > n) {
            cout << i-1;
            break;
        }
    }
}