#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S = "", input;
    while (getline(cin, input)) {
        if (input == "EOF") break;
        S += input;
    }

    S += ',';

    int total = 0;
    string num = "";
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == ',') {
            total += stoi(num);
            num = "";
        }
        else num += S[i];
    }

    cout << total;
}