#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int W, P; cin >> W >> P;
    vector<int> pt = {0};
    set<int> answer;

    while (P--) {
        int L; cin >> L;
        pt.push_back(L); 
    }

    pt.push_back(W);

    for (int i = 0; i < pt.size()-1; i++) {
        for (int j = i+1; j < pt.size(); j++) {
            answer.insert(pt[j]-pt[i]);
        }
    }

    for (auto x : answer) cout << x << ' ';
}