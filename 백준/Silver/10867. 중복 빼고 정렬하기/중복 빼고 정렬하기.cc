#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int value;
    set<int> S;
    
    for (int i = 0; i < N; i++) {
        cin >> value;
        S.insert(value);
    }

    for (auto i : S) cout << i << ' ';
}