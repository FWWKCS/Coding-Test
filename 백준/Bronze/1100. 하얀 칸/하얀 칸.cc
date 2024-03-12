#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;
    int count = 0;
    for (int i = 0; i < 8; i++) {
        cin >> line;
        for (int j = 0; j < line.length(); j++) {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                if (line[j] == 'F') count++;
            }
        }
    }

    cout << count;
}