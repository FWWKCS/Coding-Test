#include <iostream>
#include <vector>
#include <math.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

vector<int> p = { 2,3,5,7,11,13,17,19,23,29 };
vector<ll> prefixM;
vector<int> a;

int idx;

void findA(int v) {
    idx = 0;
    for (int i = prefixM.size() - 1; i >= 0; i--) {
        if (v / prefixM[i] > 0) {  // 수정된 조건
            idx = i;
            break;
        }
    }

    for (int i = idx; i >= 0; i--) {
        for (int x = (i+1 < p.size() ? p[i+1] - 1 : 1); x >= 0; x--) { // 수정된 x 범위
            ll result = x * prefixM[i];
            if (v - result >= 0) {
                a[i+1] = x;
                v -= result;
                break;
            }
        }
    }

    a[0] = v;  // 0 또는 1
}

void printAnswer(int v) {
    string s = "";
    cout << v << " = ";

    bool first = true;
    for (int i = 0; i < a.size(); i++) {  // 수정된 반복 범위
        if (a[i]) {
            if (!first) cout << " + ";
            cout << a[i] << s;
            first = false;
        }
        s += '*' + to_string(p[i]);
    }
}

int main() {
    FASTIO;

    ll total = 1;
    for (int i = 0; i < p.size(); i++) {
        total *= p[i];
        prefixM.push_back(total);
    }

    a.resize(prefixM.size() + 1); // 크기 조정

    int v;
    while (true) {
        cin >> v;
        if (v == 0) return 0;

        fill(a.begin(), a.end(), 0); // 배열 초기화
        findA(v);
        printAnswer(v);
        cout << '\n';
    }
}