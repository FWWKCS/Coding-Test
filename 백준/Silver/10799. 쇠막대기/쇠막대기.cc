#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string T; cin >> T;
    string X = "";
    for (int i = 0; i < T.length(); i++) {
        if (!X.empty() && X.back() == '(' && T[i] == ')') {
            X.pop_back();
            X += "*";
        } 
        else X += T[i]; 
    }

    int d = 0, total = 0;
    for (int i = 0; i < X.length(); i++) {
        if (X[i] == '(') d += 1;
        else if (X[i] == ')') {
            d--;
            total += 1;
        }
        else total += d;
    }

    cout << total;
}