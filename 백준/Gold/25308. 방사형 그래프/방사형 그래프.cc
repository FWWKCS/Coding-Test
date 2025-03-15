#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

double N = 1/sqrt(2);

int answer = 0;
vector<double> cur(8);
vector<int> idx = {0, 1, 2, 3, 4, 5, 6, 7};
vector<pair<double, double>> pos(8);
vector<int> visited(8, 0);

void solve() {
    for (int i = 0; i < 8; i++) {
        double abt = cur[idx[i]];
        double x, y;
        switch (i) {
            case 0: x = 0, y = abt;
                break;
            case 1: x = N*abt, y = N*abt;
                break;
            case 2: x = abt, y = 0;
                break;
            case 3: x = N*abt, y = -N*abt;
                break;
            case 4: x = 0, y = -abt;
                break;
            case 5: x = -N*abt, y = -N*abt;
                break;
            case 6: x = -abt, y = 0;
                break;
            case 7: x = -N*abt, y = N*abt;
                break;
        }

        pos[i] = {x, y};
    }

    double x1, x2, x3;
    double y1, y2, y3;

    double ccw;
    int sign = 0;

    for (int i = 0; i < 8; i++) {
        x1 = pos[i % 8].first, y1 = pos[i % 8].second;
        x2 = pos[(i+1) % 8].first, y2 = pos[(i+1) % 8].second;
        x3 = pos[(i+2) % 8].first, y3 = pos[(i+2) % 8].second;

        // 외적
        ccw = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);

        if (ccw >= 0) return;
    }

    answer++;
}

int main() {
    for (auto &x : cur) cin >> x;
    
    solve();
    while (next_permutation(idx.begin(), idx.end())) {
        solve();
    }

    cout << answer;
}