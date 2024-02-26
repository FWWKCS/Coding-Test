#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, N; cin >> N;
    string value; cin >> value;
    string input;
    for (i = 1; i < N; i++) {
        cin >> input;
        for (j = 0; j < input.length(); j++) {
            if (value[j] != input[j]) value[j] = '?';
        }
    }

    cout << value;
}