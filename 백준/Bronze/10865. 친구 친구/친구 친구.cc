#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<int, int> relation;
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) relation[i] = 0;

    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        relation[A]++;
        relation[B]++;
    }

    for (auto R : relation) {
        cout << R.second << '\n';
    }
}