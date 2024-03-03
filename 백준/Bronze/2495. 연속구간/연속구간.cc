#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int target, count, total = 0;
    string num;
    for (int i = 0; i < 3; i++) {
        cin >> num;

        target = num[0];
        count = 1;
        for (int x = 1; x < num.length(); x++) {
            if (num[x] != num[x-1]) {
                total = max(total, count);
                target = num[x];
                count = 1;
            } else count++;
        }
        total = max(total, count);
        cout << total << '\n';
        total = 0;
    }
} 