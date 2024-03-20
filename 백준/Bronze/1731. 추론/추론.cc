#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int d, r;

    int a;
    vector<int> sequence;
    for (int i = 0; i < N; i++) {
        cin >> a;
        sequence.push_back(a);
    }

    if (sequence[1] - sequence[0] == sequence[2] - sequence[1]) {
        d = sequence[1] - sequence[0];
        cout << sequence[N-1] + d;
    }
    else {
        r = sequence[1] / sequence[0];
        cout << sequence[N-1] * r;
    }
}