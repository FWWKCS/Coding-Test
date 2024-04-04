#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    map<long long, int> cards;
    cards.clear();
    long long x;

    for (int i = 0; i < N; i++) {
        cin >> x;
        if (cards.find(x) != cards.end()) {
            cards[x]++;
        }
        else cards.insert({x, 1});
    }

    long long answer = pow(2, 62);
    int total = 0;
    for (auto k : cards) {
        if (total < k.second) {
            answer = k.first;
            total = k.second;
        }
    }

    cout << answer;
}