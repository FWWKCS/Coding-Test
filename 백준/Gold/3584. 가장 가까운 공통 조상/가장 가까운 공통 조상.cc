#include <iostream>
#include <map>
#include <set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int T; cin >> T;
    while (T--) {
        int N; cin >> N; N--;
        map<int, int> rel;
        while (N--) {
            int A, B; cin >> A >> B;
            rel[B] = A;
        }

        int X, Y; cin >> X >> Y;
        set<int> visited;
        while (true) {
            visited.insert(X);
            if (rel.find(X) == rel.end()) break;
            X = rel[X];
        };

        while (true) {
            if (visited.find(Y) != visited.end()) {
                cout << Y << '\n';
                break;
            }

            Y = rel[Y];
        }
    }
}