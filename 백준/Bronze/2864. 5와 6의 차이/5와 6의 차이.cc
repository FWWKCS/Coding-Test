#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int min = 0, max = 0;
    int i;
    for (i = 0; i < a.length(); i++) {
        if (a[i] == '6') a[i] = '5';
    }

    for (i = 0; i < b.length(); i++) {
        if (b[i] == '6') b[i] = '5';
    }

    min = stoi(a) + stoi(b);

    for (i = 0; i < a.length(); i++) {
        if (a[i] == '5') a[i] = '6';
    }

    for (i = 0; i < b.length(); i++) {
        if (b[i] == '5') b[i] = '6';
    }

    max = stoi(a) + stoi(b);

    cout << min << ' ' << max;
}