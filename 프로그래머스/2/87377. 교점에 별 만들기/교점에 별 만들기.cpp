#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define INF 20'000'000'001

typedef long long ll;
using namespace std;

bool custom_sorted(vector<ll> &a, vector<ll> &b) {
    if (a[1] != b[1]) return a[1] > b[1];
    else return a[0] < b[0];
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    ll x_min = INF, x_max = -INF, y_min = INF, y_max = -INF;
    vector<vector<ll>> pos;
    for (int a = 0; a <= line.size()-2; a++) {
        for (int b = a+1; b <= line.size()-1; b++) {
            ll A = line[a][0], B = line[a][1], E = line[a][2];
            ll C = line[b][0], D = line[b][1], F = line[b][2];
            
            if (A*D-B*C == 0) continue;
            else {
                ll p = A*D-B*C;
                ll cx = B*F-E*D;
                ll cy = E*C-A*F;
                
                if (cx % p == 0 && cy % p == 0) {
                    pos.push_back({cx/p, cy/p});
                    
                    x_min = min(x_min, cx/p);
                    x_max = max(x_max, cx/p);
                    y_min = min(y_min, cy/p);
                    y_max = max(y_max, cy/p);
                }
            }
        }
    }
    
    sort(pos.begin(), pos.end(), custom_sorted);   
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    

    int idx = 0;
    for (ll r = y_max; r >= y_min; r--) {
        string l = "";
        for (ll c = x_min; c <= x_max; c++) {
            if (idx < pos.size() && c == pos[idx][0] && r == pos[idx][1]) {
                l += "*";
                idx++;
            }
            else l += ".";
        }
        answer.push_back(l);
    }
    
    return answer;
}