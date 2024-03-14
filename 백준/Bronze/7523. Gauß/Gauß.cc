#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    long long n, m;
    long long n_sum, m_sum, result;
    for (int i = 1; i <= T; i++) {
        cin >> n >> m;

        if (n >= 0 && m >= 0) {
            n_sum = n * (n+1) / 2;
            m_sum = m * (m+1) / 2;

            result = m_sum - n_sum + n;
        }
        else if (n < 0 && m < 0) {
            n = abs(n);
            m = abs(m);

            n_sum = n * (n+1) / 2;
            m_sum = m * (m+1) / 2;

            result = m_sum - n_sum - m;
        }
        else if (abs(n) <= abs(m)) {
            n = abs(n);
            m = abs(m);

            n_sum = n * (n+1) / 2;
            m_sum = m * (m+1) / 2;

            result = m_sum - n_sum;
        }
        else if (abs(n) > abs(m)) {
            n = abs(n);
            m = abs(m);

            n_sum = n * (n+1) / 2;
            m_sum = m * (m+1) / 2;

            result = m_sum - n_sum;
        }
        cout << "Scenario #" << i << ":\n" << result << "\n\n";
    }
}