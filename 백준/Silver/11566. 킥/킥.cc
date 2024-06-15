#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int x;
    vector<int> t;
    for (int i = 0; i < n; i++) {
        cin >> x;
        t.push_back(x);
    }

    int m; cin >> m;
    vector<int> l;
    for (int i = 0; i < m; i++) {
        cin >> x;
        l.push_back(x);
    }

    int min = -1;
    int max = -1;

    int d = 0;
    while (n + (n-1)*d <= m) {
        for (int k = 0; k <= m - (n + (n-1)*d); k++) {
            bool found = true;
            int idx = 0;
            for (int p = k; idx < n; p+=d+1) {
                // cout << l[p] << ' ' << t[idx] << '\n';
                if (l[p] != t[idx]) {
                    found = false;
                    break;
                }
                idx++;
            }


            if (found) {
                if (min == -1) min = d;
                else if (min > -1) max = d;
                break;
            }
        }

        d++;
    }   

    if (min > -1 && max == -1) { 
        max = min;
        cout << min << ' ' << max;
    }
    else if (min == -1 && max == -1) cout << -1;
    else cout << min << ' ' << max;
}