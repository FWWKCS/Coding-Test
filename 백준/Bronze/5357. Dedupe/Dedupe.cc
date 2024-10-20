#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    while (N--) {
        string S; cin >> S;
        char cur = ' ';
        for (char x : S) {
            if (x != cur) {
                cout << x;
                cur = x;
            }
        }
        cout << '\n';
    }
}