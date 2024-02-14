#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ch, cm, cs, cur_total = 0;
    int sh, sm, ss, start_total;
    string current = "";
    string start = "";

    cin >> current >> start;

    ch = stoi(current.substr(0,2));
    cm = stoi(current.substr(3,2));
    cs = stoi(current.substr(6,2));

    sh = stoi(start.substr(0,2));
    sm = stoi(start.substr(3,2));
    ss = stoi(start.substr(6,2));

    cur_total = 3600 * ch + 60 * cm + cs;
    start_total = 3600 * sh + 60 * sm + ss;

    int left = start_total - cur_total;
    if (left < 0) left += 3600 * 24;

    int lh, lm, ls;
    string h, m, s;
    lh = left / 3600;
    if (lh < 10) h = '0' + to_string(lh);
    else h = to_string(lh);

    left %= 3600;

    lm = left / 60;
    if (lm < 10) m = '0' + to_string(lm);
    else m = to_string(lm);

    left %= 60;

    if (left < 10) s = '0' + to_string(left);
    else s = to_string(left);

    cout << h << ':' << m << ':' << s;
}