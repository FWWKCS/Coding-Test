#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    deque<int> cards;

    for (int i = 1; i <= N; i++) cards.push_back(i);

    int selected;
    while (!cards.empty()) {
        cout << cards[0] << ' ';
        cards.pop_front();

        rotate(cards.begin(), cards.begin()+1, cards.end());
    }
}