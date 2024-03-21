#include <bits/stdc++.h>
using namespace std;

int getSum(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        if ('0' <= s[i] && s[i] <= '9') sum += s[i] - '0';
    }

    return sum;
}

bool compare(const tuple <int, int, string>& a, const tuple <int, int, string>& b) {
    if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
    if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
    return get<2>(a) < get<2>(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    string serial;

    vector<tuple<int, int, string>> info;
    tuple<int, int, string> each;
    for (int i = 0; i < N; i++) {
        cin >> serial;

        get<0>(each) = serial.length();
        get<1>(each) = getSum(serial);
        get<2>(each) = serial;

        info.push_back(each);
    }

    stable_sort(info.begin(), info.end(), compare);

    for (auto s : info) cout << get<2>(s) << '\n';
}