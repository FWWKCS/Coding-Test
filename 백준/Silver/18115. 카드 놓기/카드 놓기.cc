#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int x;

    int answer[N];
    deque<int> idx;
    for (int i = N-1; i > -1; i--) idx.push_back(i);

    for (int k = N; k > 0; k--) {
        cin >> x;

        if (x == 1) {
            answer[idx.back()] = k;
            idx.pop_back();
        }
        else if (x == 2) {
            int top = idx.back();
            idx.pop_back();
            int cur = idx.back();
            answer[cur] = k;
            idx.pop_back();
            idx.push_back(top);
        }
        else {
           answer[idx.front()] = k;
            idx.pop_front();
        }
    }

    for (int i = 0; i < N; i++) cout << answer[i] << ' ';
}