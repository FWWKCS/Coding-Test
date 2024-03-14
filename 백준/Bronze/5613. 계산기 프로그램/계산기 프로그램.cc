#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int result = 0;

    int x; cin >> x;
    result = x;

    while (true) {
        char opr; cin >> opr;
        if (opr == '=') break;

        else if (opr == '+') {
            cin >> x;
            result += x;
        }
        else if (opr == '-') {
            cin >> x;
            result -= x;
        }
        else if (opr == '*') {
            cin >> x;
            result *= x;
        }
        else if (opr == '/') {
            cin >> x;
            result /= x;
        }
    }

    cout << result;
}