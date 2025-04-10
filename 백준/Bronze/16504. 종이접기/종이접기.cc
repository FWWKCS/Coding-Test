#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    long long answer = 0;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            long long x; cin >> x;
            answer += x;
        }
    }

    cout << answer;
}