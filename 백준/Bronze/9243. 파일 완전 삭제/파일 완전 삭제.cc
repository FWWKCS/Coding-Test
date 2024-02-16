#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    string target; cin >> target;
    // 변환
    if (N % 2 != 0) {
        for (int i = 0; i < target.length(); i++) {
            if (target[i] == '1') target[i] = '0';
            else target[i] = '1';
        }
    }

    string result; cin >> result;
    // 비교
    for (int i = 0; i < target.length(); i++) {
        if (target[i] != result[i]) {
            cout << "Deletion failed";
            return 0;
        }
    }
    cout << "Deletion succeeded";
}