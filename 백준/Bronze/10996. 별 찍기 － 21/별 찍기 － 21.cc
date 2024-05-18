#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    if (N == 1) {
        cout << '*';
        return 0;
    }

    for (int r = 0; r < N; r++) {
        // 윗 줄
        // N이 홀수면 N까지, 짝수면 N-1까지
        for (int i = 1; i <= N; i++) {
            if (N % 2 == 0 && i == N) break;
            
            if (i % 2 == 1) cout << '*';
            else if (i % 2 == 0) cout << ' ';
        }
        
        cout << '\n';

        // 아랫줄
        // N이 홀수면 N-1까지, 짝수면 N까지
        for (int i = 1; i <= N; i++) {
            if (N % 2 == 1 && i == N) break;

            if (i % 2 == 1) cout << ' ';
            else if (i % 2 == 0) cout << '*';
        }

        cout << '\n';
    }
}