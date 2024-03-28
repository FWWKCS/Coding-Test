#include <bits/stdc++.h>
using namespace std;

bool custom(pair<string, int>& A, pair<string, int>& B) {
    return A.first < B.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M, N;
    cin >> M >> N;

    vector<pair<string, int>> seq;
    map<int, string> eng = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {0, "zero"},
    };

    for (int i = M; i <= N; i++) {
        if (i < 10) seq.push_back(make_pair(eng[i], i));
        else {
            string ten, one;
            ten = eng[i / 10];
            one = eng[i % 10];

            seq.push_back(make_pair(ten+one, i));
        }
    }

    sort(seq.begin(), seq.end(), custom);

    int count = 1;
    for (auto x : seq) {
        if (count > 10) {
            cout << '\n';
            count = 1;
        }
        cout << x.second << ' ';
        count++;
    }
}