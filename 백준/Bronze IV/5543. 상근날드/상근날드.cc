#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int burger = (int)1e9, drink = (int)1e9;
    int price;
    for (int i = 0; i < 3; i++) {
        cin >> price;
        if (price < burger) burger = price;
    }

    for (int i = 0; i < 2; i++) {
        cin >> price;
        if (price < drink) drink = price;
    }

    cout << burger + drink - 50;
}