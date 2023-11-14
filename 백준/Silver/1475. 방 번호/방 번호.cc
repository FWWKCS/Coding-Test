#include <bits/stdc++.h>
using namespace std;

int main() {
    int count[10];
    for (int i = 0; i < 10; i++) count[i] = 0;
    string S;
    cin >> S;

    for (int i = 0; i < S.length(); i++) {
        count[S[i] - '0']++;
    }

    int total = 0;
    for (int i = 0; i < 10; i++) {
        if ((i != 6) && (i != 9)) {
            if (total < count[i]) {
                total = count[i];
            }
        }
    }

    int sum = count[6] + count[9];
    if (sum % 2 == 0) {
        sum /= 2;
    }
    else {
        sum = (sum / 2) + 1; 
    }

    if (total < sum) total = sum;

    cout << total;
}