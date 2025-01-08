#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int count = 0;
    vector<int> info;

    int N, K, L; cin >> N >> K >> L;
    while (N--) {
        int x1, x2, x3; cin >> x1 >> x2 >> x3;
        if (x1+x2+x3 >= K && x1 >= L && x2 >= L && x3 >= L) {
            count++;
            info.push_back(x1);
            info.push_back(x2);
            info.push_back(x3);
        }
    }

    cout << count << '\n';
    for (int x : info) cout << x << ' ';
}