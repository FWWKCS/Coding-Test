#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int T; cin >> T;
    while (T--) {
        int B; cin >> B;
        string s; cin >> s;
        int answer = 0;
        for (char c : s) {
            answer += c - '0';
            answer %= B-1;
        }
        cout << answer << '\n';
    }
}