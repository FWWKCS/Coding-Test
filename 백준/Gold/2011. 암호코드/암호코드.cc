#include <iostream>
#include <vector>
#define MOD 1'000'000
using namespace std;

int main() {
    string code = "0";
    string input; cin >> input;
    if (input[0] == '0') {
        cout << 0;
        return 0;
    }


    code += input;
    vector<int> dp(code.length(), 1);

    for (int i = 2; i < code.length(); i++) {
        string value = "";
        value += code[i-1];
        value += code[i];
        
        if (value == "00") {
            cout << 0;
            return 0;
        }

        if ('3' <= value[0] && value[1] == '0') {
            cout << 0;
            return 0;
        }
        else if (value[0] == '0') {
            // 마지막 수와 분리해 이어붙이기만 가능
            dp[i] = dp[i-1];
        }
        else if (value[0] <= '2' && value[1] == '0') {
            // 0으로 끝나는 수는 이전 수와 결합해야함
            dp[i] = dp[i-2];
        }
        else if (value > "26") {
            // 26을 초과하는 값은 마지막과 결합할 수 없음
            // 마지막 수와 분리해 이어붙이기만 가능
            dp[i] = dp[i-1];
        }
        else {
            // 상관이 없는 모든 경우엔 이어붙이거나 마지막과 결합
            dp[i] = (dp[i-2] + dp[i-1]) % MOD;
        }
    }

    // for (auto x : dp) cout << x << ' ';
    // cout << '\n';

    cout << dp[code.length()-1];
}