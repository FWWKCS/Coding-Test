#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, p, value;
    string name = "";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int maxValue = 0;
        string choose = "";
        cin >> p;
        for (int j = 0; j < p; j++) {
            cin >> value >> name;
            if (value > maxValue) {
                maxValue = value;
                choose = name;
            }
        }
        cout << choose << '\n';
    }
}