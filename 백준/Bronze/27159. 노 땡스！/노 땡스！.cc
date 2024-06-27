#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> cards;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x; 
        cards.push_back(x);
    }

    sort(cards.begin(), cards.end());

    int total = cards[0];
    int prev = cards[0];
    int idx = 1;
    while (idx < N) {
        if (cards[idx] == prev+1) {
            prev++;
        }
        else {
            prev = cards[idx];
            total += prev;
        }

        idx++;
    }

    cout << total;
}