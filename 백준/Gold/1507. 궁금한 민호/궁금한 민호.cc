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

            bool unique = true;
            for (int k = 1; k <= N; k++) {
                if (P == k || Q == k) continue;

                int tmp = mT[P][k] + mT[k][Q];
                if (mT[P][Q] > tmp) {
                    // 중간을 거쳐가는 경우가 다이렉트보다 더 적게 걸리면 모순
                    cout << -1; 
                    return 0;
                }
                // 중간을 거치는 경우에도 최단 시간이라면 해당 경로를 이용하여 필요 간선을 줄임
                else if (mT[P][Q] == tmp) unique = false;     
            }
            
            if (unique) {
                direct[P][Q] = direct[Q][P] = mT[P][Q];
                total += mT[P][Q];
            }
        }
    }

    cout << total;
}