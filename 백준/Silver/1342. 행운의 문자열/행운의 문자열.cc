#include <iostream>
#include <algorithm>
using namespace std;

bool lucky(string S) {
    for (int i = 0; i < S.length()-1; i++) {
        if (S[i] == S[i+1]) return false;
    }
    return true;
}

int main() {
    string S; cin >> S;
    sort(S.begin(), S.end());
    int count = 0;

    do {
        if (lucky(S)) count++;
    } while (next_permutation(S.begin(), S.end()));

    cout << count;
}