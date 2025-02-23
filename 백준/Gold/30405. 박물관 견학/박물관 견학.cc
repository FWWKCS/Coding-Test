#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main() {
    vector<int> pos;

    int N, M; cin >> N >> M;
    for (int v = 1; v <= N; v++) {
        int k; cin >> k;
        for (int i = 1; i <= k; i++) {
            int x; cin >> x;
            if (i == 1 || i == k) pos.push_back(x);
        }
    }

    sort(pos.begin(), pos.end());
    cout << pos[N-1];
}