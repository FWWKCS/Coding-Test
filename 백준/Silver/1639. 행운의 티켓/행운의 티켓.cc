#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int answer = 0;
    for (int k = 2; k <= s.size(); k += 2) {
        for (int i = 0; i <= s.size()-k; i++) {
            int l = 0, r = 0;
            for (int x = i; x < i+(k/2); x++) l += s[x]-'0';
            for (int x = i+(k/2); x < i+k; x++) r += s[x]-'0';

            if (l == r) answer = max(answer, k);
        }
    }

    cout << answer;
}