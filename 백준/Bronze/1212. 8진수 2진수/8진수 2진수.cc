#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string oct; cin >> oct;
    // edge case
    if (oct == "0") {
        cout << '0';
        return 0;
    }

    string bin = "";
    for (int i = 0; i < oct.length(); i++) {
        bin += bitset<3> (stoi(oct.substr(i, 1))).to_string();
    }


    int k;
    for (k = 0; ; k++) {
        if (bin[k] == '1') break;
    }

    for (; k < bin.length(); k++) cout << bin[k];
}