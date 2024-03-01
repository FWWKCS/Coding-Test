#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    string num;
    set<char> v;
    for (int i = 0; i < T; i++) {
        cin >> num;
        for (int k = 0; k < num.length(); k++) {
            v.insert(num[k]);
        }

        cout << v.size() << '\n';
        v.clear();
    }
}