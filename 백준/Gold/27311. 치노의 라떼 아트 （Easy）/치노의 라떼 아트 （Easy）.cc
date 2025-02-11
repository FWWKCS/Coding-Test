#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int T, R, C;
string board[10];

int minR, minC, maxR, maxC;
int minDR, minDC, maxDR, maxDC;


void area() {
    bool check = false;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '#') {
                minR = min(minR, i);
                minC = min(minC, j);
                maxR = max(maxR, i);
                maxC = max(maxC, j);
            }
        }
    }
}

int checkHeart() {
    // 하트 모양 검증

    // 영역이 존재하지 않는 경우
    if (maxR < 0 || maxC < 0 || minR > 9 || minC > 9) return 0;

    // 크림의 전체 범위는 정사각형
    if (maxR-minR != maxC-minC) return 0;

    // 1x1 크기는 하트가 아니다, 존재하지 않는 경우도 동일
    if (maxR == minR || maxC == minC) return 0;

    for (int i = minR; i <= maxR; i++) {
        for (int j = minC; j <= maxC; j++) {
            if (board[i][j] == '.') {
                minDR = min(minDR, i);
                minDC = min(minDC, j);
                maxDR = max(maxDR, i);
                maxDC = max(maxDC, j);
            }
        }
    }

    // cout << minDR << ' ' << minDC << ' ' << maxDR << ' ' << maxDC << '\n';

    // 빈 영역의 범위는 정사각형
    if (maxDR-minDR != maxDC-minDC) return 0;

    // 빈 영역이 존재하지 않는 경우
    if (maxDR < 0 || maxDC < 0 || minDR > 9 || minDC > 9) return 0;

    // 각각의 범위 중하나는 모서리에 인접해야한다
    if (!(minDR == minR && minDC == minC) // 좌측 상단
     && !(minDR == minR && maxDC == maxC) // 우측 상단
     && !(maxDR == maxR && minDC == minC) // 좌측 하단
     && !(maxDR == maxR && maxDC == maxC)) // 우측 하단 
     return 0;

    // 빈 영역만으로 존재해야한다
    for (int i = minDR; i <= maxDR; i++) {
        for (int j = minDC; j <= maxDC; j++) {
            if (board[i][j] == '#') return 0;
        }
    }

    return 1;
}


int main() {
    FASTIO;

    cin >> T;
    while (T--) {
        cin >> R >> C;
        minR = 1e9, minC = 1e9, maxR = -1, maxC = -1;
        minDR = 1e9, minDC = 1e9, maxDR = -1, maxDC = -1;
        for (int i = 0; i < R; i++) {
            string s; cin >> s;
            board[i] = s;
        }

        area();

        // cout << minR << ' ' << minC << ' ' << maxR << ' ' << maxC << '\n';
        
        cout << checkHeart() << '\n';
    }
}