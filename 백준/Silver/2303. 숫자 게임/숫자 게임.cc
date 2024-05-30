#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int winner, highscore = 0;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        vector<int> cards;
        int x;
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            cin >> x;
            sum += x;
            cards.push_back(x); 
        }

        int score = 0;
        for (int u = 0; u < 4; u++) {
            for (int v = u+1; v < 5; v++) {
                score = max(score, (sum - cards[u] - cards[v]) % 10);
            }
        }

        if (score >= highscore) {
            winner = i+1;
            highscore = score;
        }
    }

    cout << winner;
}