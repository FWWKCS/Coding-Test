#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int T; cin >> T;
    int input;
    int min, sum; 
    for (int x = 0; x < T; x++) {
        min = (int)1e9;
        sum = 0;
        for (int i = 0; i < 7; i++) {
            cin >> input;
            if (input % 2 == 0) {
                sum += input;
                if (input < min) min = input;
            }
        }
        cout << sum << ' ' << min << '\n';
    }
}