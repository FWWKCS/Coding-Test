#include <iostream>
#include <random>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 시드값을 얻기 위해 random_device를 사용
    std::random_device rd;

    // random_device를 이용해 시드된 Mersenne Twister 엔진을 생성
    std::mt19937 gen(rd());

    // 0에서 99까지 균등 분포 정의
    std::uniform_int_distribution<> dis(-8139, 8139);

    int count = 0;
    while (count < 812) {
        cout << dis(gen) << ' ' << dis(gen) << '\n';
        count++;
    }
    cout << "-8140 -8140\n8140 8140";
}