#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> W(10);
    vector<int> K(10);

    int i;
    for (i = 0; i < 10; i++) cin >> W[i];
    for (i = 0; i < 10; i++) cin >> K[i];

    sort(W.rbegin(), W.rend());
    sort(K.rbegin(), K.rend());

    cout << accumulate(W.begin(), W.begin()+3, 0) << ' ' << accumulate(K.begin(), K.begin()+3, 0);
}