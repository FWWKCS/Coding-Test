#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int count = 1;
    while (true) {
        int t; cin >> t;
        if (t == 0) break;

        vector<int> data(t+1);;
        for (int i = 1; i <= t; i++) {
            cin >> data[i];
        }

        // sort(data.begin(), data.end());
        double median;

        if (t % 2 == 1) 
            median = data[(t+1)/2];
        else 
            median = (data[t/2] + data[(t/2)+1])/ 2.0;
        
        cout << fixed << setprecision(1) << "Case " << count << ": " << median << '\n';

        count++;

    }
}