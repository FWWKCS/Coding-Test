#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    cin.ignore();
    string sentence;
    for (int i = 0; i < N; i++) {
        getline(cin, sentence);
        if (int(sentence[0]) >= 97) sentence[0] = char(int(sentence[0])-32);
        cout << sentence << '\n';
    }
}