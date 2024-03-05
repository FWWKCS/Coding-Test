#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int M; cin >> M;
    vector<int> I;
    int k;
    for (int i = 0; i < N; i++) {
        cin >> k;
        I.push_back(k);
    }

    sort(I.begin(), I.end());

    int s = 0, e = N-1;
    int count = 0;
    while (s < e) {
        if (I[s] + I[e] == M) {
            count++;
            s++;
        }

        else if (I[s] + I[e] < M) s++;
        else e--;
    }

    cout << count;
}