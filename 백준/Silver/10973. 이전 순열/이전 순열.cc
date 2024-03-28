#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    vector<int> target;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        target.push_back(x);
    }

    bool found = prev_permutation(target.begin(), target.end());
    if (found) for (auto x : target) cout << x << ' ';
    else cout << -1;
}