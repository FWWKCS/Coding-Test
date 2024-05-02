#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    for (int v = 0; v < T; v++) {
        string s, p;
        cin >> s >> p;
        int time = 0;

        string stack = "";
        bool match = false;
        for (int i = 0; i < s.length(); i++) {
            stack.push_back(s[i]);
            if (stack.size() >= p.length() && stack.back() == p.back()) {
                match = true;
                for (int j = 0; j < p.length(); j++) {
                    if (stack[stack.size()-p.size()+j] != p[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    time++;
                    for (int k = 0; k < p.length(); k++) stack.pop_back();
                }
            }
        }

        cout << time + stack.size() << '\n';    
    }
}