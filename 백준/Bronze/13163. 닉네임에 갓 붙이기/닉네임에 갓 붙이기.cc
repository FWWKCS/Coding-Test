#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    cin.ignore();
    while (N--) {
        string s; getline(cin, s);
        cout << "god";
        int idx = 0;
        for (; idx < s.length(); idx++) {
            if (s[idx] == ' ') break;
        }

        for (int i = idx+1; i < s.length(); i++) {
            if (s[i] == ' ') continue;
            else cout << s[i];
        }

        cout << '\n';
    }
}
