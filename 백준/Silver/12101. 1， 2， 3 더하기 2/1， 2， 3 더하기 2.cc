#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n, k; cin >> n >> k;

    int dp[12] = {0, };
    map<int, vector<string>> dict = {
        {0, {""}},
        {1, {"1"}},
        {2, {"1+1", "2"}}
    }; 

    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= 11; i++) {
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        dict[i] = {};

        for (int x = 1; x <= 3; x++) {
            for (auto y : dict[i-x]) {
                string v = "";
                if (y == "") v = to_string(x);
                else v = y+"+"+to_string(x);

                dict[i].push_back(v);
            }
        }

        sort(dict[i].begin(), dict[i].end());
    }

    if (dp[n] < k) cout << -1;
    else cout << dict[n][k-1];
}