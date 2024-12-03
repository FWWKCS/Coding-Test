#include <iostream>
using namespace std;

int main() {
    int S, F; cin >> S >> F;
    // 더 적게 걸리는 교통편 이용
    if (S > F) cout << "flight";
    else if (S <= F) cout << "high speed rail";
}