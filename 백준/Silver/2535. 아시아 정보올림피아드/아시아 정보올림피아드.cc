#include <bits/stdc++.h>
using namespace std;

bool sorted(tuple<int, int, int>& a, tuple<int, int, int>& b) {
    return get<2>(a) > get<2>(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int world, num, score;
    vector<tuple<int, int, int>> info;
    for (int i = 0; i < N; i++) {
        cin >> world >> num >> score;
        tuple<int, int, int> x (world, num, score);
        info.push_back(x);
    }

    sort(info.begin(), info.end(), sorted);

    vector<int> country(101, 0);
    int k = 0, awards = 0;
    while (true) {
        int count = get<0>(info[k]);
        if (country[count] == 2) {
            k++;
            continue;
        }
        country[count]++;
        cout << get<0>(info[k]) << ' ' << get<1>(info[k]) << '\n';
        k++;
        awards++;

        if (awards == 3) break;
    } 
}