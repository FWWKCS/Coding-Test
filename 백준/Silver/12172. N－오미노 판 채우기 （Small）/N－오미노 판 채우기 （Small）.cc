#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int X, R, C; cin >> X >> R >> C;
        bool fill = false;
        if (X == 1) {
            // 판을 반드시 채움
            fill = true;
        }
        else if (X == 2) {
            // 판의 칸 개수가 홀수면 채울 수 없다
            if ((R * C) % 2 == 1) fill = false;
            else fill = true;
        }
        else if (X == 3) {
            // 칸 부족
            if ((R <= 2 && C <= 2)) fill = false;
            // 칸 수가 6이상인 3의 배수일때 항상 가능
            else if (R*C >= 6 && (R*C) % 3 == 0) fill = true;
            else fill = false; 
        }
        else {
            // 3x4, 4x4 일때만 무엇을 선택하든 칸을 채울 수 있음
            if ((R != 3 || C != 3) && (R >= 3 && C >= 3)) fill = true;
            else fill = false;
        }

        cout << "Case #" << i << ": " << (fill ? "GABRIEL" : "RICHARD") << '\n';
    }
}