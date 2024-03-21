#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    long long len = 0;

    vector<int> l = {
        0,
        9-1+1,
        99-10+1,
        999-100+1,
        9999-1000+1,
        99999-10000+1,
        999999-100000+1,
        9999999-1000000+1,
        99999999-10000000+1,
        1
    };

    int count = 1;
    while (N != 0) {
        len += min(N, l[count]) * count;
        N -= min(N, l[count]);
        count++;
    }

    cout << len;
}