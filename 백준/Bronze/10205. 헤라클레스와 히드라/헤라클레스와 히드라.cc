#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K; cin >> K;
    int h;
    string command;
    for (int i = 1; i <= K; i++) {
        cout << "Data Set " << i << ":\n";
        cin >> h >> command;

        for (int c = 0; c < command.length(); c++) {
            if (command[c] == 'c') h++;
            else h--;
        }

        cout << h << "\n\n";
    }
}