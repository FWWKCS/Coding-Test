#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    int stage[N];
    for (int i = 0; i < N; i++) {
        int x; cin >> x; 
        stage[i] = x;
    }

    int B, C; cin >> B >> C;
    long long answer = N;
    for (int i = 0; i < N; i++) {
        stage[i] = max(0, stage[i] - B);

        if (stage[i] % C == 0) answer += stage[i] / C;
        else answer += (stage[i] / C) + 1;
    } 

    cout << answer;
}