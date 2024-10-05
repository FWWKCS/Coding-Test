#include <iostream>
using namespace std;

int main() {
    string S;
    while (getline(cin, S)) {
        if (S == "EOF") return 0;

        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'i') cout << 'e';
            else if (S[i] == 'e') cout << 'i';
            else if (S[i] == 'I') cout << "E";
            else if (S[i] == 'E') cout << 'I';
            else cout << S[i];
        }

        cout << '\n';
    }
}