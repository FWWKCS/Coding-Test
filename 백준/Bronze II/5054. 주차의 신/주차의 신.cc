#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t; cin >> t;
    int n;
    for (int x = 0; x < t; x++) {
        cin >> n;
        vector<int> shop(n);
        for (int i = 0; i < n; i++) cin >> shop[i];
        sort(shop.begin(), shop.end());
        
        int d = 0;
        for (int i = 1; i < n; i++) d += shop[i] - shop[i-1];
        cout << d * 2 << '\n';  
    }
}