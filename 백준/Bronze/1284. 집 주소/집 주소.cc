#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input;
    while (true) {
        cin >> input;
        if (input == "0") break;

        int len = 0;

        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '0') len += 4;
            else if (input[i] == '1') len += 2;
            else len += 3; 
        }

        cout << len + input.length() + 1 << '\n';
    }
}