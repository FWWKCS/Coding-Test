#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<vector<int>> clause;
vector<int> state;

bool found = false;

bool calc() {
    bool result;
    bool a, b;
    if (clause[0][0] < 0) a = !state[abs(clause[0][0])];
    else a = state[clause[0][0]];

    if (clause[0][1] < 0) b = !state[abs(clause[0][1])];
    else b = state[clause[0][1]];

    result = a || b;

    for (int i = 1; i < M; i++) {
        if (clause[i][0] < 0) a = !state[abs(clause[i][0])];
        else a = state[clause[i][0]];

        if (clause[i][1] < 0) b = !state[abs(clause[i][1])];
        else b = state[clause[i][1]];

        result = result && (a || b);
    }

    return result;
}

void recursion(int depth) {
    if (found) return;

    if (depth == N+1) {
        if (calc()) {
            found = true;
        }
        return;
    }

    state[depth] = 0;
    recursion(depth+1);

    state[depth] = 1;
    recursion(depth+1);
}

int main() {
    cin >> N >> M;

    clause.resize(M, vector<int>(2));
    state.resize(N+1, 0);

    for (int i = 0; i < M; i++) {
        cin >> clause[i][0] >> clause[i][1];
    }

    recursion(1);

    cout << found;
    return 0;
}