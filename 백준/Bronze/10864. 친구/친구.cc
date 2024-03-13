#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;
    vector<int> count(N+1, 0);

    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        count[A]++;
        count[B]++;
    }

    for (int i = 1; i <= N; i++) cout << count[i] << '\n';
}