#include <iostream>
#include <vector>
#include <string>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

int main() {    
    FASTIO;

    int T; cin >> T;
    while (T--) {
        string A, B; cin >> A >> B;
        int lenA = A.length(), lenB = B.length();
        ll lA = stol(A), lB = stol(B);
        string answer = to_string(lA * lB);

        vector<string> v(max(lenA, lenB));
        if (lenA > lenB) {
            for (int i = 0; i < lenB; i++) {
                v[lenA-1-i] = to_string((A[lenA-1-i]-'0')*(B[lenB-1-i]-'0'));
            }

            for (int i = lenA-lenB-1; i > -1; i--) v[i] = A[i];
        }
        else {
            for (int i = 0; i < lenA; i++) {
                v[lenB-1-i] = to_string((A[lenA-1-i]-'0')*(B[lenB-1-i]-'0'));
            }

            for (int i = lenB-lenA-1; i > -1; i--) v[i] = B[i];
        }

        string X = "";
        for (string s : v) X += s;

        cout << (X == answer ? 1 : 0) << '\n';
    }
}