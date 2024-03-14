#include <bits/stdc++.h>
using namespace std;

int main() {
    int P; cin >> P;
    string test;

    for (int i = 0; i < P; i++) {
        cin >> test;
        vector<int> state(8, 0);
        
        for (int i = 0; i < test.length()-2; i++) {
            if (test.substr(i, 3) == "TTT") state[0]++;
            else if (test.substr(i, 3) == "TTH") state[1]++;
            else if (test.substr(i, 3) == "THT") state[2]++;
            else if (test.substr(i, 3) == "THH") state[3]++;
            else if (test.substr(i, 3) == "HTT") state[4]++;
            else if (test.substr(i, 3) == "HTH") state[5]++;
            else if (test.substr(i, 3) == "HHT") state[6]++;
            else state[7]++;

        }

        for (int k = 0; k < 8; k++) {
            cout << state[k] << ' ';
            state[k] = 0;
        }
        cout << '\n';
    }
}