#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int team, score = 0, result = 0;
    int a, b, c, d;
    for (int i = 1; i <= 5; i++) {
        cin >> a >> b >> c >> d;
        result = a + b + c + d;
        if (score < result) {
            team = i; score = result;
        }
    }
    cout << team << ' ' << score;
}