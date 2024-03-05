#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    vector<char> A;
    vector<char> B;
    vector<int> C(7, 0);

    int i;
    string num = "";

    for (i = 0; i < 7-a.length(); i++) 
        A.push_back('0');
    for (i = 0; i < a.length(); i++) 
        A.push_back(a[i]);

    for (i = 0; i < 7-b.length(); i++) 
        B.push_back('0');
    for (i = 0; i < b.length(); i++) 
        B.push_back(b[i]);

    for (i = 0; i < 7; i++) {
        C[i] = (A[i] - '0') + (B[i] - '0');
        num += to_string(C[i]);
    }

    cout << stoll(num);
}