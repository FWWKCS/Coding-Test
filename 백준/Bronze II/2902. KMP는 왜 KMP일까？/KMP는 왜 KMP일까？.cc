#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string name; cin >> name;
    for(int i = 0; i < name.length(); i++) {
        if (int(name[i]) != 45 && int(name[i]) <= 90) cout << name[i];
    }
}