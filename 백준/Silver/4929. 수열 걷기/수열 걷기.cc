#include <iostream>
#include <vector>
#include <set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using  namespace std;

int A, B; 

int main() {
    FASTIO;

    while (true) {
        cin >> A;
        if (!A) return 0;
        set<int> X;
        while (A--) {
            int k; cin >> k;
            X.insert(k);
        }

        set<int> Y;
        cin >> B;
        while (B--) {
            int k; cin >> k;
            Y.insert(k);
        }
        
        set<int> Z;

        int answer = 0;
        for (auto v : X) {
            if (Y.find(v) != Y.end()) {
                Z.insert(v);
                answer += v;
            }
        }
        
        vector<int> S1, S2;
        int total = 0;
        for (auto v : X) {
            if (Z.find(v) != Z.end()) {
                S1.push_back(total); 
                total = 0;
            }
            else total += v;
        }

        S1.push_back(total);

        total = 0;
        for (auto v : Y) {
            if (Z.find(v) != Z.end()) {
                S2.push_back(total); 
                total = 0;
            }
            else total += v;
        }

        S2.push_back(total);


        for (int i = 0; i < S1.size(); i++) {
            answer += max(S1[i], S2[i]);
        }

        cout << answer << '\n';
    }
}