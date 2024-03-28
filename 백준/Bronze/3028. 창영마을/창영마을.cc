#include <bits/stdc++.h>
using namespace std;

int main() {
    string seq;
    cin >> seq;

    vector<int> cups = {1, 0, 0};
    int tmp;

    for (int i = 0; i < seq.length(); i++) {
        if (seq[i] == 'A') {
            tmp = cups[0];
            cups[0] = cups[1];
            cups[1] = tmp;
        }
        else if (seq[i] == 'B') {
            tmp = cups[1];
            cups[1] = cups[2];
            cups[2] = tmp;
        }
        else {
            tmp = cups[0];
            cups[0] = cups[2];
            cups[2] = tmp;
        }
    }

    cout << find(cups.begin(), cups.end(), 1) - cups.begin() + 1;
}