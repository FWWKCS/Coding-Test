#include <iostream>
using namespace std;

int main() {
    string s; cin >> s;
    int idx = 0;
    string answer = "";
    while (idx < s.size()) {
        answer += s[idx];
        idx += s[idx] - 'A' + 1;
    }

    cout << answer;
}