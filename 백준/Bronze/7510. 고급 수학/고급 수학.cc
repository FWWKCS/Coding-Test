#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> l(3, 0);
    int x;
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 3; k++) {
            cin >> x;
            l[k] = x; 
        }
        sort(l.begin(), l.end());

        if (pow(l[0],2)+pow(l[1],2) == pow(l[2], 2))
            cout << "Scenario #" << i << ":\nyes\n\n";
        else cout << "Scenario #" << i << ":\nno\n\n";
    }
}