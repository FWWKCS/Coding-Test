#include <iostream>
using namespace std;

int main() {
    string S;
    while (getline(cin, S)) {
        if (S == "EOF") return 0;
        cout << S << '\n';
    }
}