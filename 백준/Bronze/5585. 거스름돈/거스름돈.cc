#include <bits/stdc++.h>
using namespace std;

int main() {
    int M; cin >> M;
    int change = 1000;
    change -= M;

    int count = 0;
    
    count += change / 500;
    change %= 500;

    count += change / 100;
    change %= 100;

    count += change / 50;
    change %= 50;

    count += change / 10;
    change %= 10;

    count += change / 5;
    change %= 5;

    count += change;

    cout << count;
}