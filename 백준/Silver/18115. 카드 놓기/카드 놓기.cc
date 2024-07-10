#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<int>F;
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        F.push_back(x);
    }

    vector<int> answer(N, 0);
    list<int> idx;
    for (int i = N-1; i > -1; i--) idx.push_back(i);

    for (int x : F) {
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