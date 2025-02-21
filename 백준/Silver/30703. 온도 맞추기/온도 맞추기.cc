#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    vector<int> A(N), B(N), X(N);
    int mod;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> X[i];
    
    vector<int> div;
    for (int i = 0; i < N; i++) {
        if (abs(B[i] - A[i]) % X[i] != 0) {
            cout << -1;
            return 0;
        }

        div.push_back(abs(B[i] - A[i]) / X[i]);
    }

    for (int i = 0; i < N-1; i++) {
        if (div[i] % 2 != div[i+1] % 2) {
            cout << -1;
            return 0;
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        answer = max(answer, div[i]);
    }

    cout << answer;
}