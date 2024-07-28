#include <iostream>
#include <cmath>
#include <vector>
#define MAX 1'000'000
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int arr[MAX+1] = {0, };

int main() {
    FASTIO;

    for (int i = 0; i <= MAX; i++) arr[i] = i;
    arr[1] = 0;
    // 소수 필터링
    for (int i = 2; i < int(sqrt(MAX)) + 1; i++) {
        for (int k = i*i; k <= MAX; k += i) arr[k] = 0;
    }

    vector<int> super(1, 0);
    int k = 1;
    for (int i = 0; i <= MAX; i++) {
        if (arr[i] == 0) continue;

        if (arr[k] == 0) {
            k++;
            continue;
        }

        super.push_back(i);
        k++;
    }
    
    int T; cin >> T;
    while (T--) {
        int q; cin >> q;
        cout << super[q] << '\n';
    }
}