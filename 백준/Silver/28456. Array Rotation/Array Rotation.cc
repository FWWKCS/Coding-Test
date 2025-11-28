#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> T(N);
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            int x; cin >> x;
            T[r].push_back(x);
        }
    }

    int Q; cin >> Q;
    while (Q--) {
        int x; cin >> x;
        if (x == 1) {
            int i; cin >> i; i--;
            int k = T[i].back();
            T[i].pop_back();
            T[i].insert(T[i].begin(), k);
        }
        else {
            // transfer
            for (int r = 0; r < N; r++) {
                for (int c = r; c < N; c++) {
                    int tmp = T[r][c];
                    T[r][c] = T[c][r];
                    T[c][r] = tmp;
                }
            }

            // reverse
            for (int r = 0; r < N; r++) {
                reverse(T[r].begin(), T[r].end());
            }
        }
    }

    for (auto r : T) {
        for (auto c : r) cout << c << ' ';
        cout << '\n';
    }
}