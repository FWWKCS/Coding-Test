#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int X; double Y; cin >> X >> Y;
    int N; cin >> N;

    vector<double> v;
    v.push_back(X/Y);

    double A, B;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        v.push_back(A/B);
    }

    sort(v.begin(), v.end());
    cout << fixed << setprecision(2) << v[0] * 1000;
}