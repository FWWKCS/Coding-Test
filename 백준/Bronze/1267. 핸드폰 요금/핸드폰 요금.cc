#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, time, Y = 0, M = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> time;
        // 영식 요금제로 계산
        Y += ((time / 30) + 1) * 10;
        // 민식 요금제로 계산
        M += ((time / 60) + 1) * 15;
    }

    if (Y < M) cout << "Y " << Y;
    else if (M < Y) cout << "M " << M;
    else cout << "Y M " << Y;
}