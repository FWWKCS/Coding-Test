#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int D, M; 
    cin >> D >> M;

    tm date = {};
    date.tm_year = 2009 - 1900; // 연도는 1900기준 시작
    date.tm_mon = M - 1; // 1월은 0부터 시작
    date.tm_mday = D; // 1일은 1부터 시작

    // time_t 구조체 변환
    time_t time = mktime(&date);

    // 주어진 날짜 요일 확인
    tm* weekday = localtime(&time);

    // 요일 출력
    switch (weekday -> tm_wday) {
        case 0:
            cout << "Sunday";
            return 0;
        case 1:
            cout << "Monday";
            return 0;
        case 2:
            cout << "Tuesday";
            return 0;
        case 3:
            cout << "Wednesday";
            return 0;
        case 4:
            cout << "Thursday";
            return 0;
        case 5:
            cout << "Friday";
            return 0;
        case 6:
            cout << "Saturday";
            return 0;
    }
}