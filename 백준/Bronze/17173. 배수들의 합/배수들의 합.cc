#include <iostream>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    long long total = 0;
    int K[M];
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        K[i] = x;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (i % K[j] == 0) {
                total += i;
                break;
            }
        }
    }
    cout << total;
}