#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int total = 0;
    int pos;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '*') pos = i;
        else total += (s[i]-'0') * (i % 2 ? 3 : 1);
    }

    if (total % 10 == 0) cout << 0;
    else if (pos % 2) {
        for (int k = 1; k < 10; k++) {
            if ((3*k + total) % 10 == 0) {
                cout << k;
                break;
            }
        }
    }
    else cout << 10-(total % 10);
}