#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    int count = 1;
    string E;
    bool correct;

    while (true) {
        cin >> a >> E >> b;
        correct = false;
        
        if (E == "E") break;

        if (E == ">" && a > b) correct = true;
        else if (E == ">=" && a >= b) correct = true;
        else if (E == "<" && a < b) correct = true;
        else if (E == "<=" && a <= b) correct = true;
        else if (E == "==" && a == b) correct = true;
        else if (E == "!=" && a != b) correct = true;

        if (correct) cout << "Case " << count << ": true\n";
        else cout << "Case " << count << ": false\n";
        count++; 
    }
}