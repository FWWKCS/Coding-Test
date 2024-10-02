#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    string M; cin >> M;
    int K; cin >> K;

    if (M == "annyong") {
        if (K % 2 == 1) cout << K;
        else cout << K-1;
    }

    else { // induck
        if (K % 2 == 1) {
            if (K == N) cout << K-1;
            else if (K == 1) cout << K+1;
            else cout << K+1;
        }
        else cout << K;
    }
}