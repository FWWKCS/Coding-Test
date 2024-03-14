#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    int n, m;

    for (int i = 0; i < T; i++) {
        cin >> n >> m;
        int count = 0;
        int value;
        for (int b = 2; b < n; b++) {
            for (int a = 1; a < b; a++) {
                if ((a*a + b*b + m) % (a*b) == 0) count++; 
            }
        }

        cout << count << '\n';
    }
}