#include <iostream>
#include <vector>
using namespace std;

int main() {
    string S; cin >> S;
    string stack = "";

    int count = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(') stack += '(';
        else {
            if (stack.empty()) count++;
            else stack.pop_back();
        }
    }

    count += stack.length();

    cout << count;
}