#include <iostream>
#include <vector>
#include <map>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int T;
int n, m;
int k, p;
int x;

int main() {
    FASTIO;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<vector<int>> prize(n);
        for (int r = 0; r < n; r++) {
            cin >> k;
            while (k--) {
                cin >> x; 
                prize[r].push_back(x);
            }
            cin >> p;
            prize[r].push_back(p);
        }

        vector<int> cards(m+1);
        for (auto i = cards.begin()+1; i < cards.end(); i++) cin >> *i;
        
        // 집계
        long long total = 0;
        for (int r = 0; r < n; r++) {
            int rep = 1e9;
            for (int c = 0; c < prize[r].size()-1; c++) rep = min(rep, cards[prize[r][c]]);
            
            total += prize[r].back() * rep;
        }

        cout << total << '\n';
    }
}