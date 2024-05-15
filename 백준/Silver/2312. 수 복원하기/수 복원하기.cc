#include <iostream>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 에라토스테네스의 체
    vector<int> prime;
    for (int i = 0; i < 100'001; i++) prime.push_back(i);

    for (int i = 2; i < int(sqrt(100'001))+1; i++) {
        for (int j = i * i; j < 100'001; j+=i) {
            prime[j] = 0;
        }
    }

    vector<int> p;
    for (int i = 2; i < 100'001; i++) {
        if (prime[i] != 0) p.push_back(prime[i]); 
    }

    int T; cin >> T;
    int N;
    for (int k = 0; k < T; k++) {
        cin >> N;
        map<int, int> count;
        int idx = 0;
        while (N != 1) {
            if (N % p[idx] == 0) {
                if (count.find(p[idx]) != count.end()) count[p[idx]]++;
                else count[p[idx]] = 1;

                N /= p[idx];
            }
            else idx++;
        }
        for (auto x : count) cout << x.first << ' ' << x.second << '\n';
    }

}