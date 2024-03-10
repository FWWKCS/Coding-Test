#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string target; cin >> target;
    int n; cin >> n;
    string ring;

    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> ring;
        for (int x = 0; x < target.length()-1; x++) ring += ring[x];

        for (int k = 0; k < 10; k++) {
            if (target == ring.substr(k, target.length())) {
                count++;
                break;
            }
        }
    }
    cout << count;
}