#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> A;
    vector<int> B;
    int i, input;
    for (i = 0; i < 10; i++) {
        cin >> input;
        A.push_back(input);
    }
    
    for (i = 0; i < 10; i++) {
        cin >> input;
        B.push_back(input);
    }

    int sa = 0, sb = 0;
    for (i = 0; i < 10; i++) {
        if (A[i] > B[i]) sa++;
        else if (A[i] < B[i]) sb++;
    }

    if (sa > sb) cout << 'A';
    else if (sa < sb) cout << 'B';
    else cout << 'D';
}