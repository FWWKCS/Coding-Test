#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int price, total; cin >> total;
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        cin >> price; sum += price;
    }
    cout << total - sum;
}