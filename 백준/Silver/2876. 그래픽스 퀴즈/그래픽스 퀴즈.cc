#include <iostream>
#include <vector>
#include <tuple>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    vector<pair<int, int>> table;
    for (int i = 0; i < N; i++) {
        int A, B; cin >> A >> B;
        table.push_back(make_pair(A, B));
    }

    vector<vector<int>> dp(6, vector<int>(N, 0));
    vector<int> answer(6, 0);

    for (int r = 1; r <= 5; r++) {
        if (table[0].first == r || table[0].second == r) {
            dp[r][0] = 1;
            answer[r] = 1;
        }
    }

    for (int r = 1; r <= 5; r++) {
        for (int k = 1; k < N; k++) {
            if (table[k].first == r || table[k].second == r) {
                dp[r][k] = dp[r][k-1] + 1;

                answer[r] = max(answer[r], dp[r][k]);
            }
        }
    }

    // for (int r = 1; r <= 5; r++) {
    //     for (int c = 0; c < N; c++) cout << dp[r][c] << ' ';
    //     cout << '\n';
    // }

    // for (auto a : answer) cout << a << ' ';
    // cout << '\n';

    int m = 0, grade;
    for (int x = 1; x <= 5; x++) {
        if (answer[x] > m) {
            m = answer[x];
            grade = x;
        }
    }

    cout << m << ' ' << grade;
}