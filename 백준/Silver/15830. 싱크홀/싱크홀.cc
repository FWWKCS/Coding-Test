#include <iostream>
using namespace std;

int main() {
    double V, W, D; cin >> V >> W >> D;

    // 한쪽 끝에서 맞은편으로 등속운동하여 충돌하는 초기 시간
    // W = Vt
    double Ht = W/V;

    int answer = 0;
    while (true) {
        D -= 5*Ht*Ht;
        if (D < 0) break;

        answer++;

        // 감속
        V *= 0.8;
        Ht = W/V;
    }

    cout << answer;
}