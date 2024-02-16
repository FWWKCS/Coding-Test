#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    while (true) {
        getline(cin, input);
        if (input.compare("END") == 0) return 0;

        reverse(input.begin(), input.end());
        cout << input << '\n';
    }
}