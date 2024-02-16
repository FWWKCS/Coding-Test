#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x, y; 
    cin >> x >> y;

    tm date = {};
    date.tm_year = 2007 - 1900; // 연도는 1900기준 시작
    date.tm_mon = x - 1; // 1월은 0부터 시작
    date.tm_mday = y; // 1일은 1부터 시작

    // time_t 구조체 변환
    time_t time = mktime(&date);

    // 주어진 날짜 요일 확인
    tm* weekday = localtime(&time);

    // 요일 출력
    switch (weekday -> tm_wday) {
        case 0:
            cout << "SUN";
            return 0;
        case 1:
            cout << "MON";
            return 0;
        case 2:
            cout << "TUE";
            return 0;
        case 3:
            cout << "WED";
            return 0;
        case 4:
            cout << "THU";
            return 0;
        case 5:
            cout << "FRI";
            return 0;
        case 6:
            cout << "SAT";
            return 0;
    }
}