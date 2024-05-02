#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    string s, p;
    for (int i = 0; i < T; i++) {
        cin >> s >> p;
        int count = 0;
        string stack = "";
        for (int j = 0; j < s.length(); j++) {
            stack.push_back(s[j]);
            if (stack.size() >= p.length() && stack.substr(stack.size()-p.length(), p.length()) == p) {
                count++;
                for (int x = 0; x < p.length(); x++) stack.pop_back();
            }
        }

        count += stack.size();
        cout << count << '\n';
    }
}