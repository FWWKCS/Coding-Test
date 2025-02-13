#include <iostream>
#include <math.h>
using namespace std;
using ld = long double;

int main() {
    ld V, W, D; cin >> V >> W >> D;

    int answer = 0;
    // 한쪽 끝에서 맞은편으로 등속운동하여 충돌하는 초기 시간 W = Vk
    ld k = W/V;
    
    while (true) {
        D -= 5*k*k;
        if (D < 0) break;

        answer++;
        k *= 1.25;
    }

    cout << answer;
}