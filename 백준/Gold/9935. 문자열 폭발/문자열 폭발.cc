#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, p;
    cin >> s >> p;
    string stack = "";
    for (int j = 0; j < s.length(); j++) {
        stack.push_back(s[j]);
        if (stack.size() >= p.length() && stack.substr(stack.size()-p.length(), p.length()) == p) {
            for (int x = 0; x < p.length(); x++) stack.pop_back();
        }
    }

    if (stack == "") cout << "FRULA";
    else cout << stack << '\n';
    
}