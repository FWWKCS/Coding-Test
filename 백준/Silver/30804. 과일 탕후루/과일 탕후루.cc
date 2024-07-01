#include <iostream>
#include <vector>
#include <tuple>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<int> S, C;
    int x; cin >> x;
    S.push_back(x);
    C.push_back(1);
    for (int i = 1; i < N; i++) {
        cin >> x;
        if (S.back() == x) {
            int top = C.size()-1;
            C[top]++;
        }
        else {
            S.push_back(x);
            C.push_back(1);
        }
    }

    int s = 0;
    int answer = 0;
    set<int> kind;
    int total = 0;
    while (s < S.size()) {


        if (kind.size() == 2 && kind.find(S[s]) == kind.end()) {
            // 더 이상 넣을 수 없음
            answer = max(answer, total);
            kind.clear();
            total = 0;
            s--;
        }
        else if (kind.size() <= 2 || kind.find(S[s]) != kind.end()) {
            kind.insert(S[s]);
            total += C[s];
            s++;
        }
    }

    answer = max(answer, total);

    cout << answer;
}