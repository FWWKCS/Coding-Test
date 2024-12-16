#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int A = 0, B = 0;
    for (int i = 0; i < s.length(); i += 2) {
        if (s[i] == 'A') {
            A += s[i+1] - '0';
        }
        else B += s[i+1] - '0';
    }

    if (A > B) cout << 'A';
    else cout << 'B';
}