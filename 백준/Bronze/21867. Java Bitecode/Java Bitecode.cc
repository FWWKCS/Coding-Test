#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    string code; cin >> code;

    string S = "";
    for (int i = 0; i < code.length(); i++) {
        if (code[i] != 'J' && code[i] != 'A' && code[i] != 'V') S += code[i];
    }

    if (S.length() == 0) cout << "nojava";
    else cout << S;
}