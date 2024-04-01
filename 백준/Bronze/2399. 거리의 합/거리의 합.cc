#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> x;
    int N; cin >> N;
    int k;
    for (int i = 0; i < N; i++) {
        cin >> k;
        x.push_back(k);
    }   

    long long total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            total += abs(x[i]-x[j]);
        }
    }

    cout << total;
}