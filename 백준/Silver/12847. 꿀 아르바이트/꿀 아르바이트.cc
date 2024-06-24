#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m; cin >> n >> m;
    long long x;
    vector<long long> T(1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        T.push_back(x);
        T[i] = T[i-1] + T[i];
    }

    long long value = 0;
    for (int i = m; i <= n; i++) {
        value = max(value, T[i] - T[i-m]);
    }
    cout << value;
}