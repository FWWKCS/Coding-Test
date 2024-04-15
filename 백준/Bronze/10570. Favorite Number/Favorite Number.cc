#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int V, S; cin >> V;
        map<int, int> most;
        for (int j = 0; j < V; j++) {
            cin >> S;
            if (most.find(S) != most.end()) most[S]++;
            else most.insert({S, 1});
        }

        int maxCount = 0, mostValue = 1e9;
        for (auto x : most) {
            if (x.second > maxCount) {
                mostValue = x.first;
                maxCount = x.second;
            }
            else if (x.second == maxCount) mostValue = min(mostValue, x.first);
        } 
        cout << mostValue << '\n';
    }
}