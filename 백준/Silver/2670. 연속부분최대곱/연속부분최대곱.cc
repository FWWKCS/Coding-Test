#include <iostream>
#include <iomanip>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    double dp[N];
    for (int i = 0; i < N; i++) {
        double x; cin >> x;
        dp[i] = x;
    }

    for (int i = 1; i < N; i++) {
        dp[i] = max(dp[i], dp[i-1] * dp[i]);
    }

    double maxV = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] > maxV) maxV = dp[i];
    }

    cout << fixed << setprecision(3) << maxV;
}