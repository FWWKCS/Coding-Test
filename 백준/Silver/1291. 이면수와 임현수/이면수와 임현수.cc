#include <iostream>
#include <set>
using namespace std;

int main() {
    string N; cin >> N;
    int K = stoi(N);

    bool isLee = false;
    bool isLim = false;

    // Lee
    // 2와 3의 합으로 표현되는 숫자 (1,2,3,5가 아닌 모든 수)
    // 각 자리수 합이 홀수
    if (K >= 4 && K != 5) {
        int total = 0;
        for (int i = 0; i < N.length(); i++) {
            total += N[i] - '0';
        }

        if (total % 2 == 1) isLee = true;
    } 

    // Lim
    // 2 또는 4인 경우
    if (K == 2 || K == 4) isLim = true;
    else {
        bool isComposite = false;
        for (int i = K; i > 0; i--) {
            if (i != K && i != 1) {
                if (K % i == 0) {
                    isComposite = true;
                    break;
                }
            }
        }
        // 합성수인 경우
        if (isComposite) {
            set<int> factor;
            int x = 2;
            while (K != 1) {
                if (K % x == 0) {
                    K /= x;
                    factor.insert(x);
                }
                else x++;
            }

            // 소인수 종류 개수가 짝수개
            if (factor.size() % 2 == 0) {
                isLim = true;
            }
        }
    }

    if (isLee && !isLim) cout << 1;
    else if (!isLee && isLim) cout << 2;
    else if (!isLee && !isLim) cout << 3;
    else cout << 4;
}