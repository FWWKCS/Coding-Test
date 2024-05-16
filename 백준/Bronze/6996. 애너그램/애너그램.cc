#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    string A, B;
    for (int k = 0; k < T; k++) {
        bool anagram = true;
        cin >> A >> B;
        if (A.length() == B.length()) {
            vector<int> a(26, 0), b(26, 0);

            for (int i = 0; i < A.length(); i++) a[int(A[i])-97]++;
            for (int i = 0; i < B.length(); i++) b[int(B[i])-97]++;

            if (a != b) anagram = false;
        } 
        else anagram = false;

        if (anagram) cout << A << " & " << B << " are anagrams.\n";
        else cout << A << " & " << B << " are NOT anagrams.\n";


    }
}