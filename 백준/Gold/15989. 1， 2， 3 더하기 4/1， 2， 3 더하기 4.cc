#include <iostream>
#include <vector>
#define MAX 10'000
using namespace std;

int main() {
    vector<vector<int>> dp(4, vector<int>(MAX+1, 1));
    
    // c열의 값을 만들기 위해 c-r로부터 r만큼 더해 만드는 경우
    dp[2][1] = 0; 
    dp[3][1] = 0, dp[3][2] = 0;

    dp[0][2] = 2, dp[0][3] = 3;

    for (int k = 4; k <= MAX; k++) {
        dp[1][k] = dp[1][k-1];
        dp[2][k] = dp[2][k-2] + dp[1][k-2];
        dp[3][k] = dp[3][k-3] + dp[2][k-3] + dp[1][k-3];

        dp[0][k] = dp[1][k] + dp[2][k] + dp[3][k];
    }

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << dp[0][N] << '\n';
    }
}