#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;
    set<char> alpha;
    while (true) {
        getline(cin, line);
        if (line == "#") break;

        for (int i = 0; i < line.length(); i++) {
            line[i] = char(tolower(line[i]));
            if ('a' <= line[i] && line[i] <= 'z') alpha.insert(line[i]);
        }

        cout << alpha.size() << '\n';
        alpha.clear();
    }
}