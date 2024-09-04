#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int T; cin >> T;
    while (T--) {
        int N; cin >> N; 
        vector<int> rel(N+1, -1);
        for (int i = 0; i < N-1; i++) {
            int A, B; cin >> A >> B;
            rel[B] = A;
        }

        int X, Y; cin >> X >> Y;
        vector<bool> visited(N+1, false);
        while (true) {
            visited[X] = true;
            if (rel[X] == -1) break;
            X = rel[X];
        };

        while (true) {
            if (visited[Y]) {
                cout << Y << '\n';
                break;
            }

            Y = rel[Y];
        }
    }
}