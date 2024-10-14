#include <iostream>
using namespace std;

int main() {
    int N, M, K; cin >> N >> M >> K;

    int count = 0;
    while (true) {
        N -= 2;
        M -= 1;
        if (N < 0 || M < 0 || (N+M) < K) break;
        else count++;
    }

    cout << count;
}