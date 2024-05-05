#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M; cin >> N >> M;

    vector<int> num(1, 0);
    int x;
    for (int i = 0; i < N; i++) {
        cin >> x;
        num.push_back(x);
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j < N; j++) {
            if (num[j] % i > num[j+1] % i) {
                int tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
        }
    }

    for (int i = 1; i <= N; i++) cout << num[i] << '\n';
}