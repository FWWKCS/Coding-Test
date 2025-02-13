#include <iostream>
using namespace std;

string str;

int mode1(int l, int r) {
    int total = 1;
    char current = str[l-1];

    for (int i = l; i < r; i++) {
        if (str[i] != current) {
            total++;
            current = str[i];
        }
    }

    return total;
}

void mode2(int l, int r) {
    for (int i = l-1; i < r; i++) {
        if (str[i] == 'Z') str[i] = 'A';
        else str[i] = char(str[i]+1);
    }
}

int main() {
    int N, Q; cin >> N >> Q;
    cin >> str;
    while (Q--) {
        int m, l, r; cin >> m >> l >> r;

        if (m == 1) cout << mode1(l, r) << '\n';
        else mode2(l, r);
    }
}