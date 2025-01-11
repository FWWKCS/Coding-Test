#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    int A, B; cin >> A >> B;
    int C; cin >> C;

    vector<int> tp(N);
    for (int i = 0; i < N; i++) {
        int D; cin >> D;
        tp[i] = D;
    }

    sort(tp.rbegin(), tp.rend());

    int kcal = C;
    int price = A;
    int answer = C / A; // 아무것도 선택하지 않은 디폴트
    for (int d : tp) {
        kcal += d;
        price += B;

        answer = max(answer, kcal/price);
    }
    
    cout << answer;
}