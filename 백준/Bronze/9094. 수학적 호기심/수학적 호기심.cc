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
                value = (pow(a, 2)+pow(b, 2)+m)/(a*b);
                if (value*a*b == (pow(a, 2)+pow(b, 2)+m)) count++; 
            }
        }

        cout << count << '\n';
    }
}