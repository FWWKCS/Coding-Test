#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    vector<int> info(4, 0);
    while (getline(cin, input)) {
        if (input == "EOF") return 0;
        for (int i = 0; i < input.size(); i++) {
            if (islower(input[i])) info[0]++;
            else if (isupper(input[i])) info[1]++;
            else if ('0' <= input[i] && input[i] <= '9') info[2]++;
            else info[3]++;
        }

        for (int i = 0; i < 4; i++) {
            cout << info[i] << ' ';
            info[i] = 0;
        }
        cout << '\n';
    }
}