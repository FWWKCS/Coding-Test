#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    int maxV = 0, idx = -1;
    vector<int> cards(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> cards[i];
        if (maxV < cards[i]) {
            maxV = cards[i];
            idx = i;
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (i == idx) continue;

        answer += (maxV + cards[i]);
    }

    cout << answer;
}