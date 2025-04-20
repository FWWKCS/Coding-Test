#include <iostream>
#include <cmath>
#include <vector>
#define MAX 500*2000
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main() {
    FASTIO;

    vector<int> pr(MAX+1);
    for (int i = 0; i <= MAX; i++) pr[i] = i;

    pr[0] = 0, pr[1] = 0;

    for (int i = 2; i <= int(sqrt(MAX))+1; i++) {
        for (int k = i*i; k <= MAX; k+=i) pr[k] = 0;
    }


    int N; cin >> N;
    vector<int> seq(N+1);
    seq[0] = 0;
    for (int i = 1; i <= N; i++) cin >> seq[i];

    for (int i = 2; i <= N; i++) seq[i] += seq[i-1];

    int answer = 0;
    for (int l = 2; l <= N; l++) {
        if (!pr[l]) continue;
        for (int k = l; k <= N; k++) {
            if (pr[seq[k]-seq[k-l]]) answer++;
        }
    }

    cout << answer;
}