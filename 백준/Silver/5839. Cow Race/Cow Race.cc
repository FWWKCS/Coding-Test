#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;
    vector<int> Bessie, Elsie;
    int d, h;
    for (int i = 0; i < N; i++) {
        cin >> d >> h;
        for (int j = 0; j < h; j++) Bessie.push_back(d);
    }

    for (int i = 0; i < M; i++) {
        cin >> d >> h;
        for (int j = 0; j < h; j++) Elsie.push_back(d);
    }

    int total = Bessie.size();

    for (int i = 1; i < total; i++) {
        Bessie[i] = Bessie[i-1] + Bessie[i];
        Elsie[i] = Elsie[i-1] + Elsie[i];
    }

    // 선두 결정
    int hour = 0;
    char theFirst;
    while (true) {
        if (Bessie[hour] > Elsie[hour]) {
            theFirst = 'B';
            hour++;
            break;
        }
        else if (Bessie[hour] < Elsie[hour]) {
            theFirst = 'E';
            hour++;
            break;
        }
        else hour++;
    }

    // 리더십 판별
    int leadership = 0;
    while (hour < Bessie.size()) {
        if (theFirst == 'B' && Elsie[hour] > Bessie[hour]) {
            theFirst = 'E';
            leadership++;
        }
        else if (theFirst == 'E' && Bessie[hour] > Elsie[hour]) {
            theFirst = 'B';
            leadership++;
        }
        hour++;
    }

    cout << leadership;
}