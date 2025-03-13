#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, K;

int main() {
    FASTIO;

    cin >> N;
    vector<int> nums(N);
    for (auto &x : nums) cin >> x;
    cin >> K;

    sort(nums.rbegin(), nums.rend());

    vector<int> dp(nums[0] * K + 2, 1e9);

    dp[0] = 0;

    for (int i = 1; i < dp.size(); i++) {
        for (int n : nums) {
            if (i-n >= 0) dp[i] = min(dp[i], dp[i-n]+1);
        }

        if (dp[i] > K) {
            cout << (i % 2 == 0 ? "holsoon " : "jjaksoon ") << "win at " << i;
            return 0;
        }
    }
}