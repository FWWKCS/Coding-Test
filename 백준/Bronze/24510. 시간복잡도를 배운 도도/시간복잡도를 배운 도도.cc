#include <iostream>
using namespace std;

int find(string s, string t) {
    int result = 0;
    int idx = 0;
    int k = 0;
    for (char c : s) {
        if (c == t[k]) {
            k++;
            if (k == t.length()) {
                result++;
                k = 0;
            }
        }
        else {
            k = 0;
            if (c == t[k]) k++;
        }
    }

    // cout << s << ' ' << t << ' ' << result << '\n';
    return result;
}

int main() {
    int C; cin >> C;
    int answer = 0;
    while (C--) {
        string s; cin >> s;

        answer = max(answer, find(s, "for")+find(s, "while"));
    }

    cout << answer;
}