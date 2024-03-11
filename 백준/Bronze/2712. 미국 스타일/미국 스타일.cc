#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    double input;
    double trans;
    string type;
    for (int i = 0; i < T; i++) {
        cin >> input >> type;
        if (type == "kg") cout << fixed << setprecision(4) << input * 2.2046 << " lb\n";
        else if (type == "lb") cout << fixed << setprecision(4) << input * 0.4536 << " kg\n";
        else if (type == "l") cout << fixed << setprecision(4) << input * 0.2642 << " g\n";
        else cout << fixed << setprecision(4) << input * 3.7854 << " l\n"; 
    }
}