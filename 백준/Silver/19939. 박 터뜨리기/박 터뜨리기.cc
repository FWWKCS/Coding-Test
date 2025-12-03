#include <iostream>
using namespace std;

int main() {
    int N, K; cin >> N >> K;

    int cond = K * (K+1) / 2;

    // 최소 공 개수 조건
    if (N < cond) {
        cout << -1;
        return 0;
    }
    
    if ((N-cond) % K == 0) {
        cout << K-1;
    }
    else cout << K;    
}