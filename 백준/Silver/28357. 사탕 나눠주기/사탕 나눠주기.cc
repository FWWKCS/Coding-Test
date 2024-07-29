#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

long long bin_search(long long score[], long long N, long long K) {
    long long s = 0, e = 1'000'000'000'000;

    while (s <= e) {
        long long m = (s + e) / 2;
        long long S = 0;

        for (int i = 0; i < N; i++) {
            S += max((long long)0, score[i]-m);
            if (S > K) break;
        }

        if (S > K) {
            s = m+1;
        }
        else if (S <= K) {
            e = m-1;
        }
    }
    
    return s;
}

int main() {
    FASTIO;
    long long N, K; cin >> N >> K;
    long long score[N];
    for (int i = 0; i < N; i++) {
        long long x; cin >> x;
        score[i] = x;
    }

    cout << bin_search(score, N, K);
}