#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    int n; cin >> n;
    int x;

    vector<int> num;
    for (int i = 0; i < 2; i++) {
        cin >> x;
        num.push_back(x);
    }
    sort(num.begin(), num.end());

    // find GCD (a, b)
    int GCD = gcd(num[0], num[1]);

    // find GCD's divisor
    set<int> divisor;

    for (int i = 1; i < sqrt(GCD)+1; i++) {
        if (GCD % i == 0) {
            divisor.insert(i);
            divisor.insert(GCD / i);
        }
    }
    
    if (n == 2) {
        for (auto v : divisor) cout << v << '\n';
        return 0;
    }

    cin >> x;
    set<int> filter;

    for (auto v : divisor) {
        if (x % v == 0) filter.insert(v);
    }
    
    for (auto v : filter) cout << v << '\n';
}