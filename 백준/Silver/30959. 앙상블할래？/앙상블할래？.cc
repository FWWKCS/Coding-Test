#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N, M;
int maxCorrect = 0;
bool found = false;
vector<int> answer;

int check(set<int> &select, vector<vector<int>> &model) {
    // 앙상블 모델 정확도 비교
    // cout << "타겟 모델 : ";
    // for (auto x : select) cout << x << ' ';
    // cout << '\n';

    int correct = 0;
    for (int i = 0; i < M; i++) {
        int one = 0, zero = 0;
        for (auto s : select) {
            if (model[s][i] == 1) one++;
            else zero++;
        }
        
        if (one > zero && answer[i] == 1) correct++;
        else if (one < zero && answer[i] == 0) correct++;
    }

    return correct;
}

void assemble(set<int> &select, vector<vector<int>> &model, int top) {
    if (found) return;

    // 재귀 사용
    if (select.size() != 1 && select.size() % 2 == 1) {
        // 결과 비교
        int score = check(select, model);
        if (score > maxCorrect) {
            found = true;
            return;
        }
    }

    for (int k = top; k <= N; k++) {
        if (select.find(k) != select.end()) continue;

        select.insert(k);
        assemble(select, model, k+1);
        select.erase(k);
    } 
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int b;
    for (int i = 0; i < M; i++) {
        cin >> b;
        answer.push_back(b);
    }

    vector<vector<int>> model(N+1, vector<int>(M, 0));
    for (int i = 1; i <= N; i++) {
        int correct = 0;
        for (int j = 0; j < M; j++) {
            cin >> b;
            model[i][j] = b;
            if (b == answer[j]) correct++;
        }

        maxCorrect = max(maxCorrect, correct);
    }

    set<int> select;

    assemble(select, model, 1);
    if (found) cout << 1;
    else cout << 0;
}