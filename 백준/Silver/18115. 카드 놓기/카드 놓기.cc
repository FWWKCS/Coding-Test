#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int x;

    vector<int> answer(N, 0);
    list<int> idx;
    for (int i = N-1; i > -1; i--) idx.push_back(i);

    while (N) {
        cin >> x;

        if (x == 1) {
            answer[idx.back()] = N;
            idx.pop_back();
            N--;
        }
        else if (x == 2) {
            list<int>::iterator cur = idx.end();
            cur--; cur--;
            answer[*cur] = N;
            idx.erase(cur);
            N--;
        }
        else {
           answer[idx.front()] = N;
            idx.pop_front();
            N--; 
        }
    }

    for (int v : answer) cout << v << ' ';
}