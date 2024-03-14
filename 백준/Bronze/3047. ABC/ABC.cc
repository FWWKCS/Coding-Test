#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> sequence;
    int x;
    for (int i = 0; i < 3; i++) {
        cin >> x;
        sequence.push_back(x);
    }

    sort(sequence.begin(), sequence.end());

    string req; cin >> req;
    for (int i = 0; i < req.length(); i++) {
        cout << sequence[int(req[i])-65] << ' ';
    }
}