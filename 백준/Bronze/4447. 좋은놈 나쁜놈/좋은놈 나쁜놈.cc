#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    cin.ignore();
    
    string name;
    char tmp;
    for (int k = 0; k < n; k++) {
        getline(cin, name);

        vector<int> count(2, 0);
        for (int i = 0; i < name.length(); i++) {
            tmp = char(tolower(name[i]));
            if (tmp == 'b') count[0]++;
            else if (tmp == 'g') count[1]++;
        }

        if (count[0] > count[1]) cout << name << " is A BADDY\n";
        else if (count[0] < count[1]) cout << name << " is GOOD\n";
        else cout << name << " is NEUTRAL\n";
    }
}