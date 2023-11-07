#include <bits/stdc++.h>
using namespace std;

int main() {
    int start, end;
    int cards[21];
    for (int i = 1; i < 21; i++) cards[i] = i;

    for (int i = 0; i < 10; i++) {
        cin >> start >> end;
        int mid = (start+end) / 2;
        for (int k = start; k <= mid; k++) {
            // swap
            int tmp = cards[end];
            cards[end] = cards[k];
            cards[k] = tmp;

            end--;
        }
    }

    for (int i = 1; i < 21; i++) cout << cards[i] << " ";
}