#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> mirror;
    int N, K;
    string line;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> line;
        mirror.push_back(line);
    }

    cin >> K;
    switch (K) {
        case 1: {
            // 그대로 출력
            for (int i = 0; i < N; i++) cout << mirror[i] << '\n';
            break;
        }
        case 2: {
            // 좌우반전
            for (int i = 0; i < N; i++) {
                reverse(mirror[i].begin(), mirror[i].end());
                cout << mirror[i] << '\n';
            }
            break;
        }
        case 3: {
            // 상하반전
            for (int i = N-1; i > -1; i--) cout << mirror[i] << '\n';
            break;
        }
    }
}