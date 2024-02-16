#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int b, s;
    // 바닥 제외 별 처리
    for (int i = 0; i < N-1; i++) {
        // 첫 공백
        for (b = 0; b < N-1-i; b++) cout << ' ';
        // 첫 별
        cout << '*';

        // 다음 공백
        for (b = 0; b < 2*i - 1; b++) cout << ' ';
        // 마지막 별
        if (i > 0) cout << "*\n";
        else cout << '\n';
    }

    // 바닥 별
    for (s = 0; s < 2*N-1; s++) cout << '*';
}