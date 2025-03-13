#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    vector<double> drinks(N);
    for (auto &x : drinks) cin >> x;
    sort(drinks.begin(), drinks.end());

    double total = drinks.back();
    for (int i = 0; i < N-1; i++) {
        total += drinks[i] / 2;
    }

    cout << fixed << setprecision(5) << total;
}