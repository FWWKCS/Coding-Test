#include <bits/stdc++.h>

using namespace std;

struct student {
    string name;
    int d, m, y;
    // 비교 연산자 정의
    bool operator<(const student &other) const {
        // 각 수를 모두 비교하여 우선순위 결정
        if (y != other.y) return y < other.y;
        if (m != other.m) return m < other.m;
        return d < other.d;
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<student> info(n);
    for (auto& i : info) { cin >> i.name >> i.d >> i.m >> i.y; }

    auto [min, max] = minmax_element(info.begin(), info.end());
    cout << max->name << '\n' << min->name ;
}