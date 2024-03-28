#include <bits/stdc++.h>
using namespace std;

int N;

void sequence(int depth, vector<int> seq, set<int> visited) {
    if (depth == N) { 
        for (int i = 0; i < N; i++) cout << seq[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited.find(i) != visited.end()) continue;

        visited.insert(i);
        seq.push_back(i);
        sequence(depth + 1, seq, visited);
        visited.erase(i);
        seq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    vector<int> seq;
    set<int> visited;
    sequence(0, seq, visited);
}