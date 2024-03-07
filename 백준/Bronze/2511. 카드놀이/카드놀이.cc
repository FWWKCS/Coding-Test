#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> A;
    vector<int> B;

    int x;
    int sa = 0, sb = 0;
    int wa = 0, wb = 0;
    for (int i = 0; i < 10; i++) {
        cin >> x; 
        A.push_back(x);
    }
    for (int i = 0; i < 10; i++) {
        cin >> x; 
        B.push_back(x);
    }
    for (int i = 0; i < 10; i++) {
        if (A[i] > B[i]) {
            sa += 3;
            wa = i+1;
        }
        else if (A[i] < B[i]) {
            sb += 3;
            wb = i+1;
        }
        else {
            sa++; sb++;
        }
    }

    cout << sa << ' ' << sb << '\n';
    if (sa > sb) cout << 'A';
    else if (sa < sb) cout << 'B';
    else if (sa == 10 && sb == 10) cout << 'D';
    else {
        if (wa > wb) cout << 'A';
        else cout << 'B';
    }
}