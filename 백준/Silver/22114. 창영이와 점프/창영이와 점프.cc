#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, K;

int main() {
    FASTIO;
    
    cin >> N >> K;
    int block[N] = {0};
    vector<vector<int>> dp(2, vector<int>(N, 1));

    for (int i = 1; i < N; i++) {
        int L; cin >> L;
        block[i] = L;
    } 

    int answer = 0;
    for (int i = 1; i < N; i++) {
        if (block[i] > K) {
            dp[0][i] = 1;
            dp[1][i] = dp[0][i-1] + 1;
        }
        else {
            dp[0][i] = dp[0][i-1] + 1;
            dp[1][i] = dp[1][i-1] + 1;
        }

        answer = max(answer, max(dp[0][i], dp[1][i]));
    }

    cout << answer;
}