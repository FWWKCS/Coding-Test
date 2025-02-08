#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int H, W, N;
vector<pair<int, int>> stickers;

int total = 0;
void select(pair<int, int>& a, pair<int, int>& b) {
    int aR, aC, bR, bC;
    int S = (a.first*a.second)+(b.first*b.second);

    aR = a.first, aC = a.second;
    bR = b.first, bC = b.second;
    
    // 모두 그대로
    if ((aR + bR <= H && max(aC, bC) <= W) || (aR + bR <= W && max(aC, bC) <= H))  
        total = max(total, S);

    // a 회전, b 그대로
    aR = a.second, aC = a.first;
    if ((aR + bR <= H && max(aC, bC) <= W) || (aR + bR <= W && max(aC, bC) <= H))  
        total = max(total, S);

    // 모두 회전
    bR = b.second, bC = b.first;
    if ((aR + bR <= H && max(aC, bC) <= W) || (aR + bR <= W && max(aC, bC) <= H))  
        total = max(total, S);

    // a 그대로, b 회전
    aR = a.first, aC = a.second;
    if ((aR + bR <= H && max(aC, bC) <= W) || (aR + bR <= W && max(aC, bC) <= H))  
        total = max(total, S);

}

int main() {
    FASTIO;

    cin >> H >> W >> N;

    for (int i = 0; i < N; i++) {
        int r, c; cin >> r >> c;
        stickers.push_back({r, c});
    }   

    for (int i = 0; i < stickers.size()-1; i++) {
        for (int j = i+1; j < stickers.size(); j++) {
            select(stickers[i], stickers[j]);
        }
    }

    cout << total;
}