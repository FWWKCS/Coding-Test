#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count = 1;
    string input;
    vector<int> A(26);
    vector<int> B(26);


    while (true) {
        for (int i = 0; i < 26; i++) {
            A[i] = 0;
            B[i] = 0;
        }

        bool same = true;
        bool end1 = false, end2 = false;

        cin >> input;
        if (input == "END") end1 = true;

        for (int i = 0; i < input.length(); i++) A[int(input[i])-97]++;

        cin >> input;
        if (input == "END") end2 = true;

        if (end1 && end2) break;

        for (int i = 0; i < input.length(); i++) B[int(input[i]) - 97]++;
        

        // compare
        for (int i = 0; i < 26; i++) {
            if (A[i] != B[i]) {
                same = false;
                break;
            }
        }

        if (same) cout << "Case " << count << ": same\n";
        else cout << "Case " << count << ": different\n";
        
        count++;
    }
}