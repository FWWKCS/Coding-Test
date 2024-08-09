#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    int maxV = 0, answer = 0;
    int link[N+1] = {0, };
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        link[i] = x;
    }

    for (int i = 1; i <= N; i++) {
        bool visited[N+1] = {false, };
        int count = 0;
        int target = i;
        while (!visited[target]) {
            visited[target] = true;
            target = link[target];
            count++;
        }

        if (maxV < count) {
            maxV = count;
            answer = i;
        }
    }

    cout << answer;
}