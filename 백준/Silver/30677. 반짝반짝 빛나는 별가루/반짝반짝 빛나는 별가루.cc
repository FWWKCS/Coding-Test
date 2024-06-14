#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K, R;
    long long C;

    cin >> N >> K >> C >> R;
    int input;
    
    vector<long long> base(1, 0);
    for (int i = 0; i < K; i++) {
        cin >> input; 
        base.push_back(input);
    }
    
    vector<long long> S(1, 0);
    for (int i = 0; i < K; i++) {
        cin >> input;
        S.push_back(input);
    }

    vector<long long> P(1, 0);
    for (int i = 0; i < K; i++) {
        cin >> input;
        P.push_back(input);
    }

    long long total = 0;
    vector<long long> skill(K+1, 0);
    int combo = 0;
    int F = 0;

    int l;
    for (int d = 0; d < N; d++) {
        cin >> l;
        if (l == 0) {
            F = max(0, F-R);
            combo = 0;
            continue;
        }

        long long stardust;
        stardust = base[l] * (100 + combo * C) * (100 + skill[l] * S[l]);
        total += stardust / 10000;
        
        skill[l]++;
        combo++;

        F += P[l];
        if (F > 100) {
            cout << -1;
            return 0;
        }
    }

    cout << total;
}