#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int L, P;
    cin >> L >> P;
    int total = L*P;

    int pt;
    for (int i = 0; i < 5; i++) {
        cin >> pt;
        cout << pt-total << ' '; 
    }
}