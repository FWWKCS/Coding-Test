#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int dp[21] = {0, };
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;
    
    for (int i = 5; i <= 20; i++) {
        dp[i] = dp[i-1] * 2;
        if (i % 2 == 0) {
            dp[i] -= dp[i-4] + dp[i-5];
        }   
    }

    cout << dp[N];
}