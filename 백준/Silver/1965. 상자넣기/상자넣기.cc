#include <iostream>
#include <vector>
#define FASIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASIO;
    int N; cin >> N;
    
    int seq[N];
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        seq[i] = x;
    }

    vector<int> dp(N, 1);
    int answer = 1;
    for (int i = 1; i < N; i++) {
        for (int k = i-1; k > -1; k--) {
            if (seq[k] < seq[i]) dp[i] = max(dp[i], dp[k]+1);
        }
        answer = max(answer, dp[i]);
    }

    cout << answer;
}