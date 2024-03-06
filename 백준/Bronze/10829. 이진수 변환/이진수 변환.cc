#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N; cin >> N;
    string bin = bitset<64>(N).to_string();

    // find first 1
    int i = 0;
    for (; i < bin.length(); i++) {
        if (bin[i] == '1') break;
    }

    for (; i < bin.length(); i++) cout << bin[i];
}