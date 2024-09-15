#include <iostream>
#include <vector>
#include <queue>
#define MAX 1'000'000
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    int mT[N+1][N+1];
    for (int A = 1; A <= N; A++) {
        for (int B = 1; B <= N; B++) {
            int x; cin >> x;
            mT[A][B] = x;
        }
    }

    vector<vector<int>> direct(N+1, vector<int>(N+1, MAX));
    int total = 0;
    for (int P = 1; P <= N; P++) {
        for (int Q = 1; Q <= N; Q++) {
            if (direct[P][Q] < MAX) continue;

            bool only = true;
            for (int k = 1; k <= N; k++) {
                if (P == k || Q == k) continue;

                // P 와 Q가 아닌 곳(k)을 거쳐 오는 것이 직접 가는 것 보다 더 크기만하면, 무조건 다이렉트로 이동하는 간선이 존재
                // P -> k -> Q = P -> Q 이면 k를 거치는 거치는 것이 간선을 줄임
                if (mT[P][Q] >= mT[P][k] + mT[k][Q]) {
                    only = false;
                    break;
                }
            }

            if (only) {
                direct[P][Q] = mT[P][Q];
                direct[Q][P] = mT[Q][P];
                total += mT[P][Q];
            } 
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int P = 1; P <= N; P++) {
            for (int Q = 1; Q <= N; Q++) {
                direct[P][Q] = min(direct[P][Q], direct[P][k] + direct[k][Q]);
                if (direct[P][Q] < mT[P][Q]) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << total;
}