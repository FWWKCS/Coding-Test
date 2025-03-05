#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 10'000'000'000'000'000
using namespace std;
using ll = long long;

ll k, x;
vector<ll> fibo = {1, 1};
bool found = false;

void recursion(int depth, int idx, ll sum) {
    if (depth > k || sum > x || found) return;

    if (depth == k) {
        if (sum == x) {
            found = true;
        }
        
        return;
    }

    for (int i = idx; i < fibo.size(); i++) {
        recursion(depth+1, i, sum+fibo[i]);
    }
}

int main() {    
    FASTIO;
    
    int T; cin >> T;

    while (true) {
        ll tmp = fibo.back() + fibo[fibo.size()-2];
        if (tmp > MAX) break;

        fibo.push_back(tmp);
    }

    while (T--) {
        cin >> k >> x;
        found = false;
        recursion(0, 0, 0);
        cout << (found ? "YES\n" : "NO\n");
    }
}