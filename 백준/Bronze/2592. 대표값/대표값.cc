#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v(101, 0);
    int input;
    int sum = 0, most = 0, count = 0;
    for (int i = 0; i < 10; i++) {
        cin >> input;
        sum += input;
        v[input / 10] += 1; 
    }

    for (int i = 0; i < 100; i++) {
        if (v[i] > count) {
            most = i*10;
            count = v[i];
        }
    }

    cout << sum / 10 << '\n' << most;
}