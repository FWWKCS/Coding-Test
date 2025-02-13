#include <iostream>
#include <vector>
using namespace std;

vector<char> str = {'0'};

int mode1(int l, int r) {
    int total = 1;
    char current = str[l];

    for (int i = l+1; i <= r; i++) {
        if (str[i] != current) {
            total++;
            current = str[i];
        }
    }

    return total;
}

void mode2(int l, int r) {
    for (int i = l; i <= r; i++) {
        if (str[i] == 'Z') str[i] = 'A';
        else str[i] = char(str[i]+1);
    }
}

int main() {
    int N, Q; cin >> N >> Q;
    string s; cin >> s;
    for (char c : s) str.push_back(c);
    while (Q--) {
        int m, l, r; cin >> m >> l >> r;

        if (m == 1) cout << mode1(l, r) << '\n';
        else mode2(l, r);
    }
}