#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

int main() {
    FASTIO;

    ll aXl, aXh, aYl, aYh, aZl, aZh;
    cin >> aXl >> aXh >> aYl >> aYh >> aZl >> aZh;

    ll tXl, tXh, tYl, tYh, tZl, tZh;
    cin >> tXl >> tXh >> tYl >> tYh >> tZl >> tZh;

    if (aXh <= tXl || aXl >= tXh || aYl >= tYh || aYh <= tYl || aZh <= tZl)
        cout << -1;
    else if (aZl < tZh) 
        cout << 0;
    else {
        cout << abs(aZl - tZh) + 1;
    }
}