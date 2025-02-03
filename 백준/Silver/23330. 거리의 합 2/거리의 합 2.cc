#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int n; cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        l[i] = x;
    }

    sort(l.begin(), l.end());

    long long pre = 0;
    for (int i = 0; i < n; i++) {
        pre += abs(l[0]-l[i]);
    }

    long long answer = pre;
    for (int i = 1; i < n; i++) {
        pre -= (n-i)*(l[i]-l[i-1]);
        pre += i * (l[i]-l[i-1]);

        answer += pre;
    }

    cout << answer;
}