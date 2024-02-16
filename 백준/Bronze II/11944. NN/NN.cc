#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    string out;
    cin >> N >> M;

    out = to_string(N);

    vector<char> str;
    int idx = 0, min;
    if (out.length() * N <= M) min = out.length() * N;
    else min = M;
    while (idx < min) {
        str.push_back(out[idx % out.length()]);
        idx++;
    }

    for (int i = 0; i < min; i++) cout << str[i];
}