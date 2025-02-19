#include <iostream>
#include <set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

set<pair<int, int>> F; // 기말 기준

int main() {
    FASTIO;

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int k; cin >> k;

        F.insert({k, i});
    }

    for (auto &[k, i] : F) cout << k-i << '\n';
}