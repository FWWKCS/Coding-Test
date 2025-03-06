#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, M;
vector<int> seq;

int maxV = 0;

int wrap(int t) {
    int total = 0, cd = 0;
    for (int x : seq) {
        if (total + x > t) {
            cd++;
            total = 0;
        }
        total += x;
    }

    total = 0;
    cd++;

    return cd;
}

int binSearch() {
    int s = maxV, e = 10000*N;
    int res;

    while (s <= e) {
        int mid = (s+e)/2;
        if (wrap(mid) <= M) {
            res = mid;
            e = mid-1;
        }
        else s = mid+1;
    }

    return res;
}

int main() {
    FASTIO;

    cin >> N >> M;
    seq.resize(N);
    
    for (auto &x : seq) cin >> x, maxV = max(maxV, x);

    cout << binSearch();
}
